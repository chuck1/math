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
		double e0, double e1, double e2,
		double e3, double e4, double e5,
		double e6, double e7, double e8)
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
	memcpy(v, rhs.v, 9*sizeof(double));
}
math::mat33::mat33(const double * rhs)
{
	memcpy(v, rhs, 9*sizeof(double));
}
math::mat33::mat33(vec3 const & rhs) {
	LoadIdentity();
	v[0] = rhs.v[0];
	v[4] = rhs.v[1];
	v[8] = rhs.v[2];
}
void math::mat33::SetDiagonal(double x, double y, double z) {
	LoadZero();
	v[0] = x;
	v[4] = y;
	v[8] = z;
}
void math::mat33::setRotation(math::quat const & q)
{
	const double x = q.x;
	const double y = q.y;
	const double z = q.z;
	const double w = q.w;

	const double x2 = x + x;
	const double y2 = y + y;
	const double z2 = z + z;

	const double xx = x2*x;
	const double yy = y2*y;
	const double zz = z2*z;

	const double xy = x2*y;
	const double xz = x2*z;
	const double xw = x2*w;

	const double yz = y2*z;
	const double yw = y2*w;
	const double zw = z2*w;

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
void math::mat33::SetEntry(int position, double value)
{
	if(position>=0 && position<=15)
		v[position]=value;
}
double		math::mat33::GetEntry(int position) const
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
	memset(v, 0, 9*sizeof(double));
	v[0]=1.0f;
	v[4]=1.0f;
	v[8]=1.0f;
}
void math::mat33::LoadZero(void)
{
	memset(v, 0, 9*sizeof(double));
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
math::mat33 math::mat33::operator*(const double rhs) const
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
math::mat33 math::mat33::operator/(const double rhs) const
{
	if (rhs==0.0f || rhs==1.0f)
		return (*this);

	double temp=1/rhs;

	return (*this)*temp;
}
math::mat33 operator*(double scaleFactor, const math::mat33 & rhs)
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
void math::mat33::operator*=(const double rhs) {
	for(int i = 0; i < 9; ++i) v[i] *= rhs;
}
void math::mat33::operator/=(const double rhs)
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
			v[0]*rhs.v[0] + v[3]*rhs.v[1] + v[6] * rhs.v[2],
			v[1]*rhs.v[0] + v[4]*rhs.v[1] + v[7] * rhs.v[2],
			v[2]*rhs.v[0] + v[5]*rhs.v[1] + v[8] * rhs.v[2]);

}
math::vec3	math::mat33::GetRotatedVector3D(const vec3 & rhs) const
{
	return vec3(
			v[0]*rhs.v[0] + v[4]*rhs.v[1] + v[8]*rhs.v[2],
			v[1]*rhs.v[0] + v[5]*rhs.v[1] + v[9]*rhs.v[2],
			v[2]*rhs.v[0] + v[6]*rhs.v[1] + v[10]*rhs.v[2]);
}
math::vec3	math::mat33::GetInverseRotatedVector3D(const vec3 & rhs) const
{
	//rotate .v[1] transpose:
	return vec3(v[0]*rhs.v[0] + v[1]*rhs.v[1] + v[2]*rhs.v[2],
			v[4]*rhs.v[0] + v[5]*rhs.v[1] + v[6]*rhs.v[2],
			v[8]*rhs.v[0] + v[9]*rhs.v[1] + v[10]*rhs.v[2]);
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

	double tmp[12];												//temporary pair storage
	double det;													//determinant

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
void		math::mat33::SetScale(const vec3 & scaleFactor)
{
	LoadIdentity();

	v[0]  = scaleFactor.v[0];
	v[5]  = scaleFactor.v[1];
	v[10] = scaleFactor.v[2];
}
void		math::mat33::SetUniformScale(const double scaleFactor)
{
	LoadIdentity();

	v[0]=v[5]=v[10]=scaleFactor;
}
void		math::mat33::SetRotationAxis(const double angle, const vec3 & axis)
{
	vec3 u=axis.GetNormalized();

	double sinAngle=(double)sin(M_PI*angle/180);
	double cosAngle=(double)cos(M_PI*angle/180);
	double oneMinusCosAngle=1.0f-cosAngle;

	LoadIdentity();

	v[0]  = (u.v[0])*(u.v[0]) + cosAngle*(1-(u.v[0])*(u.v[0]));
	v[4]  = (u.v[0])*(u.v[1])*(oneMinusCosAngle) - sinAngle*u.v[2];
	v[8]  = (u.v[0])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[1];

	v[1]  = (u.v[0])*(u.v[1])*(oneMinusCosAngle) + sinAngle*u.v[2];
	v[5]  = (u.v[1])*(u.v[1]) + cosAngle*(1-(u.v[1])*(u.v[1]));
	v[9]  = (u.v[1])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[0];

	v[2]  = (u.v[0])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[1];
	v[6]  = (u.v[1])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[0];
	v[10] = (u.v[2])*(u.v[2]) + cosAngle*(1-(u.v[2])*(u.v[2]));
}
void		math::mat33::SetRotationX(const double angle)
{
	LoadIdentity();

	v[5]=(double)cos(M_PI*angle/180);
	v[6]=(double)sin(M_PI*angle/180);

	v[9]=-v[6];
	v[10]=v[5];
}
void		math::mat33::SetRotationY(const double angle)
{
	LoadIdentity();

	v[0]=(double)cos(M_PI*angle/180);
	v[2]=-(double)sin(M_PI*angle/180);

	v[8]=-v[2];
	v[10]=v[0];
}
void		math::mat33::SetRotationZ(const double angle)
{
	LoadIdentity();

	v[0]=(double)cos(M_PI*angle/180);
	v[1]=(double)sin(M_PI*angle/180);

	v[4]=-v[1];
	v[5]=v[0];
}
void		math::mat33::SetRotationEuler(const double angleX, const double angleY, const double angleZ)
{
	double cr = cos( M_PI*angleX/180 );
	double sr = sin( M_PI*angleX/180 );
	double cp = cos( M_PI*angleY/180 );
	double sp = sin( M_PI*angleY/180 );
	double cy = cos( M_PI*angleZ/180 );
	double sy = sin( M_PI*angleZ/180 );

	v[0] = ( double )( cp*cy );
	v[1] = ( double )( cp*sy );
	v[2] = ( double )( -sp );

	double srsp = sr*sp;
	double crsp = cr*sp;

	v[4] = ( double )( srsp*cy-cr*sy );
	v[5] = ( double )( srsp*sy+cr*cy );
	v[6] = ( double )( sr*cp );

	v[8] = ( double )( crsp*cy+sr*sy );
	v[9] = ( double )( crsp*sy-sr*cy );
	v[10] = ( double )( cr*cp );
}
void		math::mat33::RotateVector3D(math::vec3 & rhs) const {
	rhs = GetRotatedVector3D(rhs);
}
void		math::mat33::InverseRotateVector3D(math::vec3 & rhs) const
{
	rhs=GetInverseRotatedVector3D(rhs);
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



