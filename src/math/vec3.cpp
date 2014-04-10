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

math::vec3::vec3() {
	LoadZero();
}
math::vec3::vec3(double const & nx, double const & ny, double const & nz) {
	v[0] = nx;
	v[1] = ny;
	v[2] = nz;
}
math::vec3::vec3(double const * const v):
	math::vecbase<double,3>(v)
{
}

double	math::vec3::dot(math::vec3 const & rhs) const
{
	return v[0]*rhs.v[0] + v[1]*rhs.v[1] + v[2]*rhs.v[2];
}
math::vec3	math::vec3::cross(const vec3 & rhs) const
{
	return vec3(v[1]*rhs.v[2] - v[2]*rhs.v[1], v[2]*rhs.v[0] - v[0]*rhs.v[2], v[0]*rhs.v[1] - v[1]*rhs.v[0]);
}
math::vec3		math::vec3::operator+(const vec3 & rhs) const
{
	math::vec3 a(*this);
	a += rhs;
	return a;
}
math::vec3		math::vec3::operator-(const vec3 & rhs) const {
	math::vec3 a(*this);
	a -= rhs;
	return a;
}
math::vec3		math::vec3::operator*(const double rhs) const {
	math::vec3 a(*this);
	a *= rhs;
	return a;
}
math::vec3		math::vec3::operator/(const double rhs) const {
	math::vec3 a(*this);
	a /= rhs;
	return a;
}
math::vec3 math::vec3::GetNormalized() const {

	vec3 result(*this);

	result.Normalize();

	return result;
}
math::vec3 math::vec3::GetRotatedX(double angle) const {

	if(angle==0.0) return (*this);

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);

	return vec3(	v[0],
			v[1]*cosAngle - v[2]*sinAngle,
			v[1]*sinAngle + v[2]*cosAngle);
}
void math::vec3::RotateX(double angle) {

	(*this)=GetRotatedX(angle);
}
math::vec3 math::vec3::GetRotatedY(double angle) const {

	if(angle==0.0) return (*this);

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);

	return math::vec3(	v[0]*cosAngle + v[2]*sinAngle,
			v[1],
			-v[0]*sinAngle + v[2]*cosAngle);
}
void math::vec3::RotateY(double angle) {

	(*this)=GetRotatedY(angle);
}
math::vec3 math::vec3::GetRotatedZ(double angle) const {

	if(angle==0.0) return (*this);

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);

	return math::vec3(v[0]*cosAngle - v[1]*sinAngle,
			v[0]*sinAngle + v[1]*cosAngle,
			v[2]);
}
void math::vec3::RotateZ(double angle) {

	(*this)=GetRotatedZ(angle);
}
math::vec3 math::vec3::GetRotatedAxis(double angle, const math::vec3 & axis) const {

	if(angle==0.0) return (*this);

	math::vec3 u = axis.GetNormalized();

	math::vec3 rotMatrixRow0, rotMatrixRow1, rotMatrixRow2;

	float sinAngle=(float)sin(M_PI*angle/180);
	float cosAngle=(float)cos(M_PI*angle/180);
	float oneMinusCosAngle=1.0f-cosAngle;

	rotMatrixRow0.v[0]=(u.v[0])*(u.v[0]) + cosAngle*(1-(u.v[0])*(u.v[0]));
	rotMatrixRow0.v[1]=(u.v[0])*(u.v[1])*(oneMinusCosAngle) - sinAngle*u.v[2];
	rotMatrixRow0.v[2]=(u.v[0])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[1];

	rotMatrixRow1.v[0]=(u.v[0])*(u.v[1])*(oneMinusCosAngle) + sinAngle*u.v[2];
	rotMatrixRow1.v[1]=(u.v[1])*(u.v[1]) + cosAngle*(1-(u.v[1])*(u.v[1]));
	rotMatrixRow1.v[2]=(u.v[1])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[0];

	rotMatrixRow2.v[0]=(u.v[0])*(u.v[2])*(oneMinusCosAngle) - sinAngle*u.v[1];
	rotMatrixRow2.v[1]=(u.v[1])*(u.v[2])*(oneMinusCosAngle) + sinAngle*u.v[0];
	rotMatrixRow2.v[2]=(u.v[2])*(u.v[2]) + cosAngle*(1-(u.v[2])*(u.v[2]));

	return math::vec3( dot(rotMatrixRow0), dot(rotMatrixRow1), dot(rotMatrixRow2));
}
double		math::vec3::angle(vec3 const & rhs) const {

	math::vec3 v = cross(rhs);

	return acos( v.magnitude() / magnitude() / rhs.magnitude() );
}
void		math::vec3::RotateAxis(double angle, const math::vec3 & axis) {

	(*this) = GetRotatedAxis(angle, axis);
}
void		math::vec3::PackTo01() {

	(*this)=GetPackedTo01();	
}
void		math::vec3::Add(const vec3 & v2, vec3 & result) {

	result.v[0]=v[0]+v2.v[0];
	result.v[1]=v[1]+v2.v[1];
	result.v[2]=v[2]+v2.v[2];
}
void		math::vec3::Subtract(const vec3 & v2, vec3 & result) {

	result.v[0]=v[0]-v2.v[0];
	result.v[1]=v[1]-v2.v[1];
	result.v[2]=v[2]-v2.v[2];
}
math::vec3	math::vec3::GetPackedTo01() const {

	math::vec3 temp(*this);

	temp.Normalize();

	temp = temp * 0.5f + math::vec3(0.5f, 0.5f, 0.5f);

	return temp;
}
math::vec3 operator*(double scaleFactor, const math::vec3 & rhs) {

	return rhs*scaleFactor;
}
bool		math::vec3::operator==(const math::vec3 & rhs) const {

	if(v[0]==rhs.v[0] && v[1]==rhs.v[1] && v[2]==rhs.v[2])
		return true;

	return false;
}
bool		math::vec3::operator!=(const vec3 & rhs) const {

	return !((*this)==rhs);
}
math::vec3&		math::vec3::operator+=(math::vec3 const & rhs) {
	math::vecbase<double,3>::operator+=(rhs);
	return *this;
}
math::vec3&		math::vec3::operator-=(const vec3 & rhs) {
	math::vecbase<double,3>::operator-=(rhs);
	return *this;
}
math::vec3&		math::vec3::operator*=(const double rhs) {
	math::vecbase<double,3>::operator*=(rhs);
	return *this;

	v[0]*=rhs;	v[1]*=rhs;	v[2]*=rhs;
}
math::vec3&		math::vec3::operator/=(const double rhs) {
	math::vecbase<double,3>::operator/=(rhs);
	return *this;
}
void	math::vec3::print() const {

	printf("%f %f %f\n",v[0],v[1],v[2]);
}



