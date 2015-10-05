#ifndef __MATH_GEO_HEIGHT_MAP_HPP__
#define __MATH_GEO_HEIGHT_MAP_HPP__

#include <math/geo/polyhedron.hpp>

namespace math {
	namespace geo {
		template <typename T> class height_map {
			public:
				height_map(int nx, int ny) {
					vertices_	= new vertex<T>[(nx+1)*(ny+1)];
					tris_		= new tri<T>[nx*ny*2];
				}

				vertex<T>*		vertices_;
				tri<T>*			tris_;
		};
	}
}



#endif
