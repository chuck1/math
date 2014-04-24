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
			transform(): p(0, 0, 0), q(1, 0, 0, 0) {}
			transform(const vec3<T>& np): p(np), q(0, 0, 0, 1) {}
			transform(quat<T> const & nq): p(0, 0, 0), q(nq) {
				assert(nq.isSane());
			}
			transform(math::vec3<T> const & p0, math::quat<T> const & q0): p(p0), q(q0) {
				if(!q.isSane()) {
					q = quat<T>();
				}
			}
			transform(mat44<T> const & m)
			{
				p = m.GetTranslatedVector3D(math::vec3<T>(0,0,0));
				q = math::quat<T>(m);
			}
			/** @} */

			math::transform<T>	operator*(const transform& x) const {
				assert(x.isSane());
				return transform(x);
			}
			math::transform<T>	getInverse() const {
				assert(isFinite());
				return transform(q.rotateInv(-p),q.getConjugate());
			}

			/** @name Transformations
			 * @{
			 */
			math::vec3<T>		trans(vec3<T> const & input) const {
				assert(isFinite());
				return q.rotate(input) + p;
			}
			math::vec3<T>		transInv(const vec3<T>& input) const {
				assert(isFinite());
				return q.rotateInv(input-p);
			}
			math::vec3<T>		rotate(const vec3<T>& input) const {
				assert(isFinite());
				return q.rotate(input);
			}
			math::vec3<T>		rotateInv(const vec3<T>& input) const {
				assert(isFinite());
				return q.rotateInv(input);
			}
			math::transform<T>	trans(const transform& src) const {
				assert(src.isSane());
				assert(isSane());
				// src = [srct, srcr] -> [r*srct + t, r*srcr]
				return transform(q.rotate(src.p) + p, q*src.q);
			}
			math::transform<T>	transInv(transform const & src) const {
				assert(src.isSane());
				assert(isFinite());
				// src = [srct, srcr] -> [r^-1*(srct-t), r^-1*srcr]
				math::quat<T> qinv = q.getConjugate();
				return transform(qinv.rotate(src.p - p), qinv*src.q);
			}
			math::plane<T>		trans(plane<T> const & plane) const {
				vec3<T> transformedNormal = rotate(plane.n);
				return math::plane<T>(transformedNormal, plane.d - p.dot(transformedNormal));
			}
			math::plane<T>		transInverse(math::plane<T> const & plane) const {
				vec3<T> transformedNormal = rotateInv(plane.n);
				return math::plane<T>(transformedNormal, plane.d + p.dot(plane.n));
			}
			/** @} */

			bool			isValid() const {
				return p.IsFinite() && q.isFinite() && q.isUnit();
			}
			bool			isSane() const {
				return isFinite() && q.isSane();
			}
			bool			isFinite() const {
				return p.IsFinite() && q.isFinite();
			}

			math::transform<T>	getNormalized() const {
				return transform(p, q.getNormalized());
			}
#ifdef PHYSX
			operator physx::PxTransform() const {
				return physx::PxTransform(p,q);
			}
			math::transform<T>&	operator=(physx::PxTransform const & rhs) {
				p = rhs.p;
				q = rhs.q;

				return *this;
			}
#endif

			vec3<T>		p;
			quat<T>		q;
	};
}

#endif
