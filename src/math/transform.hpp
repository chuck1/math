#ifndef TRANSFORM_H
#define TRANSFORM_H

#ifdef PHYSX
#include <PxPhysicsAPI.h>
#endif

#include <math/config.hpp>
#include <math/vec3.hpp>
#include <math/quat.hpp>

namespace math {
	template<typename T> class transform {
		public:
			/** @name Constructors
			 * @{
			 */
			transform(); 
			transform(vec3<T> const & np);
			transform(quat<T> const & nq);
			transform(vec3<T>const & np, quat<T> const & nq);
			transform(mat44<T> const & m);
			/** @} */

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
			/** @name %Transform a %plane
			 * @{
			 */
			plane<T>	trans(plane<T> const & plane) const;
			plane<T>	inverseTransform(plane<T> const & plane) const;
			/** @} */

			transform	getNormalized() const;

#ifdef PHYSX
			operator physx::PxTransform() const;
			transform&	operator=(physx::PxTransform const &);
#endif

			vec3<T>		p;
			quat<T>		q;
	};
}

#endif
