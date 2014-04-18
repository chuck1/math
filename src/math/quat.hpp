#ifndef __QUAT_H__
#define __QUAT_H__

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif

#include <math/config.hpp>

namespace math {
	class quat {
		public:
			quat();
			quat(double nx, double ny, double nz, double nw);
			quat(double angleRadians, vec3<double> const & axis);
			quat(quat const & v);
			quat(vec3<double> const &, vec3<double> const &);
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

			void		toRadiansAndUnitAxis(double& angle, vec3<double>& axis) const;
			double		getAngle() const;
			double		getAngle(const quat& q) const;
			double		magnitudeSquared() const;
			double		dot(const quat& v) const;
			quat		getNormalized() const;
			double		magnitude() const;
			double		normalize();
			quat		getConjugate() const;
			vec3<double>		getImaginaryPart() const;
			vec3<double>		getBasisVector0() const;
			vec3<double>		getBasisVector1() const;
			vec3<double>		getBasisVector2() const;
			const vec3<double>	rotate(const vec3<double>& v) const;
			const vec3<double>	rotateInv(const vec3<double>& v) const;
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

			vec3<double> getOmega(double dt);

			void		print();

			double w,x,y,z;
	};
}

/** @} */
#endif // PX_FOUNDAdoubleION_PX_QUAdouble_H
