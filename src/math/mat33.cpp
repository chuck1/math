//////////////////////////////////////////////////////////////////////////////////////////
//	math::mat44.cpp
//	function definitions for 4x4 matrix class
//	Downloaded from: www.paulsprojects.net
//	Created:	20th July 2002
//	Updated:	19th August 2002	-	Corrected 2nd SetPerspective for n!=1.0f
//				26th September 2002	-	Added nudge to prevent artifacts with infinite far plane
//									-	Improved speed
//				7th November 2002	-	Added Affine Inverse functions
//									-	Changed constructors
//									-	Added special cases for row3 = (0, 0, 0, 1)
//				17th December 2002	-	Converted from radians to degrees for consistency
//										with OpenGL. Should have been done a long time ago...
//
//	Copyright (c) 2006, Paul Baker
//	Distributed under the New BSD Licence. (See accompanying file License.txt or copy at
//	http://www.paulsprojects.net/NewBSDLicense.txt)
//////////////////////////////////////////////////////////////////////////////////////////	
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include <math/vec3.hpp>
#include <math/vec4.hpp>
#include <math/transform.hpp>
#include <math/mat33.hpp>
#include <math/quat.hpp>
#include <math/plane.hpp>





