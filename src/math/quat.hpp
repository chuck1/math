#ifndef __QUAT_H__
#define __QUAT_H__

#include <cmath>

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif

#include <math/config.hpp>
#include <math/free.hpp>
#include <math/vec3.hpp>

namespace math {
	template <typename T> class quat {
		public:

			quat() {
				loadZero();
			}
			quat(double nx, double ny, double nz, double nw): w(nw),x(nx),y(ny),z(nz) {}
			quat(double angleRadians, vec3<T> const & axis) {
				vec3<T> unitAxis(axis);

				unitAxis.Normalize();

				const double a = angleRadians * 0.5f;
				const double s = sin(a);
				w = cos(a);
				x = unitAxis.v_[0] * s;
				y = unitAxis.v_[1] * s;
				z = unitAxis.v_[2] * s;
			}
			quat(math::quat<T> const & v): w(v.w), x(v.x), y(v.y), z(v.z) {}
			quat(math::vec3<T> const & u, math::vec3<T> const & v) {
				math::vec3<T> a(u);
				math::vec3<T> b(v);

				a.Normalize();
				b.Normalize();

				math::vec3<T> c = a.cross(b);

				x = c.v_[0];
				y = c.v_[1];
				z = c.v_[2];

				w = a.dot(b);

				if(!isSane()) {
					printf("a b c\n");
					a.print();
					b.print();
					c.print();
					throw;
				}
			}
			quat(mat44<T> const & m) {
				T m00 = m.v(0,0);
				T m01 = m.v(0,1);
				T m02 = m.v(0,2);
				T m10 = m.v(1,0);
				T m11 = m.v(1,1);
				T m12 = m.v(1,2);
				T m20 = m.v(2,0);
				T m21 = m.v(2,1);
				T m22 = m.v(2,2);

				T tr = m00 + m11 + m22;

				if (tr > 0)
				{ 
					T S = sqrt(tr+1.0) * 2; // S=4*qw 
					w = 0.25 * S;
					x = (m21 - m12) / S;
					y = (m02 - m20) / S; 
					z = (m10 - m01) / S; 
				}
				else if ((m00 > m11)&(m00 > m22))
				{ 
					T S = sqrt(1.0 + m00 - m11 - m22) * 2; // S=4*qx 
					w = (m21 - m12) / S;
					x = 0.25 * S;
					y = (m01 + m10) / S; 
					z = (m02 + m20) / S; 
				}
				else if (m11 > m22)
				{ 
					T S = sqrt(1.0 + m11 - m00 - m22) * 2; // S=4*qy
					w = (m02 - m20) / S;
					x = (m01 + m10) / S; 
					y = 0.25 * S;
					z = (m12 + m21) / S; 
				}
				else
				{ 
					T S = sqrt(1.0 + m22 - m00 - m11) * 2; // S=4*qz
					w = (m10 - m01) / S;
					x = (m02 + m20) / S;
					y = (m12 + m21) / S;
					z = 0.25 * S;
				}
			}
			void loadZero() {
				x = y = z = 0.0;
				w = 1.0;
			}
			bool		isFinite() const
			{
				return std::isfinite(x) 
					&& std::isfinite(y) 
					&& std::isfinite(z)
					&& std::isfinite(w);
			}
			bool		isUnit() const
			{
				const T unitTolerance = 1e-4;
				return isFinite() && (std::abs(magnitude()-1) < unitTolerance);
			}
			bool		isSane() const
			{
				const T unitTolerance = T(1e-4);
				if(!isFinite()) return false;

				if(std::abs(magnitude()-1) < unitTolerance) {
					return true;
				} else {
					printf("%lf\n", magnitude()-1);
					return false;
				}
			}
			void		toRadiansAndUnitAxis(T& angle, vec3<T>& axis) const
			{
				const T Epsilon = (T(1.0e-8f));
				const T s2 = x*x+y*y+z*z;
				if(s2 < (Epsilon*Epsilon)) {
					angle = 0;
					axis = vec3<T>(1,0,0);
				} else {
					const T s = math::recipsqrt(s2);
					axis = vec3<T>(x,y,z) * s; 
					angle = (std::abs(w) < Epsilon) ? M_PI : atan((s2*s)/w) * 2;
				}

			}
			T		getAngle() const
			{
				const T unitTolerance = 1e-6;

				if(w > 1.0) {
					if(fabs(w - 1.0) < unitTolerance) {
						return 0.0;
					}

					printf("quat<T> getAngle\n");
					printf("w %e\n",w-1.0);
					throw;// math::except::domain();
				}

				if(w < -1.0) {
					if(fabs(w + 1.0) < unitTolerance) {
						return M_PI;
					}

					printf("quat<T> getAngle\n");
					printf("w %e\n",w+1.0);
					throw;// math::except::domain();
				}

				if(isnan(acos(w))) {
					printf("%f\n",w);
					throw;
				}

				return acos(w) * T(2);
			}
			T		getAngle(const math::quat<T>& q) const
			{
				return acos(dot(q)) * T(2);
			}
			T		magnitudeSquared() const
			{
				return x*x + y*y + z*z + w*w;
			}
			T		dot(const math::quat<T>& v) const
			{
				return x * v.x + y * v.y + z * v.z  + w * v.w;
			}
			math::quat<T>	getNormalized() const
			{
				const T s = 1.0f / magnitude();
				return math::quat<T>(x*s, y*s, z*s, w*s);
			}
			T		magnitude() const
			{
				return sqrt(magnitudeSquared());
			}
			T		normalize()
			{
				const T mag = magnitude();
				if(mag)
				{
					const T imag = 1.0f / mag;

					x *= imag;
					y *= imag;
					z *= imag;
					w *= imag;
				}
				return mag;
			}
			math::quat<T>	getConjugate() const
			{
				return math::quat<T>(-x,-y,-z,w);
			}
			math::vec3<T>	getImaginaryPart() const
			{
				return math::vec3<T>(x,y,z);
			}
			math::vec3<T>	getBasisVector0()	const
			{	
				//		return rotate(math::vec3<T>(1,0,0));
				const T x2 = x*2.0f;
				const T w2 = w*2.0f;
				return math::vec3<T>(
						(w * w2) - 1.0f + x*x2,
						(z * w2)        + y*x2,
						(-y * w2)       + z*x2);
			}
			math::vec3<T> getBasisVector1()	const 
			{	
				//		return rotate(math::vec3<T>(0,1,0));
				const T y2 = y*2.0f;
				const T w2 = w*2.0f;
				return math::vec3<T>(
						(-z * w2)       + x*y2,
						(w * w2) - 1.0f + y*y2,
						(x * w2)        + z*y2);
			}
			math::vec3<T> getBasisVector2() const	
			{	
				//		return rotate(math::vec3<T>(0,0,1));
				const T z2 = z*2.0f;
				const T w2 = w*2.0f;
				return math::vec3<T>(
						(y * w2)        + x*z2,
						(-x * w2)       + y*z2,
						(w * w2) - 1.0f + z*z2);
			}
			const math::vec3<T> rotate(const math::vec3<T>& v) const {
				const T vx = 2.0f * v.v_[0];
				const T vy = 2.0f * v.v_[1];
				const T vz = 2.0f * v.v_[2];
				const T w2 = w * w - 0.5f;
				const T dot2 = (x*vx + y*vy +z*vz);
				return math::vec3<T>(
						(vx*w2 + (y * vz - z * vy)*w + x*dot2), 
						(vy*w2 + (z * vx - x * vz)*w + y*dot2), 
						(vz*w2 + (x * vy - y * vx)*w + z*dot2));
				/*
				   const math::vec3<T> qv(x,y,z);
				   return (v*(w*w-0.5f) + (qv.cross(v))*w + qv*(qv.dot(v)))*2;
				   */
			}
			const math::vec3<T> rotateInv(const math::vec3<T>& v) const
			{
				const T vx = 2.0f * v.v_[0];
				const T vy = 2.0f * v.v_[1];
				const T vz = 2.0f * v.v_[2];
				const T w2 = w * w - 0.5f;
				const T dot2 = (x*vx + y*vy +z*vz);
				return math::vec3<T>
					(
					 (vx*w2 - (y * vz - z * vy)*w + x*dot2), 
					 (vy*w2 - (z * vx - x * vz)*w + y*dot2), 
					 (vz*w2 - (x * vy - y * vx)*w + z*dot2)
					);
				//		const math::vec3<T> qv(x,y,z);
				//		return (v*(w*w-0.5f) - (qv.cross(v))*w + qv*(qv.dot(v)))*2;
			}
			math::quat<T>&	operator=(const math::quat<T>& p) {
				x = p.x; y = p.y; z = p.z; w = p.w;	return *this;		
			}
			math::quat<T>& operator*= (const math::quat<T>& q) {
				const T tx = w*q.x + q.w*x + y*q.z - q.y*z;
				const T ty = w*q.y + q.w*y + z*q.x - q.z*x;
				const T tz = w*q.z + q.w*z + x*q.y - q.x*y;

				w = w*q.w - q.x*x - y*q.y - q.z*z;
				x = tx;
				y = ty;
				z = tz;

				return *this;
			}
			math::quat<T>& operator+= (const math::quat<T>& q) {
				x+=q.x;
				y+=q.y;
				z+=q.z;
				w+=q.w;
				return *this;
			}
			math::quat<T>& operator-= (const math::quat<T>& q) {
				x-=q.x;
				y-=q.y;
				z-=q.z;
				w-=q.w;
				return *this;
			}
			math::quat<T>& operator*= (const T s) {
				x*=s;
				y*=s;
				z*=s;
				w*=s;
				return *this;
			}
			math::quat<T> operator*(const math::quat<T>& q) const {
				return math::quat<T>(w*q.x + q.w*x + y*q.z - q.y*z,
						w*q.y + q.w*y + z*q.x - q.z*x,
						w*q.z + q.w*z + x*q.y - q.x*y,
						w*q.w - x*q.x - y*q.y - z*q.z);
			}
			math::quat<T> operator+(const math::quat<T>& q) const
			{
				return math::quat<T>(x+q.x,y+q.y,z+q.z,w+q.w);
			}
			math::quat<T> operator-() const
			{
				return math::quat<T>(-x,-y,-z,-w);
			}
			math::quat<T> operator-(const math::quat<T>& q) const
			{
				return math::quat<T>(x-q.x,y-q.y,z-q.z,w-q.w);
			}
			math::quat<T> operator*(T r) const {
				return math::quat<T>(x*r,y*r,z*r,w*r);
			}
			math::quat<T> createIdentity() {
				return math::quat<T>(0,0,0,1);
			}
			void print() {
				printf("%f %f %f %f\n", x, y, z, w);
			}
			math::vec3<T> getOmega(T dt) {
				vec3<T> v = getImaginaryPart();

				vec3<T> omega;

				if (v.magnitude() > 1.0) {
					printf("%e\n",v.magnitude() - 1.0);
					throw;
				}

				if (v.magnitude() > 0.0) {
					v.Normalize();
					omega = v * getAngle() / dt;
				}

				if(omega.isNan()) throw;

				return omega;
			}


			/**
			  \brief returns true if finite and magnitude is reasonably
			  close to unit to allow for some accumulation of error vs isValid
			  */


			quat<T>		slerp(math::quat<T> q1, float u) {
				math::quat<T> q0(*this);

				q0.normalize();
				q1.normalize();

				math::quat<T> z = q0 * q1.getConjugate();
				float t = acos(z.w);

				math::quat<T> q =  q0 * (sin((1-u)*t) / sin(t)) + q1 * (sin(u*t) / sin(t));

				return q;
			}
			/**
			  \brief converts this quaternion to angle-axis representation
			  */

#ifdef PHYSX

			operator physx::PxQuat() const { return physx::PxQuat(x,y,z,w); }
			quat<T>&		operator=(physx::PxQuat const & rhs) {
				x=rhs.x;
				y=rhs.y;
				z=rhs.z;
				w=rhs.w;
				return *this;
			}
#endif

			T w,x,y,z;
	};
}

/** @} */
#endif // PX_FOUNDATION_PX_QUAT_H
