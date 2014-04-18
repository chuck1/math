#ifndef TRANSFORM_H
#define TRANSFORM_H

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif

#include <math/config.hpp>
#include <math/vec3.hpp>
#include <math/quat.hpp>


namespace math {
	class transform {
		public:
			transform(); 
			explicit transform(const vec3<double>& position);
			explicit transform(const quat& orientation);
			transform(const vec3<double>& p0, const quat& q0);
			explicit transform(const mat44& m);
			transform	operator*(const transform& x) const;
			transform	getInverse() const;
			vec3<double>		trans(const vec3<double>& input) const;
			vec3<double>		transInv(const vec3<double>& input) const;
			vec3<double>		rotate(const vec3<double>& input) const;
			vec3<double>		rotateInv(const vec3<double>& input) const;
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

			vec3<double>	p;
			quat	q;
	};
}

#endif
