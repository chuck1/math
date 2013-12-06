
#include <math/geo/polyhedron.h>

math::geo::sphere(int slices, int stacks)
{
	//v = new math::geo::vertex[(stacks-1)*slices + 2];

	math::geo::tri north[slices];
	math::geo::tri south[slices];
	
	math::geo::quad quads[slices][stacks-2];
	
	math::geo::vertex poles[2];
	
	poles[0].xyz = vec3(0,-0.5,0);
	poles[1].xyz = vec3(0, 0.5,0);
	
	math::geo::vertex* interior = v + 2;
	
	float theta;
	float phi;
	
	float 
	
	for( int a = 0; a < slices; ++a )
	{
		theta = a * 2.0f * M_PI / (float)slices;
		
		for( int b = 0; b < (stacks-1); ++b )
		{
			phi = -M_PI / 2.0f + (b+1) * M_PI / (float)stacks;
			
			vec3 v( cos(theta)*cos(phi), sin(phi), sin(theta)*cos(phi) );
			
			interior[a][b].v = v;
			interior[a][b].n = v.GetNormalized();
		}
	}
	
	for( int a0 = 0; a0 < slices; ++a0 )
	{
		int a1 = ((a0+1) == slices) ? 0 : (a0+1);
		
		
		north[a0].v[0] = interior[a0][stacks-1];
		north[a0].v[1] = interior[a1][stacks-1];
		north[a0].v[2] = poles[0];

		south[a0].v[0] = interior[a1][0];
		south[a0].v[1] = interior[a0][0];
		south[a0].v[2] = poles[0];

		for( int b0 = 0; b0 < (stacks-1); ++b0 )
		{
			b1 = b0 + 1;

			quad[a0][b0].v[0] = interior[a0][b0];
			quad[a0][b0].v[1] = interior[a1][b0];
			quad[a0][b0].v[2] = interior[a1][b1];
			quad[a0][b0].v[3] = interior[a0][b1];
		}
	}
	
	if( flag_ & math::geo::PER_FACE_NORMAL )
	{
		for( int a0 = 0; a0 < slices; ++a0 )
		{
			int a1 = ((a0+1) == slices) ? 0 : (a0+1);
			
			north[a0].reset_normals();
			south[a0].reset_normals();
			
			for( int b0 = 0; b0 < (stacks-1); ++b0 )
			{
				b1 = b0 + 1;

				quad[a0][b0].reset_normals();
			}
		}

	}
	
	
}

