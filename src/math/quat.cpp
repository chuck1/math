#include <cmath>
#include <stdio.h>

#include <math/config.hpp>
#include <math/except.hpp>
#include <math/mat44.hpp>
#include <math/free.hpp>
#include <math/vec3.hpp>
#include <math/quat.hpp>


#include <gal/except.h>

math::quat::quat()
{
	loadZero();
}
math::quat::quat(double nx, double ny, double nz, double nw):
	w(nw),x(nx),y(ny),z(nz)
{}
math::quat::quat(double angleRadians, vec3<double> const & axis)
{
	vec3<double> unitAxis(axis);

	unitAxis.Normalize();

	const double a = angleRadians * 0.5f;
	const double s = sin(a);
	w = cos(a);
	x = unitAxis.v[0] * s;
	y = unitAxis.v[1] * s;
	z = unitAxis.v[2] * s;
}
math::quat::quat(math::quat const & v):
	w(v.w), x(v.x), y(v.y), z(v.z)
{
}
math::quat::quat(math::vec3<double> const & u, math::vec3<double> const & v)
{
	math::vec3<double> a(u);
	math::vec3<double> b(v);
	
	a.Normalize();
	b.Normalize();

	math::vec3<double> c = a.cross(b);
	
	x = c.v[0];
	y = c.v[1];
	z = c.v[2];
	
	w = a.dot(b);
	
	if(!isSane()) {
		printf("a b c\n");
		a.print();
		b.print();
		c.print();
		throw gal::except();
	}
}
math::quat::quat(mat44 const & m)
{
	double m00 = m.entries[0];
	double m01 = m.entries[1];
	double m02 = m.entries[2];
	double m10 = m.entries[4];
	double m11 = m.entries[5];
	double m12 = m.entries[6];
	double m20 = m.entries[8];
	double m21 = m.entries[9];
	double m22 = m.entries[10];

	double tr = m00 + m11 + m22;

	if (tr > 0)
	{ 
		double S = sqrt(tr+1.0) * 2; // S=4*qw 
		w = 0.25 * S;
		x = (m21 - m12) / S;
		y = (m02 - m20) / S; 
		z = (m10 - m01) / S; 
	}
	else if ((m00 > m11)&(m00 > m22))
	{ 
		double S = sqrt(1.0 + m00 - m11 - m22) * 2; // S=4*qx 
		w = (m21 - m12) / S;
		x = 0.25 * S;
		y = (m01 + m10) / S; 
		z = (m02 + m20) / S; 
	}
	else if (m11 > m22)
	{ 
		double S = sqrt(1.0 + m11 - m00 - m22) * 2; // S=4*qy
		w = (m02 - m20) / S;
		x = (m01 + m10) / S; 
		y = 0.25 * S;
		z = (m12 + m21) / S; 
	}
	else
	{ 
		double S = sqrt(1.0 + m22 - m00 - m11) * 2; // S=4*qz
		w = (m10 - m01) / S;
		x = (m02 + m20) / S;
		y = (m12 + m21) / S;
		z = 0.25 * S;
	}
}
void math::quat::loadZero() {
	x = y = z = 0.0;
	w = 1.0;
}
bool		math::quat::isFinite() const
{
	return std::isfinite(x) 
		&& std::isfinite(y) 
		&& std::isfinite(z)
		&& std::isfinite(w);
}
bool		math::quat::isUnit() const
{
	const double unitTolerance = 1e-4;
	return isFinite() && (std::abs(magnitude()-1) < unitTolerance);
}
bool		math::quat::isSane() const
{
	const double unitTolerance = double(1e-4);
	if(!isFinite()) return false;
	
	if(std::abs(magnitude()-1) < unitTolerance) {
		return true;
	} else {
		printf("%lf\n", magnitude()-1);
		return false;
	}
}
void		math::quat::toRadiansAndUnitAxis(double& angle, vec3<double>& axis) const
{
	const double Epsilon = (double(1.0e-8f));
	const double s2 = x*x+y*y+z*z;
	if(s2 < (Epsilon*Epsilon))  // can't extract a sensible axis
	{
		angle = 0;
		axis = vec3<double>(1,0,0);
	}
	else
	{
		const double s = math::recipsqrt(s2);
		axis = vec3<double>(x,y,z) * s; 
		angle = (std::abs(w) < Epsilon) ? M_PI : atan((s2*s)/w) * 2;
	}

}
double		math::quat::getAngle() const
{
	const double unitTolerance = 1e-6;

	if(w > 1.0) {
		if(fabs(w - 1.0) < unitTolerance) {
			return 0.0;
		}
		
		printf("quat getAngle\n");
		printf("w %e\n",w-1.0);
		throw math::except::domain();
	}
	
	if(w < -1.0) {
		if(fabs(w + 1.0) < unitTolerance) {
			return M_PI;
		}
		
		printf("quat getAngle\n");
		printf("w %e\n",w+1.0);
		throw math::except::domain();
	}
	
	if(isnan(acos(w))) {
		printf("%f\n",w);
		throw;
	}

	return acos(w) * double(2);
}
double		math::quat::getAngle(const math::quat& q) const
{
	return acos(dot(q)) * double(2);
}
double		math::quat::magnitudeSquared() const
{
	return x*x + y*y + z*z + w*w;
}
double		math::quat::dot(const math::quat& v) const
{
	return x * v.x + y * v.y + z * v.z  + w * v.w;
}
math::quat	math::quat::getNormalized() const
{
	const double s = 1.0f / magnitude();
	return math::quat(x*s, y*s, z*s, w*s);
}
double		math::quat::magnitude() const
{
	return sqrt(magnitudeSquared());
}
double		math::quat::normalize()
{
	const double mag = magnitude();
	if(mag)
	{
		const double imag = 1.0f / mag;
		
		x *= imag;
		y *= imag;
		z *= imag;
		w *= imag;
	}
	return mag;
}
math::quat	math::quat::getConjugate() const
{
	return math::quat(-x,-y,-z,w);
}
math::vec3<double>	math::quat::getImaginaryPart() const
{
	return math::vec3<double>(x,y,z);
}
math::vec3<double>	math::quat::getBasisVector0()	const
{	
	//		return rotate(math::vec3<double>(1,0,0));
	const double x2 = x*2.0f;
	const double w2 = w*2.0f;
	return math::vec3<double>(
			(w * w2) - 1.0f + x*x2,
			(z * w2)        + y*x2,
			(-y * w2)       + z*x2);
}
math::vec3<double> math::quat::getBasisVector1()	const 
{	
	//		return rotate(math::vec3<double>(0,1,0));
	const double y2 = y*2.0f;
	const double w2 = w*2.0f;
	return math::vec3<double>(
			(-z * w2)       + x*y2,
			(w * w2) - 1.0f + y*y2,
			(x * w2)        + z*y2);
}
math::vec3<double> math::quat::getBasisVector2() const	
{	
	//		return rotate(math::vec3<double>(0,0,1));
	const double z2 = z*2.0f;
	const double w2 = w*2.0f;
	return math::vec3<double>(
			(y * w2)        + x*z2,
			(-x * w2)       + y*z2,
			(w * w2) - 1.0f + z*z2);
}
const math::vec3<double> math::quat::rotate(const math::vec3<double>& v) const
{
	const double vx = 2.0f*v.v[0];
	const double vy = 2.0f*v.v[1];
	const double vz = 2.0f*v.v[2];
	const double w2 = w*w-0.5f;
	const double dot2 = (x*vx + y*vy +z*vz);
	return math::vec3<double>
		(
		 (vx*w2 + (y * vz - z * vy)*w + x*dot2), 
		 (vy*w2 + (z * vx - x * vz)*w + y*dot2), 
		 (vz*w2 + (x * vy - y * vx)*w + z*dot2)
		);
	/*
	   const math::vec3<double> qv(x,y,z);
	   return (v*(w*w-0.5f) + (qv.cross(v))*w + qv*(qv.dot(v)))*2;
	   */
}
const math::vec3<double> math::quat::rotateInv(const math::vec3<double>& v) const
{
	const double vx = 2.0f*v.v[0];
	const double vy = 2.0f*v.v[1];
	const double vz = 2.0f*v.v[2];
	const double w2 = w*w-0.5f;
	const double dot2 = (x*vx + y*vy +z*vz);
	return math::vec3<double>
		(
		 (vx*w2 - (y * vz - z * vy)*w + x*dot2), 
		 (vy*w2 - (z * vx - x * vz)*w + y*dot2), 
		 (vz*w2 - (x * vy - y * vx)*w + z*dot2)
		);
	//		const math::vec3<double> qv(x,y,z);
	//		return (v*(w*w-0.5f) - (qv.cross(v))*w + qv*(qv.dot(v)))*2;
}
math::quat&	math::quat::operator=(const math::quat& p)
{
	x = p.x; y = p.y; z = p.z; w = p.w;	return *this;		
}
math::quat& math::quat::operator*= (const math::quat& q)
{
	const double tx = w*q.x + q.w*x + y*q.z - q.y*z;
	const double ty = w*q.y + q.w*y + z*q.x - q.z*x;
	const double tz = w*q.z + q.w*z + x*q.y - q.x*y;

	w = w*q.w - q.x*x - y*q.y - q.z*z;
	x = tx;
	y = ty;
	z = tz;

	return *this;
}
math::quat& math::quat::operator+= (const math::quat& q)
{
	x+=q.x;
	y+=q.y;
	z+=q.z;
	w+=q.w;
	return *this;
}
math::quat& math::quat::operator-= (const math::quat& q)
{
	x-=q.x;
	y-=q.y;
	z-=q.z;
	w-=q.w;
	return *this;
}
math::quat& math::quat::operator*= (const double s)
{
	x*=s;
	y*=s;
	z*=s;
	w*=s;
	return *this;
}
math::quat math::quat::operator*(const math::quat& q) const
{
	return math::quat(w*q.x + q.w*x + y*q.z - q.y*z,
			w*q.y + q.w*y + z*q.x - q.z*x,
			w*q.z + q.w*z + x*q.y - q.x*y,
			w*q.w - x*q.x - y*q.y - z*q.z);
}
math::quat math::quat::operator+(const math::quat& q) const
{
	return math::quat(x+q.x,y+q.y,z+q.z,w+q.w);
}
math::quat math::quat::operator-() const
{
	return math::quat(-x,-y,-z,-w);
}
math::quat math::quat::operator-(const math::quat& q) const
{
	return math::quat(x-q.x,y-q.y,z-q.z,w-q.w);
}
math::quat math::quat::operator*(double r) const {
	return math::quat(x*r,y*r,z*r,w*r);
}
math::quat math::quat::createIdentity() {
	return math::quat(0,0,0,1);
}
void math::quat::print() {
	printf("%f %f %f %f\n", x, y, z, w);
}
math::vec3<double> math::quat::getOmega(double dt) {
	vec3<double> v = getImaginaryPart();
	
	vec3<double> omega;
	
	if (v.magnitude() > 1.0) {
		printf("%e\n",v.magnitude() - 1.0);
		throw;
	}
	
	if (v.magnitude() > 0.0) {
		v.Normalize();
		omega = v * getAngle() / dt;
	}
	
	if(omega.IsNan()) throw;

	return omega;
}

