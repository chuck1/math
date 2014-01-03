#include <cmath>

#include <math/mat44.h>
#include <math/free.h>
#include <math/vec3.h>
#include <math/quat.h>

math::quat::quat()
{}
math::quat::quat(float nx, float ny, float nz, float nw):
	x(nx),y(ny),z(nz),w(nw)
{}
math::quat::quat(float angleRadians, vec3 const & axis)
{
	vec3 unitAxis(axis);

	unitAxis.normalize();

	const float a = angleRadians * 0.5f;
	const float s = sin(a);
	w = cos(a);
	x = unitAxis.x * s;
	y = unitAxis.y * s;
	z = unitAxis.z * s;
}
math::quat::quat(math::quat const & v):
	x(v.x), y(v.y), z(v.z), w(v.w)
{
}
math::quat::quat(math::vec3 const & u, math::vec3 const & v)
{
	math::vec3 a = u.cross(v);

	x = a.x;
	y = a.y;
	z = a.z;

	w = sqrt( u.magnitudeSquared() * v.magnitudeSquared() ) + u.dot(v);
}
math::quat::quat(mat44 const & m)
{
	float m00 = m.entries[0];
	float m01 = m.entries[1];
	float m02 = m.entries[2];
	float m10 = m.entries[4];
	float m11 = m.entries[5];
	float m12 = m.entries[6];
	float m20 = m.entries[8];
	float m21 = m.entries[9];
	float m22 = m.entries[10];

	float tr = m00 + m11 + m22;

	if (tr > 0)
	{ 
		float S = sqrt(tr+1.0) * 2; // S=4*qw 
		w = 0.25 * S;
		x = (m21 - m12) / S;
		y = (m02 - m20) / S; 
		z = (m10 - m01) / S; 
	}
	else if ((m00 > m11)&(m00 > m22))
	{ 
		float S = sqrt(1.0 + m00 - m11 - m22) * 2; // S=4*qx 
		w = (m21 - m12) / S;
		x = 0.25 * S;
		y = (m01 + m10) / S; 
		z = (m02 + m20) / S; 
	}
	else if (m11 > m22)
	{ 
		float S = sqrt(1.0 + m11 - m00 - m22) * 2; // S=4*qy
		w = (m02 - m20) / S;
		x = (m01 + m10) / S; 
		y = 0.25 * S;
		z = (m12 + m21) / S; 
	}
	else
	{ 
		float S = sqrt(1.0 + m22 - m00 - m11) * 2; // S=4*qz
		w = (m10 - m01) / S;
		x = (m02 + m20) / S;
		y = (m12 + m21) / S;
		z = 0.25 * S;
	}
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
	const float unitTolerance = 1e-4;
	return isFinite() && (std::abs(magnitude()-1) < unitTolerance);
}
bool		math::quat::isSane() const
{
	const float unitTolerance = float(1e-2);
	return isFinite() && std::abs(magnitude()-1)<unitTolerance;
}
void		math::quat::toRadiansAndUnitAxis(float& angle, vec3& axis) const
{
	const float Epsilon = (float(1.0e-8f));
	const float s2 = x*x+y*y+z*z;
	if(s2 < (Epsilon*Epsilon))  // can't extract a sensible axis
	{
		angle = 0;
		axis = vec3(1,0,0);
	}
	else
	{
		const float s = math::recipsqrt(s2);
		axis = vec3(x,y,z) * s; 
		angle = (std::abs(w) < Epsilon) ? M_PI : atan((s2*s)/w) * 2;
	}

}
float		math::quat::getAngle() const
{
	return acos(w) * float(2);
}
float		math::quat::getAngle(const math::quat& q) const
{
	return acos(dot(q)) * float(2);
}
float		math::quat::magnitudeSquared() const
{
	return x*x + y*y + z*z + w*w;
}
float		math::quat::dot(const math::quat& v) const
{
	return x * v.x + y * v.y + z * v.z  + w * v.w;
}
math::quat	math::quat::getNormalized() const
{
	const float s = 1.0f/magnitude();
	return math::quat(x*s, y*s, z*s, w*s);
}
float		math::quat::magnitude() const
{
	return sqrt(magnitudeSquared());
}
float		math::quat::normalize()
{
	const float mag = magnitude();
	if (mag)
	{
		const float imag = float(1) / mag;

		x *= imag;
		y *= imag;
		z *= imag;
		w *= imag;
	}
	return mag;
}
math::quat math::quat::getConjugate() const
{
	return math::quat(-x,-y,-z,w);
}
math::vec3 math::quat::getImaginaryPart() const
{
	return math::vec3(x,y,z);
}
math::vec3 math::quat::getBasisVector0()	const
{	
	//		return rotate(math::vec3(1,0,0));
	const float x2 = x*2.0f;
	const float w2 = w*2.0f;
	return math::vec3(	(w * w2) - 1.0f + x*x2,
			(z * w2)        + y*x2,
			(-y * w2)       + z*x2);
}
math::vec3 math::quat::getBasisVector1()	const 
{	
	//		return rotate(math::vec3(0,1,0));
	const float y2 = y*2.0f;
	const float w2 = w*2.0f;
	return math::vec3(	(-z * w2)       + x*y2,
			(w * w2) - 1.0f + y*y2,
			(x * w2)        + z*y2);
}
math::vec3 math::quat::getBasisVector2() const	
{	
	//		return rotate(math::vec3(0,0,1));
	const float z2 = z*2.0f;
	const float w2 = w*2.0f;
	return math::vec3(	(y * w2)        + x*z2,
			(-x * w2)       + y*z2,
			(w * w2) - 1.0f + z*z2);
}
const math::vec3 math::quat::rotate(const math::vec3& v) const
{
	const float vx = 2.0f*v.x;
	const float vy = 2.0f*v.y;
	const float vz = 2.0f*v.z;
	const float w2 = w*w-0.5f;
	const float dot2 = (x*vx + y*vy +z*vz);
	return math::vec3
		(
		 (vx*w2 + (y * vz - z * vy)*w + x*dot2), 
		 (vy*w2 + (z * vx - x * vz)*w + y*dot2), 
		 (vz*w2 + (x * vy - y * vx)*w + z*dot2)
		);
	/*
	   const math::vec3 qv(x,y,z);
	   return (v*(w*w-0.5f) + (qv.cross(v))*w + qv*(qv.dot(v)))*2;
	 */
}
const math::vec3 math::quat::rotateInv(const math::vec3& v) const
{
	const float vx = 2.0f*v.x;
	const float vy = 2.0f*v.y;
	const float vz = 2.0f*v.z;
	const float w2 = w*w-0.5f;
	const float dot2 = (x*vx + y*vy +z*vz);
	return math::vec3
		(
		 (vx*w2 - (y * vz - z * vy)*w + x*dot2), 
		 (vy*w2 - (z * vx - x * vz)*w + y*dot2), 
		 (vz*w2 - (x * vy - y * vx)*w + z*dot2)
		);
	//		const math::vec3 qv(x,y,z);
	//		return (v*(w*w-0.5f) - (qv.cross(v))*w + qv*(qv.dot(v)))*2;
}
math::quat&	math::quat::operator=(const math::quat& p)
{
	x = p.x; y = p.y; z = p.z; w = p.w;	return *this;		
}
math::quat& math::quat::operator*= (const math::quat& q)
{
	const float tx = w*q.x + q.w*x + y*q.z - q.y*z;
	const float ty = w*q.y + q.w*y + z*q.x - q.z*x;
	const float tz = w*q.z + q.w*z + x*q.y - q.x*y;

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
math::quat& math::quat::operator*= (const float s)
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
math::quat math::quat::operator*(float r) const
{
	return math::quat(x*r,y*r,z*r,w*r);
}
math::quat math::quat::createIdentity()
{
	return math::quat(0,0,0,1);
}
void math::quat::print() {
	printf("%f %f %f %f\n", x, y, z, w);
}


