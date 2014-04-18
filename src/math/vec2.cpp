//////////////////////////////////////////////////////////////////////////////////////////
//	vec2.cpp
//	Function definitions for 2d vector class
//	Downloaded from: www.paulsprojects.net
//	Created:	8th November 2002
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#include <math/math.hpp>
#include <math/vec2.hpp>

void math::vec2::Normalize()
{
	float length;
	float scalefactor;
	length=GetLength();

	if(length==1 || length==0)			//return if length is 1 or 0
		return;

	scalefactor = 1.0f/length;
	x *= scalefactor;
	y *= scalefactor;
}
math::vec2 math::vec2::GetNormalized() const
{
	vec2 result(*this);

	result.Normalize();

	return result;
}
math::vec2 operator*(float scaleFactor, const math::vec2 & rhs)
{
	return rhs*scaleFactor;
}

bool math::vec2::operator==(const math::vec2 & rhs) const
{
	if(x==rhs.x && y==rhs.y)
		return true;

	return false;
}



