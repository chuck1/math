#ifndef __MATH_GEO_POLYHEDRON_H__
#define __MATH_GEO_POLYHEDRON_H__

//#include <math/config.hpp> // math/config.hpp.in
#include <math/vec3.hpp>

namespace math {
	namespace geo {
		template <typename T> class vertex {
			public:
				math::vec3<T>		p;
				math::vec3<T>		n;
		};
		template <typename T> class polygon {

		};
		template<typename T> class tri {
			public:
				void	reset_normals();

				vertex<T>	v_[3];
		};
		template<typename T> class quad {
			public:
				void	reset_normals();

				vertex<T>	v_[4];
		};
		template<typename T> class polyhedron {
			public:
				enum
				{
					PER_FACE_NORMAL
				};

				vertex<T>*		vertices_;
				tri<T>*			tris_;
				quad<T>*		quads_;
				int			nt_;
				int 			nq_;
				int			nv_;
				unsigned int		flag_;
		};
		template <typename T> class polyhedron_convex: public polyhedron<T> {
		};
		template <typename T> class wedge: public polyhedron_convex<T> {
		};
		template <typename T> class tetrahedron: public polyhedron_convex<T> {
		};
		template <typename T> class cuboid: public polyhedron_convex<T> {
			public:
				cuboid(float,float,float);
		};
	}
}

#endif


