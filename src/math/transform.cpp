#include <assert.h>

#include <math/mat44.hpp>
#include <math/plane.hpp>
#include <math/transform.hpp>

math::transform::transform():
	p(0, 0, 0),
	q(1, 0, 0, 0)
{
}
math::transform::transform(const vec3<double>& position):
	p(position),
	q(0, 0, 0, 1)
{
}
math::transform::transform(const quat& orientation):
	p(0, 0, 0),
	q(orientation)
{
	assert(orientation.isSane());
}
math::transform::transform(const math::vec3<double>& p0, const math::quat& q0):
	p(p0),
	q(q0)
{
	if(!q.isSane()) {
		q = quat();
	}
}
math::transform::transform(mat44 const & m)
{
	p = m.GetTranslatedVector3D(math::vec3<double>(0,0,0));
	q = math::quat(m);
}
math::transform	math::transform::operator*(const transform& x) const
{
	assert(x.isSane());
	return transform(x);
}
math::transform math::transform::getInverse() const
{
	assert(isFinite());
	return transform(q.rotateInv(-p),q.getConjugate());
}
math::vec3<double> math::transform::trans(vec3<double> const & input) const
{
	assert(isFinite());
	return q.rotate(input) + p;
}
math::vec3<double> math::transform::transInv(const vec3<double>& input) const
{
	assert(isFinite());
	return q.rotateInv(input-p);
}
math::vec3<double> math::transform::rotate(const vec3<double>& input) const
{
	assert(isFinite());
	return q.rotate(input);
}
math::vec3<double> math::transform::rotateInv(const vec3<double>& input) const
{
	assert(isFinite());
	return q.rotateInv(input);
}
math::transform		math::transform::trans(const transform& src) const
{
	assert(src.isSane());
	assert(isSane());
	// src = [srct, srcr] -> [r*srct + t, r*srcr]
	return transform(q.rotate(src.p) + p, q*src.q);
}
bool math::transform::isValid() const
{
	return p.IsFinite() && q.isFinite() && q.isUnit();
}
bool math::transform::isSane() const
{
	return isFinite() && q.isSane();
}
bool math::transform::isFinite() const
{
	return p.IsFinite() && q.isFinite();
}
math::transform math::transform::transformInv(const transform& src) const
{
	assert(src.isSane());
	assert(isFinite());
	// src = [srct, srcr] -> [r^-1*(srct-t), r^-1*srcr]
	quat qinv = q.getConjugate();
	return transform(qinv.rotate(src.p - p), qinv*src.q);
}
math::transform		math::transform::createIdentity() 
{ 
	return transform(vec3<double>(0)); 
}
math::plane math::transform::trans(plane const & plane) const
{
	vec3<double> transformedNormal = rotate(plane.n);
	return math::plane(transformedNormal, plane.d - p.dot(transformedNormal));
}
math::plane math::transform::inverseTransform(math::plane const & plane) const
{
	vec3<double> transformedNormal = rotateInv(plane.n);
	return math::plane(transformedNormal, plane.d + p.dot(plane.n));
}
math::transform math::transform::getNormalized() const
{
	return transform(p, q.getNormalized());
}
#ifdef PHYSX
math::transform::operator physx::PxTransform() const
{
	return physx::PxTransform(p,q);
}
math::transform&	math::transform::operator=(physx::PxTransform const & rhs)
{
	p = rhs.p;
	q = rhs.q;

	return *this;
}
#endif


