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

#include <math/vec3.h>

namespace math
{

	class plane
	{
		public:
			enum
			{
				//constants for ClassifyPoint()
				POINT_ON_PLANE=0,
				POINT_IN_FRONT_OF_PLANE=1,
				POINT_BEHIND_PLANE=2
			};
			plane()	:	normal(vec3(0.0f, 0.0f, 0.0f)), intercept(0.0f)
		{}
			plane(vec3 newNormal, float newIntercept)	: normal(newNormal), intercept(newIntercept)
		{}
			plane(const plane & rhs)
			{	normal=rhs.normal;	intercept=rhs.intercept;	}

			~plane() {}

			void SetNormal(const vec3 & rhs) { normal=rhs; }
			void SetIntercept(float newIntercept) { intercept=newIntercept; }
			void SetFromPoints(const vec3 & p0, const vec3 & p1, const vec3 & p2);

			void CalculateIntercept(const vec3 & pointOnPlane) { intercept=-normal.DotProduct(pointOnPlane); }

			void Normalize(void);

			vec3 GetNormal() { return normal; }
			float GetIntercept() { return intercept; }

			//find point of intersection of 3 planes
			bool Intersect3(const plane & p2, const plane & p3, vec3 & result);

			float GetDistance(const vec3 & point) const;
			int ClassifyPoint(const vec3 & point) const;

			plane lerp(const plane & p2, float factor);

			//operators
			bool operator==(const plane & rhs) const;
			bool operator!=(const plane & rhs) const
			{		return!((*this)==rhs);	}

			//unary operators
			plane operator-(void) const {return plane(-normal, -intercept);}
			plane operator+(void) const {return (*this);}

			//member variables
			vec3 normal;	//X.N+intercept=0
			float intercept;
	};
}


#endif //plane_H
