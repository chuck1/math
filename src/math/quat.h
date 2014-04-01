#ifndef __QUAT_H__
#define __QUAT_H__

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif

namespace math
{
	class vec3;
	class mat44;

	class quat {
		public:
			quat();
			quat(double nx, double ny, double nz, double nw);
			quat(double angleRadians, vec3 const & axis);
			quat(quat const & v);
			quat(vec3 const &, vec3 const &);
			quat(mat44 const & m);

			void	loadZero();

			bool	isFinite() const;
			/**
			  \brief returns true if finite and magnitude is close to unit
			 */
			bool	isUnit() const;
			/**
			  \brief returns true if finite and magnitude is reasonably
			  close to unit to allow for some accumulation of error vs isValid
			 */

			bool	isSane() const;

			/**
			  \brief converts this quaternion to angle-axis representation
			 */

			void		toRadiansAndUnitAxis(double& angle, vec3& axis) const;
			double		getAngle() const;
			double		getAngle(const quat& q) const;
			double		magnitudeSquared() const;
			double		dot(const quat& v) const;
			quat		getNormalized() const;
			double		magnitude() const;
			double		normalize();
			quat		getConjugate() const;
			vec3		getImaginaryPart() const;
			vec3		getBasisVector0() const;
			vec3		getBasisVector1() const;
			vec3		getBasisVector2() const;
			const vec3	rotate(const vec3& v) const;
			const vec3	rotateInv(const vec3& v) const;
			quat&		operator=(const quat& p);
			quat&		operator*= (const quat& q);
			quat&		operator+= (const quat& q);
			quat&		operator-= (const quat& q);
			quat&		operator*= (const double s);
			quat		operator*(const quat& q) const;
			quat		operator+(const quat& q) const;
			quat		operator-() const;
			quat		operator-(const quat& q) const;
			quat		operator*(double r) const;
			static quat	createIdentity();
#ifdef PHYSX

			operator physx::PxQuat() const { return physx::PxQuat(x,y,z,w); }
			quat&		operator=(physx::PxQuat const & rhs) {
				x=rhs.x;
				y=rhs.y;
				z=rhs.z;
				w=rhs.w;
				return *this;
			}
#endif

			vec3 getOmega(double dt);

			void		print();

			double w,x,y,z;
	};
}

/** @} */
#endif // PX_FOUNDAdoubleION_PX_QUAdouble_H
