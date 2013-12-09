#ifndef __MATH_GEO_POLYHEDRON_H__
#define __MATH_GEO_POLYHEDRON_H__

#include <math/vec3.h>

namespace math
{
	namespace geo
	{
		class vertex
		{
			public:
			math::vec3	xyz;
			math::vec3	n;
		};
		class polygon
		{

		};
		class tri
		{
			public:
				vertex	v[3];	
		};
		class quad
		{
			public:
				vertex	v[4];		
		};
		class polyhedron
		{

		};
		class polyhedron_convex: public polyhedron
		{
		};
		class sphere: public polyhedron_convex
		{
			public:
				sphere(float,int,int);
		};
		class wedge: public polyhedron_convex
		{

		};
		class tetrahedron: public polyhedron_convex
		{

		};
		class cuboid: public polyhedron_convex
		{
			public:
				cuboid(float,float,float);
		};
	}
}

#endif


