#ifndef __MATH_GEO_POLYHEDRON_H__
#define __MATH_GEO_POLYHEDRON_H__

namespace math
{
	namespace geo
	{
		class polygon
		{
			
		};
		class tri
		{
			
		};
		class quad
		{
			
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


