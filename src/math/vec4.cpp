//////////////////////////////////////////////////////////////////////////////////////////
//	math::vec4.cpp
//	Function definitions for 4d vector class
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Modified:	15th August 2002	-	prevent divide by zero in operator vec3()
//	Modified:	8th November 2002	-	Changed Constructor layout
//									-	Some speed Improvements
//									-	Corrected Lerp
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	
#include <stdio.h>
#include <math/vec3.h>
#include <math/vec4.h>
#include <math/mat44.h>

math::vec4::vec4(const vec3 & rhs):
	x(rhs.v[0]), y(rhs.v[1]), z(rhs.v[2]), w(1.0f)
{}
math::vec4::vec4(const vec3 & rhs,double const & newW):
	x(rhs.v[0]), y(rhs.v[1]), z(rhs.v[2]), w(newW)
{}

bool math::vec4::isNan() const {
	if(isnan(x)) return true;
	if(isnan(y)) return true;
	if(isnan(z)) return true;
	if(isnan(w)) return true;
	return false;
}
bool	math::vec4::isFinite() const {
	if(isinf(w)) return false;
	if(isinf(x)) return false;
	if(isinf(y)) return false;
	if(isinf(z)) return false;
	return true;
}
void math::vec4::RotateX(double angle)
{
	(*this)=GetRotatedX(angle);
}

math::vec4 math::vec4::GetRotatedX(double angle) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateX(angle);

	return math::vec4(v3d, w);
}

void math::vec4::RotateY(double angle)
{
	(*this)=GetRotatedY(angle);
}

math::vec4 math::vec4::GetRotatedY(double angle) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateY(angle);

	return math::vec4(v3d, w);
}

void math::vec4::RotateZ(double angle)
{
	(*this)=GetRotatedZ(angle);
}

math::vec4 math::vec4::GetRotatedZ(double angle) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateZ(angle);

	return math::vec4(v3d, w);
}

void math::vec4::RotateAxis(double angle, const math::vec3 & axis)
{
	(*this)=GetRotatedAxis(angle, axis);
}

math::vec4 math::vec4::GetRotatedAxis(double angle, const math::vec3 & axis) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateAxis(angle, axis);

	return math::vec4(v3d, w);
}


math::vec4 operator*(double scaleFactor, const math::vec4 & rhs)
{
	return rhs*scaleFactor;
}

bool math::vec4::operator==(const math::vec4 & rhs) const
{
	if(x==rhs.x && y==rhs.y && z==rhs.z && w==rhs.w)
		return true;

	return false;
}
math::vec4::operator math::vec3()
{
	if(w==0.0f || w==1.0f)
		return math::vec3(x, y, z);
	else
		return math::vec3(x/w, y/w, z/w);
}
math::mat44 math::vec4::operator*(math::vec4 const & rhs)
{
	math::mat44 ret(
			x*rhs.x, y*rhs.x, z*rhs.x, w*rhs.x,
			x*rhs.y, y*rhs.y, z*rhs.y, w*rhs.y,
			x*rhs.z, y*rhs.z, z*rhs.z, w*rhs.z,
			x*rhs.w, y*rhs.w, z*rhs.w, w*rhs.w);

	return ret;
}
void	math::vec4::print()
{
	printf("%f %f %f %f\n",x,y,z,w);
}




