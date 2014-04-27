#ifndef __MATH_GEO_SPHERE_H__
#define __MATH_GEO_SPHERE_H__

//#include <math/config.hpp> // math/config.hpp.in

#include <math/geo/polyhedron.hpp>

namespace math {
	namespace geo {
		template <typename T> class sphere: public polyhedron_convex<T> {
			public:
				sphere(float r, int slices, int stacks) {
					polyhedron_convex<T>::nt_ = 2 * slices;
					polyhedron_convex<T>::nq_ = slices * (stacks-2);
					polyhedron_convex<T>::nv_ = (stacks - 1) * slices + 2;

					std::cout << 
						"tris:  " << polyhedron_convex<T>::nt_ << std::endl <<
						"quads: " << polyhedron_convex<T>::nq_ << std::endl;

					/*
					   vertices_ = new math::geo::vertex[nv_];
					   tris_ = new math::geo::tri[nt_];
					   quads_ = new math::geo::quad[nq_];
					 */

					polyhedron_convex<T>::vertices_ = new math::geo::vertex<T>[polyhedron_convex<T>::nv_];
					polyhedron_convex<T>::tris_ = new math::geo::tri<T>[polyhedron_convex<T>::nt_];
					polyhedron_convex<T>::quads_ = new math::geo::quad<T>[polyhedron_convex<T>::nq_];


					printf("arrays allocated\n");

					/** @todo this function actually doesnt create a vertex for each face adjacent to it
					 * in other words, faces are sharing verticies, so per-face normals wont work properly
					 */


					math::geo::tri<T>* north = polyhedron_convex<T>::tris_;
					math::geo::tri<T>* south = polyhedron_convex<T>::tris_ + slices;

					math::geo::vertex<T>* poles = polyhedron_convex<T>::vertices_;

					poles[0].p = vec3<T>(0,-r,0);
					poles[1].p = vec3<T>(0, r,0);

					poles[0].n = vec3<T>(0,-1,0);
					poles[1].n = vec3<T>(0, 1,0);

					math::geo::vertex<T>* interior = polyhedron_convex<T>::vertices_ + 2;

					T theta;
					T phi;

					for( int a = 0; a < slices; ++a ) {
						theta = a * 2.0f * M_PI / (T)slices;

						for( int b = 0; b < (stacks-1); ++b ) {
							phi = -M_PI / 2.0f + (b+1) * M_PI / (T)stacks;

							//printf("%f %f %f %f\n",theta/M_PI,phi/M_PI,cos(theta),cos(phi));

							vec3<T> v(
									r * cos(theta) * cos(phi),
									r * sin(phi),
									r * sin(theta) * cos(phi));


							//printf("% 5f % 5f % 5f\n",v.x,v.y,v.z);
							//v.print();


							interior[a*slices+b].p = v;
							interior[a*slices+b].n = v.GetNormalized();
						}
					}

					for(int a0 = 0; a0 < slices; ++a0) {
						int a1 = (a0+1) % slices;

						north[a0].v_[2] = interior[a0*slices + stacks-2];
						north[a0].v_[1] = interior[a1*slices + stacks-2];
						north[a0].v_[0] = poles[1];

						south[a0].v_[2] = interior[a1*slices + 0];
						south[a0].v_[1] = interior[a0*slices + 0];
						south[a0].v_[0] = poles[0];

						for( int b0 = 0; b0 < (stacks-2); ++b0 ) {
							int b1 = b0 + 1;

							printf("a0 % 2i a1 % 2i b0 % 2i b1 % 2i\n",a0,a1,b0,b1);

							polyhedron_convex<T>::quads_[a0*slices + b0].v_[3] = interior[a0*slices + b0];
							polyhedron_convex<T>::quads_[a0*slices + b0].v_[2] = interior[a1*slices + b0];
							polyhedron_convex<T>::quads_[a0*slices + b0].v_[1] = interior[a1*slices + b1];
							polyhedron_convex<T>::quads_[a0*slices + b0].v_[0] = interior[a0*slices + b1];
						}
					}

					if(polyhedron_convex<T>::flag_ & polyhedron_convex<T>::PER_FACE_NORMAL) {
						for(int a0 = 0; a0 < slices; ++a0) {
							north[a0].reset_normals();
							south[a0].reset_normals();

							for( int b0 = 0; b0 < (stacks-1); ++b0 )
							{
								polyhedron_convex<T>::quads_[a0*slices + b0].reset_normals();
							}
						}

					}
				}
		};
	}
}

#endif


