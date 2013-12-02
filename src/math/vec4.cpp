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
	x(rhs.x), y(rhs.y), z(rhs.z), w(1.0f)
{}
math::vec4::vec4(const vec3 & rhs,float const & newW):
	x(rhs.x), y(rhs.y), z(rhs.z), w(newW)
{}

void math::vec4::RotateX(double angle)
{
	(*this)=GetRotatedX(angle);
}

math::vec4 math::vec4::GetRotatedX(double angle) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateX(angle);

	return math::vec4(v3d.x, v3d.y, v3d.z, w);
}

void math::vec4::RotateY(double angle)
{
	(*this)=GetRotatedY(angle);
}

math::vec4 math::vec4::GetRotatedY(double angle) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateY(angle);

	return math::vec4(v3d.x, v3d.y, v3d.z, w);
}

void math::vec4::RotateZ(double angle)
{
	(*this)=GetRotatedZ(angle);
}

math::vec4 math::vec4::GetRotatedZ(double angle) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateZ(angle);

	return math::vec4(v3d.x, v3d.y, v3d.z, w);
}

void math::vec4::RotateAxis(double angle, const math::vec3 & axis)
{
	(*this)=GetRotatedAxis(angle, axis);
}

math::vec4 math::vec4::GetRotatedAxis(double angle, const math::vec3 & axis) const
{
	math::vec3 v3d(x, y, z);

	v3d.RotateAxis(angle, axis);

	return math::vec4(v3d.x, v3d.y, v3d.z, w);
}


math::vec4 operator*(float scaleFactor, const math::vec4 & rhs)
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




