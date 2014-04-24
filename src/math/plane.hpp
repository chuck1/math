//////////////////////////////////////////////////////////////////////////////////////////
//	plane.h
//	Class declaration for a plane in 3d space
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Modified:	6th August 2002		-	Added "Normalize"
//				7th November 2002	-	Altered constructor layout
//									-	Corrected "lerp"
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	

#ifndef plane_H
#define plane_H

#include <math/vec3.hpp>

namespace math {
	template<typename T> class plane {
		public:
			enum
			{
				//constants for ClassifyPoint()
				POINT_ON_PLANE=0,
				POINT_IN_FRONT_OF_PLANE=1,
				POINT_BEHIND_PLANE=2
			};

			/** @name Constructor
			 * @{
			 */
			plane(): n(vec3<double>(0.0f, 0.0f, 0.0f)), d(0.0f) {}
			plane(vec3<double> newNormal, float newIntercept): n(newNormal), d(newIntercept) {}
			plane(const plane & rhs) {
				n=rhs.n;
				d=rhs.d;
			}
			/** @} */
			~plane() {}
			void		setFromPoints(const math::vec3<double> & p0, const math::vec3<double> & p1, const math::vec3<double> & p2)
			{
				n=(p1-p0).cross(p2-p0);

				n.Normalize();

				CalculateIntercept(p0);
			}
			void		normalize() {
				float nLength=n.magnitude();
				n/=nLength;
				d/=nLength;
			}
			bool Intersect3(math::plane<T> const & p2, math::plane<T> const & p3, math::vec3<double> & result)//find point of intersection of 3 planes
			{
				float denominator=n.dot((p2.n).cross(p3.n));
				//scalar triple product of normals
				if(denominator==0.0f)									//if zero
					return false;										//no intersection

				math::vec3<double> temp1, temp2, temp3;
				temp1=(p2.n.cross(p3.n))*d;
				temp2=(p3.n.cross(n))*p2.d;
				temp3=(n.cross(p2.n))*p3.d;

				result=(temp1+temp2+temp3)/(-denominator);

				return true;
			}

			float GetDistance(const math::vec3<double> & point) const
			{
				return point.dot(n) + d;
			}

			int ClassifyPoint(const math::vec3<double> & point) const
			{
				float distance = GetDistance(point);

				if(distance>EPSILON)	//==0.0f is too exact, give a bit of room
					return POINT_IN_FRONT_OF_PLANE;

				if(distance<-EPSILON)
					return POINT_BEHIND_PLANE;

				return POINT_ON_PLANE;	//otherwise
			}

			math::plane<T>		lerp(math::plane<T> const & p2, float factor) {
				math::plane<T> result;

				result.n = n*(1.0f-factor) + p2.n*factor;

				result.n.Normalize();

				result.d = d * (1.0f-factor) + p2.d * factor;

				return result;
			}
			bool			operator==(math::plane<T> const & rhs) const {
				if(n==rhs.n && d == rhs.d)
					return true;

				return false;
			}

			void SetNormal(const vec3<double> & rhs) {
				n=rhs;
			}
			void SetIntercept(float newIntercept) {
				d=newIntercept;
			}
			void SetFromPoints(const vec3<double> & p0, const vec3<double> & p1, const vec3<double> & p2);

			void CalculateIntercept(const vec3<double> & pointOnPlane) { d=-n.dot(pointOnPlane); }

			vec3<double>	getNormal() {
				return n;
			}
			float		getIntercept() {
				return d;
			}
			
			//find point of intersection of 3 planes
		
			//operators
			bool operator!=(const plane & rhs) const
			{		return!((*this)==rhs);	}

			//unary operators
			plane operator-(void) const {return plane(-n, -d);}
			plane operator+(void) const {return (*this);}

			//member variables
			vec3<double>		n;
			float		d;
	};
}


#endif //plane_H
