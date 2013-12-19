//////////////////////////////////////////////////////////////////////////////////////////
//	plane.cpp
//	function definitions for RGBA color class
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Modified:	6th August 2002	-	Added "Normalize"
//				7th November 2002	-	Altered constructor layout
//									-	Corrected "lerp"
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#include <math/plane.h>

void math::plane::SetFromPoints(const math::vec3 & p0, const math::vec3 & p1, const math::vec3 & p2)
{
	n=(p1-p0).cross(p2-p0);

	n.normalize();

	CalculateIntercept(p0);
}

void math::plane::Normalize()
{
	float nLength=n.magnitude();
	n/=nLength;
	d/=nLength;
}

bool math::plane::Intersect3(const math::plane & p2, const math::plane & p3, math::vec3 & result)//find point of intersection of 3 planes
{
	float denominator=n.dot((p2.n).cross(p3.n));
											//scalar triple product of normals
	if(denominator==0.0f)									//if zero
		return false;										//no intersection

	math::vec3 temp1, temp2, temp3;
	temp1=(p2.n.cross(p3.n))*d;
	temp2=(p3.n.cross(n))*p2.d;
	temp3=(n.cross(p2.n))*p3.d;

	result=(temp1+temp2+temp3)/(-denominator);

	return true;
}

float math::plane::GetDistance(const math::vec3 & point) const
{
	return point.dot(n) + d;
}

int math::plane::ClassifyPoint(const math::vec3 & point) const
{
	float distance = GetDistance(point);
	
	if(distance>EPSILON)	//==0.0f is too exact, give a bit of room
		return POINT_IN_FRONT_OF_PLANE;
	
	if(distance<-EPSILON)
		return POINT_BEHIND_PLANE;

	return POINT_ON_PLANE;	//otherwise
}

math::plane math::plane::lerp(const math::plane & p2, float factor)
{
	math::plane result;

	result.n = n*(1.0f-factor) + p2.n*factor;

	result.n.normalize();

	result.d = d * (1.0f-factor) + p2.d * factor;

	return result;
}

bool math::plane::operator ==(const math::plane & rhs) const
{
	if(n==rhs.n && d == rhs.d)
		return true;

	return false;
}
