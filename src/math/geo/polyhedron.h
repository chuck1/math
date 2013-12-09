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
				vec3	xyz;
				vec3	n;
		};
		class polygon
		{

		};
		class tri
		{
			public:
				void	reset_normals();

				vertex	v_[3];
		};
		class quad
		{
			public:
				void	reset_normals();

				vertex	v_[4];
		};
		class polyhedron
		{
			public:
				enum
				{
					PER_FACE_NORMAL
				};

				vertex*		vertices_;
				tri*		tris_;
				quad*		quads_;
				int		nt_;
				int 		nq_;
				unsigned int	flag_;
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


