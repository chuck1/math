#ifndef __MATH_GEO_POLYHEDRON_H__
#define __MATH_GEO_POLYHEDRON_H__

namespace math
{
	namespace geo
	{
		class polyhedron
		{
		};
		class polyhedron_convex: public polyhedron
		{
		};
		class sphere: public polyhedron_convex
		{
			public:
				sphere(int m,int n);
		};
	}
}

#endif


