//////////////////////////////////////////////////////////////////////////////////////////
//	vec3.cpp
//	Function definitions for 3d vector class
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Modified:	8th November 2002	-	Changed Constructor layout
//									-	Some speed Improvements
//									-	Corrected Lerp
//				17th December 2002	-	Converted from radians to degrees
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#include <stdio.h>
#include <stdlib.h>

#include <math/vec3.h>

void math::vec3::normalize()
{
	float length=magnitude();

	if(length==1.0f) return;

	if(length==0.0f)
	{
		printf("normalize zero vector");
		exit(0);
	}

	float scalefactor = 1.0f/length;
	x *= scalefactor;
	y *= scalefactor;
	z *= scalefactor;
}

math::vec3 math::vec3::GetNormalized() const
{
	vec3 result(*this);

	result.normalize();

	return result;
}

math::vec3 math::vec3::GetRotatedX(double angle) const
{
	if(angle==0.0)
		return (*this);

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);

	return vec3(	x,
			y*cosAngle - z*sinAngle,
			y*sinAngle + z*cosAngle);
}

void math::vec3::RotateX(double angle)
{
	(*this)=GetRotatedX(angle);
}

math::vec3 math::vec3::GetRotatedY(double angle) const
{
	if(angle==0.0)
		return (*this);

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);

	return math::vec3(	x*cosAngle + z*sinAngle,
			y,
			-x*sinAngle + z*cosAngle);
}

void math::vec3::RotateY(double angle)
{
	(*this)=GetRotatedY(angle);
}

math::vec3 math::vec3::GetRotatedZ(double angle) const
{
	if(angle==0.0)
		return (*this);

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);

	return math::vec3(x*cosAngle - y*sinAngle,
			x*sinAngle + y*cosAngle,
			z);
}

void math::vec3::RotateZ(double angle)
{
	(*this)=GetRotatedZ(angle);
}

math::vec3 math::vec3::GetRotatedAxis(double angle, const math::vec3 & axis) const
{
	if(angle==0.0)
		return (*this);

	math::vec3 u=axis.GetNormalized();

	math::vec3 rotMatrixRow0, rotMatrixRow1, rotMatrixRow2;

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);
	float oneMinusCosAngle=1.0f-cosAngle;

	rotMatrixRow0.x=(u.x)*(u.x) + cosAngle*(1-(u.x)*(u.x));
	rotMatrixRow0.y=(u.x)*(u.y)*(oneMinusCosAngle) - sinAngle*u.z;
	rotMatrixRow0.z=(u.x)*(u.z)*(oneMinusCosAngle) + sinAngle*u.y;

	rotMatrixRow1.x=(u.x)*(u.y)*(oneMinusCosAngle) + sinAngle*u.z;
	rotMatrixRow1.y=(u.y)*(u.y) + cosAngle*(1-(u.y)*(u.y));
	rotMatrixRow1.z=(u.y)*(u.z)*(oneMinusCosAngle) - sinAngle*u.x;

	rotMatrixRow2.x=(u.x)*(u.z)*(oneMinusCosAngle) - sinAngle*u.y;
	rotMatrixRow2.y=(u.y)*(u.z)*(oneMinusCosAngle) + sinAngle*u.x;
	rotMatrixRow2.z=(u.z)*(u.z) + cosAngle*(1-(u.z)*(u.z));

	return math::vec3( dot(rotMatrixRow0), dot(rotMatrixRow1), dot(rotMatrixRow2));
}
float		math::vec3::angle(vec3 const & rhs) const
{
	math::vec3 v = cross(rhs);
	
	return acos( v.magnitude() / magnitude() / rhs.magnitude() );
}
void		math::vec3::RotateAxis(double angle, const math::vec3 & axis)
{
	(*this)=GetRotatedAxis(angle, axis);
}
void		math::vec3::PackTo01()
{
	(*this)=GetPackedTo01();	
}
void		math::vec3::Add(const vec3 & v2, vec3 & result)
{
	result.x=x+v2.x;
	result.y=y+v2.y;
	result.z=z+v2.z;
}
void		math::vec3::Subtract(const vec3 & v2, vec3 & result)
{
	result.x=x-v2.x;
	result.y=y-v2.y;
	result.z=z-v2.z;
}
math::vec3	math::vec3::GetPackedTo01() const
{
	math::vec3 temp(*this);

	temp.normalize();

	temp = temp * 0.5f + math::vec3(0.5f, 0.5f, 0.5f);

	return temp;
}

math::vec3 operator*(float scaleFactor, const math::vec3 & rhs)
{
	return rhs*scaleFactor;
}

bool		math::vec3::operator==(const math::vec3 & rhs) const
{
	if(x==rhs.x && y==rhs.y && z==rhs.z)
		return true;

	return false;
}
bool		math::vec3::operator!=(const vec3 & rhs) const
{
	return !((*this)==rhs);
}
//self-add etc
void		math::vec3::operator+=(const vec3 & rhs)
{
	x+=rhs.x;	y+=rhs.y;	z+=rhs.z;
}
void		math::vec3::operator-=(const vec3 & rhs)
{
	x-=rhs.x;	y-=rhs.y;	z-=rhs.z;
}
void		math::vec3::operator*=(const float rhs)
{
	x*=rhs;	y*=rhs;	z*=rhs;
}
	void		math::vec3::operator/=(const float rhs)
{	if(rhs==0.0f)
	return;
	else
	{	x/=rhs; y/=rhs; z/=rhs;	}
}

void	math::vec3::print()
{
	printf("%f %f %f\n",x,y,z);
}

