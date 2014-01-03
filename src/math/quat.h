#ifndef __QUAT_H__
#define __QUAT_H__

#include <PxPhysicsAPI.h>

namespace math
{
	class vec3;
	class mat44;

	class quat
	{
		public:
			quat();
			quat(float nx, float ny, float nz, float nw);
			quat(float angleRadians, vec3 const & axis);
			quat(quat const & v);
			quat(vec3 const &, vec3 const &);
			quat(mat44 const & m);
			
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

			void toRadiansAndUnitAxis(float& angle, vec3& axis) const;
			float getAngle() const;
			float getAngle(const quat& q) const;
			float magnitudeSquared() const;
			float dot(const quat& v) const;
			quat getNormalized() const;
			float magnitude() const;
			float normalize();
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
			quat&		operator*= (const float s);
			quat		operator*(const quat& q) const;
			quat		operator+(const quat& q) const;
			quat		operator-() const;
			quat		operator-(const quat& q) const;
			quat		operator*(float r) const;
			static quat	createIdentity();

			operator physx::PxQuat() const { return physx::PxQuat(x,y,z,w); }
			quat&		operator=(physx::PxQuat const & rhs) { x=rhs.x; y=rhs.y; z=rhs.z; w=rhs.w; return *this; }
			void		print();
			
			float x,y,z,w;
	};
}

/** @} */
#endif // PX_FOUNDATION_PX_QUAT_H
