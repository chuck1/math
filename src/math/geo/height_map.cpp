#include <math/geo/height_map.h>

math::geo::height_map::height_map() {
	
	vertices_ = new vertex[(nx+1)*(ny+1)];
	tris_     = new tri[nx*ny*2];
	
	
	
	
}



