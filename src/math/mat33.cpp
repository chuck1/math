//////////////////////////////////////////////////////////////////////////////////////////
//	math::mat44.cpp
//	function definitions for 4x4 matrix class
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Updated:	19th August 2002	-	Corrected 2nd SetPerspective for n!=1.0f
//				26th September 2002	-	Added nudge to prevent artifacts with infinite far plane
//									-	Improved speed
//				7th November 2002	-	Added Affine Inverse functions
//									-	Changed constructors
//									-	Added special cases for row3 = (0, 0, 0, 1)
//				17th December 2002	-	Converted from radians to degrees for consistency
//										with OpenGL. Should have been done a long time ago...
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include <math/vec3.h>
#include <math/vec4.h>
#include <math/transform.h>
#include <math/mat33.h>
#include <math/quat.h>
#include <math/plane.h>

math::mat33::mat33()
{
	LoadIdentity();
}
math::mat33::mat33(
		float e0, float e1, float e2,
		float e3, float e4, float e5,
		float e6, float e7, float e8)
{
	v[0]=e0;
	v[1]=e1;
	v[2]=e2;
	v[3]=e3;
	v[4]=e4;
	v[5]=e5;
	v[6]=e6;
	v[7]=e7;
	v[8]=e8;
}
math::mat33::mat33(const math::mat33 & rhs)
{
	memcpy(v, rhs.v, 9*sizeof(float));
}
math::mat33::mat33(const float * rhs)
{
	memcpy(v, rhs, 9*sizeof(float));
}
math::mat33::mat33(vec3 const & rhs) {
	LoadIdentity();
	v[0] = rhs.x;
	v[4] = rhs.y;
	v[8] = rhs.z;
}
void		math::mat33::set_rotation(math::quat const & q)
{
	const float x = q.x;
	const float y = q.y;
	const float z = q.z;
	const float w = q.w;

	const float x2 = x + x;
	const float y2 = y + y;
	const float z2 = z + z;

	const float xx = x2*x;
	const float yy = y2*y;
	const float zz = z2*z;

	const float xy = x2*y;
	const float xz = x2*z;
	const float xw = x2*w;

	const float yz = y2*z;
	const float yw = y2*w;
	const float zw = z2*w;

	v[0] = 1.0f - yy - zz;
	v[1] = xy + zw;
	v[2] = xz - yw;

	v[3] = xy - zw;
	v[4] = 1.0f - xx - zz;
	v[5] = yz + xw;

	v[6] = xz + yw;
	v[7] = yz - xw;
	v[8] = 1.0f - xx - yy;
}
void math::mat33::SetEntry(int position, float value)
{
	if(position>=0 && position<=15)
		v[position]=value;
}
float		math::mat33::GetEntry(int position) const
{
	if(position>=0 && position<=15)
		return v[position];

	return 0.0f;
}
math::vec4	math::mat33::GetRow(int position) const
{
	if(position==0)
		return vec4(v[0], v[4], v[8], v[12]);

	if(position==1)
		return vec4(v[1], v[5], v[9], v[13]);

	if(position==2)
		return vec4(v[2], v[6], v[10], v[14]);

	if(position==3)
		return vec4(v[3], v[7], v[11], v[15]);

	return vec4(0.0f, 0.0f, 0.0f, 0.0f);
}
math::vec4 math::mat33::GetColumn(int position) const
{
	if(position==0)
		return vec4(v[0], v[1], v[2], v[3]);

	if(position==1)
		return vec4(v[4], v[5], v[6], v[7]);

	if(position==2)
		return vec4(v[8], v[9], v[10], v[11]);

	if(position==3)
		return vec4(v[12], v[13], v[14], v[15]);

	return vec4(0.0f, 0.0f, 0.0f, 0.0f);
}
void math::mat33::LoadIdentity(void)
{
	memset(v, 0, 9*sizeof(float));
	v[0]=1.0f;
	v[4]=1.0f;
	v[8]=1.0f;
}
void math::mat33::LoadZero(void)
{
	memset(v, 0, 16*sizeof(float));
}
math::mat33 math::mat33::operator+(const math::mat33 & rhs) const {
	math::mat33 m;
	for(int i = 0; i < 9; ++i) m.v[i] = v[i] + rhs.v[i];
	return m;
}
math::mat33 math::mat33::operator-(const math::mat33 & rhs) const {
	math::mat33 m;
	for(int i = 0; i < 9; ++i) m.v[i] = v[i] - rhs.v[i];
	return m;
}
math::mat33 math::mat33::operator*(const math::mat33 & rhs) const {

	return math::mat33(
			v[0]*rhs.v[0] + v[3] * rhs.v[1] + v[6] * rhs.v[2],
			v[1]*rhs.v[0] + v[4] * rhs.v[1] + v[7] * rhs.v[2],
			v[2]*rhs.v[0] + v[5] * rhs.v[1] + v[8] * rhs.v[2],
			v[0]*rhs.v[3] + v[3] * rhs.v[4] + v[6] * rhs.v[5],
			v[1]*rhs.v[3] + v[4] * rhs.v[4] + v[7] * rhs.v[5],
			v[2]*rhs.v[3] + v[5] * rhs.v[4] + v[8] * rhs.v[5],
			v[0]*rhs.v[6] + v[3] * rhs.v[7] + v[6] * rhs.v[8],
			v[1]*rhs.v[6] + v[4] * rhs.v[7] + v[7] * rhs.v[8],
			v[2]*rhs.v[6] + v[5] * rhs.v[7] + v[8] * rhs.v[8]);
}
math::mat33 math::mat33::operator*(const float rhs) const
{
	math::mat33 m;
	for(int i = 0; i < 9; ++i) m.v[i] = v[i]*rhs;

	return math::mat33(
			v[0]*rhs,
			v[1]*rhs,
			v[2]*rhs,
			v[3]*rhs,
			v[4]*rhs,
			v[5]*rhs,
			v[6]*rhs,
			v[7]*rhs,
			v[8]*rhs);
}
math::mat33 math::mat33::operator/(const float rhs) const
{
	if (rhs==0.0f || rhs==1.0f)
		return (*this);

	float temp=1/rhs;

	return (*this)*temp;
}
math::mat33 operator*(float scaleFactor, const math::mat33 & rhs)
{
	return rhs*scaleFactor;
}
bool math::mat33::operator==(const math::mat33 & rhs) const
{
	for(int i=0; i<16; i++)
	{
		if(v[i]!=rhs.v[i])
			return false;
	}
	return true;
}
bool math::mat33::operator!=(const math::mat33 & rhs) const
{
	return !((*this)==rhs);
}
void math::mat33::operator+=(const math::mat33 & rhs)
{
	(*this)=(*this)+rhs;
}
void math::mat33::operator-=(const math::mat33 & rhs)
{
	for(int i = 0; i < 9; ++i) v[i] *= rhs.v[i];
}
void math::mat33::operator*=(const math::mat33 & rhs) {
	(*this) = (*this) * rhs;
}
void math::mat33::operator*=(const float rhs) {
	for(int i = 0; i < 9; ++i) v[i] *= rhs;
}
void math::mat33::operator/=(const float rhs)
{
	(*this)=(*this)/rhs;
}
math::mat33 math::mat33::operator-(void) const
{
	math::mat33 result(*this);

	for(int i=0; i<16; i++)
		result.v[i]=-result.v[i];

	return result;
}
math::vec3 math::mat33::operator*(const vec3 rhs) const
{
	return vec3(
			v[0]*rhs.x + v[3]*rhs.y + v[6] * rhs.z,
			v[1]*rhs.x + v[4]*rhs.y	+ v[7] * rhs.z,
			v[2]*rhs.x + v[5]*rhs.y + v[8] * rhs.z);

}
math::vec3	math::mat33::GetRotatedVector3D(const vec3 & rhs) const
{
	return vec3(
			v[0]*rhs.x + v[4]*rhs.y + v[8]*rhs.z,
			v[1]*rhs.x + v[5]*rhs.y + v[9]*rhs.z,
			v[2]*rhs.x + v[6]*rhs.y + v[10]*rhs.z);
}
math::vec3	math::mat33::GetInverseRotatedVector3D(const vec3 & rhs) const
{
	//rotate by transpose:
	return vec3(v[0]*rhs.x + v[1]*rhs.y + v[2]*rhs.z,
			v[4]*rhs.x + v[5]*rhs.y + v[6]*rhs.z,
			v[8]*rhs.x + v[9]*rhs.y + v[10]*rhs.z);
}
void		math::mat33::Invert(void)
{
	*this=GetInverse();
}
math::mat33	math::mat33::GetInverse(void) const
{
	math::mat33 result=GetInverseTranspose();

	result.Transpose();

	return result;
}
void		math::mat33::Transpose(void)
{
	*this=GetTranspose();
}
math::mat33	math::mat33::GetTranspose(void) const
{
	return math::mat33(
			v[ 0], v[ 3], v[6],
			v[ 1], v[ 4], v[7],
			v[ 2], v[ 5], v[8]);
}
void		math::mat33::InvertTranspose(void)
{
	*this=GetInverseTranspose();
}
math::mat33	math::mat33::GetInverseTranspose(void) const
{
	math::mat33 result;

	float tmp[12];												//temporary pair storage
	float det;													//determinant

	//calculate pairs for first 8 elements (cofactors)
	tmp[0] = v[10] * v[15];
	tmp[1] = v[11] * v[14];
	tmp[2] = v[9] * v[15];
	tmp[3] = v[11] * v[13];
	tmp[4] = v[9] * v[14];
	tmp[5] = v[10] * v[13];
	tmp[6] = v[8] * v[15];
	tmp[7] = v[11] * v[12];
	tmp[8] = v[8] * v[14];
	tmp[9] = v[10] * v[12];
	tmp[10] = v[8] * v[13];
	tmp[11] = v[9] * v[12];

	//calculate first 8 elements (cofactors)
	result.SetEntry(0,		tmp[0]*v[5] + tmp[3]*v[6] + tmp[4]*v[7]
			-	tmp[1]*v[5] - tmp[2]*v[6] - tmp[5]*v[7]);

	result.SetEntry(1,		tmp[1]*v[4] + tmp[6]*v[6] + tmp[9]*v[7]
			-	tmp[0]*v[4] - tmp[7]*v[6] - tmp[8]*v[7]);

	result.SetEntry(2,		tmp[2]*v[4] + tmp[7]*v[5] + tmp[10]*v[7]
			-	tmp[3]*v[4] - tmp[6]*v[5] - tmp[11]*v[7]);

	result.SetEntry(3,		tmp[5]*v[4] + tmp[8]*v[5] + tmp[11]*v[6]
			-	tmp[4]*v[4] - tmp[9]*v[5] - tmp[10]*v[6]);

	result.SetEntry(4,		tmp[1]*v[1] + tmp[2]*v[2] + tmp[5]*v[3]
			-	tmp[0]*v[1] - tmp[3]*v[2] - tmp[4]*v[3]);

	result.SetEntry(5,		tmp[0]*v[0] + tmp[7]*v[2] + tmp[8]*v[3]
			-	tmp[1]*v[0] - tmp[6]*v[2] - tmp[9]*v[3]);

	result.SetEntry(6,		tmp[3]*v[0] + tmp[6]*v[1] + tmp[11]*v[3]
			-	tmp[2]*v[0] - tmp[7]*v[1] - tmp[10]*v[3]);

	result.SetEntry(7,		tmp[4]*v[0] + tmp[9]*v[1] + tmp[10]*v[2]
			-	tmp[5]*v[0] - tmp[8]*v[1] - tmp[11]*v[2]);

	//calculate pairs for second 8 elements (cofactors)
	tmp[0] = v[2]*v[7];
	tmp[1] = v[3]*v[6];
	tmp[2] = v[1]*v[7];
	tmp[3] = v[3]*v[5];
	tmp[4] = v[1]*v[6];
	tmp[5] = v[2]*v[5];
	tmp[6] = v[0]*v[7];
	tmp[7] = v[3]*v[4];
	tmp[8] = v[0]*v[6];
	tmp[9] = v[2]*v[4];
	tmp[10] = v[0]*v[5];
	tmp[11] = v[1]*v[4];

	//calculate second 8 elements (cofactors)
	result.SetEntry(8,		tmp[0]*v[13] + tmp[3]*v[14] + tmp[4]*v[15]
			-	tmp[1]*v[13] - tmp[2]*v[14] - tmp[5]*v[15]);

	result.SetEntry(9,		tmp[1]*v[12] + tmp[6]*v[14] + tmp[9]*v[15]
			-	tmp[0]*v[12] - tmp[7]*v[14] - tmp[8]*v[15]);

	result.SetEntry(10,		tmp[2]*v[12] + tmp[7]*v[13] + tmp[10]*v[15]
			-	tmp[3]*v[12] - tmp[6]*v[13] - tmp[11]*v[15]);

	result.SetEntry(11,		tmp[5]*v[12] + tmp[8]*v[13] + tmp[11]*v[14]
			-	tmp[4]*v[12] - tmp[9]*v[13] - tmp[10]*v[14]);

	result.SetEntry(12,		tmp[2]*v[10] + tmp[5]*v[11] + tmp[1]*v[9]
			-	tmp[4]*v[11] - tmp[0]*v[9] - tmp[3]*v[10]);

	result.SetEntry(13,		tmp[8]*v[11] + tmp[0]*v[8] + tmp[7]*v[10]
			-	tmp[6]*v[10] - tmp[9]*v[11] - tmp[1]*v[8]);

	result.SetEntry(14,		tmp[6]*v[9] + tmp[11]*v[11] + tmp[3]*v[8]
			-	tmp[10]*v[11] - tmp[2]*v[8] - tmp[7]*v[9]);

	result.SetEntry(15,		tmp[10]*v[10] + tmp[4]*v[8] + tmp[9]*v[9]
			-	tmp[8]*v[9] - tmp[11]*v[10] - tmp[5]*v[8]);

	// calculate determinant
	det	=	 v[0]*result.GetEntry(0)
		+v[1]*result.GetEntry(1)
		+v[2]*result.GetEntry(2)
		+v[3]*result.GetEntry(3);

	if(det==0.0f)
	{
		math::mat33 id;
		return id;
	}

	result=result/det;

	return result;
}
void		math::mat33::SetTranslation(const vec3 & translation)
{
	LoadIdentity();

	SetTranslationPart(translation);
}
void		math::mat33::SetScale(const vec3 & scaleFactor)
{
	LoadIdentity();

	v[0]=scaleFactor.x;
	v[5]=scaleFactor.y;
	v[10]=scaleFactor.z;
}
void		math::mat33::SetUniformScale(const float scaleFactor)
{
	LoadIdentity();

	v[0]=v[5]=v[10]=scaleFactor;
}
void		math::mat33::SetRotationAxis(const double angle, const vec3 & axis)
{
	vec3 u=axis.GetNormalized();

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);
	float oneMinusCosAngle=1.0f-cosAngle;

	LoadIdentity();

	v[0]=(u.x)*(u.x) + cosAngle*(1-(u.x)*(u.x));
	v[4]=(u.x)*(u.y)*(oneMinusCosAngle) - sinAngle*u.z;
	v[8]=(u.x)*(u.z)*(oneMinusCosAngle) + sinAngle*u.y;

	v[1]=(u.x)*(u.y)*(oneMinusCosAngle) + sinAngle*u.z;
	v[5]=(u.y)*(u.y) + cosAngle*(1-(u.y)*(u.y));
	v[9]=(u.y)*(u.z)*(oneMinusCosAngle) - sinAngle*u.x;

	v[2]=(u.x)*(u.z)*(oneMinusCosAngle) - sinAngle*u.y;
	v[6]=(u.y)*(u.z)*(oneMinusCosAngle) + sinAngle*u.x;
	v[10]=(u.z)*(u.z) + cosAngle*(1-(u.z)*(u.z));
}
void		math::mat33::SetRotationX(const double angle)
{
	LoadIdentity();

	v[5]=(float)cos(M_PI*angle/180);
	v[6]=(float)sin(M_PI*angle/180);

	v[9]=-v[6];
	v[10]=v[5];
}
void		math::mat33::SetRotationY(const double angle)
{
	LoadIdentity();

	v[0]=(float)cos(M_PI*angle/180);
	v[2]=-(float)sin(M_PI*angle/180);

	v[8]=-v[2];
	v[10]=v[0];
}
void		math::mat33::SetRotationZ(const double angle)
{
	LoadIdentity();

	v[0]=(float)cos(M_PI*angle/180);
	v[1]=(float)sin(M_PI*angle/180);

	v[4]=-v[1];
	v[5]=v[0];
}
void		math::mat33::SetRotationEuler(const double angleX, const double angleY, const double angleZ)
{
	LoadIdentity();

	SetRotationPartEuler(angleX, angleY, angleZ);
}
void		math::mat33::SetPerspective(float left, float right, float bottom, float top, float n, float f)
{
	float nudge=0.999f;		//prevent artifacts with infinite far plane

	LoadZero();

	//check for division by 0
	if(left==right || top==bottom || n==f)
	{
		printf("invalid perspective");
		exit(0);
	}
	v[0]=(2*n)/(right-left);

	v[5]=(2*n)/(top-bottom);

	v[8]=(right+left)/(right-left);
	v[9]=(top+bottom)/(top-bottom);

	if(f!=-1)
	{
		v[10]=-(f+n)/(f-n);
	}
	else		//if f==-1, use an infinite far plane
	{
		v[10]=-nudge;
	}

	v[11]=-1;

	if(f!=-1)
	{
		v[14]=-(2*f*n)/(f-n);
	}
	else		//if f==-1, use an infinite far plane
	{
		v[14]=-2*n*nudge;
	}
}
void		math::mat33::SetPerspective(float fovy, float aspect, float n, float f)
{
	float left, right, top, bottom;

	//convert fov from degrees to radians
	fovy *= (float)M_PI / 180.0f;

	top = n*tanf(fovy/2.0f);
	bottom=-top;

	left=aspect*bottom;
	right=aspect*top;

	SetPerspective(left, right, bottom, top, n, f);
}
void		math::mat33::SetOrtho(	float left, float right, float bottom, float top, float n, float f)
{
	LoadIdentity();

	v[0]=2.0f/(right-left);

	v[5]=2.0f/(top-bottom);

	v[10]=-2.0f/(f-n);

	v[12]=-(right+left)/(right-left);
	v[13]=-(top+bottom)/(top-bottom);
	v[14]=-(f+n)/(f-n);
}
void		math::mat33::SetTranslationPart(const vec3 & translation)
{
	v[12]=translation.x;
	v[13]=translation.y;
	v[14]=translation.z;
}
void		math::mat33::SetRotationPartEuler(const double angleX, const double angleY, const double angleZ)
{
	double cr = cos( M_PI*angleX/180 );
	double sr = sin( M_PI*angleX/180 );
	double cp = cos( M_PI*angleY/180 );
	double sp = sin( M_PI*angleY/180 );
	double cy = cos( M_PI*angleZ/180 );
	double sy = sin( M_PI*angleZ/180 );

	v[0] = ( float )( cp*cy );
	v[1] = ( float )( cp*sy );
	v[2] = ( float )( -sp );

	double srsp = sr*sp;
	double crsp = cr*sp;

	v[4] = ( float )( srsp*cy-cr*sy );
	v[5] = ( float )( srsp*sy+cr*cy );
	v[6] = ( float )( sr*cp );

	v[8] = ( float )( crsp*cy+sr*sy );
	v[9] = ( float )( crsp*sy-sr*cy );
	v[10] = ( float )( cr*cp );
}
void		math::mat33::RotateVector3D(math::vec3 & rhs) const {
	rhs=GetRotatedVector3D(rhs);
}
void		math::mat33::InverseRotateVector3D(math::vec3 & rhs) const
{
	rhs=GetInverseRotatedVector3D(rhs);
}
void		math::mat33::SetRotationPartEuler(const math::vec3 & rotations)
{
	SetRotationPartEuler((double)rotations.x, (double)rotations.y, (double)rotations.z);
}
void	math::mat33::print()
{
	for(int i = 0; i < 3; ++i )
	{
		for(int j = 0; j < 3; ++j )
		{
			printf("%f ",v[3*i+j]);
		}
		printf("\n");
	}
}



