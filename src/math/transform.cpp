#include <assert.h>

#include <math/plane.h>
#include <math/transform.h>

math::transform::transform():
	p(0, 0, 0),
	q(1, 0, 0, 0)
{
}
math::transform::transform(const vec3& position):
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
math::transform::transform(const math::vec3& p0, const math::quat& q0):
	p(p0),
	q(q0)
{
	assert(q0.isSane());
}
math::transform::transform(mat44 const & m)
{

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
math::vec3 math::transform::trans(vec3 const & input) const
{
	assert(isFinite());
	return q.rotate(input) + p;
}
math::vec3 math::transform::transInv(const vec3& input) const
{
	assert(isFinite());
	return q.rotateInv(input-p);
}
math::vec3 math::transform::rotate(const vec3& input) const
{
	assert(isFinite());
	return q.rotate(input);
}
math::vec3 math::transform::rotateInv(const vec3& input) const
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
	return p.is_finite() && q.isFinite() && q.isUnit();
}
bool math::transform::isSane() const
{
	return isFinite() && q.isSane();
}
bool math::transform::isFinite() const
{
	return p.is_finite() && q.isFinite();
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
	return transform(vec3(0)); 
}
math::plane math::transform::trans(plane const & plane) const
{
	vec3 transformedNormal = rotate(plane.n);
	return math::plane(transformedNormal, plane.d - p.dot(transformedNormal));
}
math::plane math::transform::inverseTransform(math::plane const & plane) const
{
	vec3 transformedNormal = rotateInv(plane.n);
	return math::plane(transformedNormal, plane.d + p.dot(plane.n));
}
math::transform math::transform::getNormalized() const
{
	return transform(p, q.getNormalized());
}
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


