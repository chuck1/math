#ifndef TRANSFORM_H
#define TRANSFORM_H

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif

#include <math/vec3.h>
#include <math/quat.h>

namespace math
{
	class mat44;
	class plane;
	class transform
	{
		public:
			transform(); 
			explicit transform(const vec3& position);
			explicit transform(const quat& orientation);
			transform(const vec3& p0, const quat& q0);
			explicit transform(const mat44& m);
			transform	operator*(const transform& x) const;
			transform	getInverse() const;
			vec3		trans(const vec3& input) const;
			vec3		transInv(const vec3& input) const;
			vec3		rotate(const vec3& input) const;
			vec3		rotateInv(const vec3& input) const;
			transform	trans(const transform& src) const;
			bool		isValid() const;
			bool		isSane() const;
			bool		isFinite() const;
			transform	transformInv(const transform& src) const;
			static		transform createIdentity();
			plane		trans(const plane& plane) const;
			plane		inverseTransform(const plane& plane) const;
			transform	getNormalized() const;

#ifdef PHYSX
			operator physx::PxTransform() const;
			transform&	operator=(physx::PxTransform const &);
#endif

			math::vec3	p;
			math::quat	q;
	};
}

#endif
