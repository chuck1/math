#ifndef __MATH_CONFIG_H__
#define __MATH_CONFIG_H__

#define MATH_DEBUG_1_FUNCTION printf("%s\n", __PRETTY_FUNCTION__);

#include <exception>

/** \brief %the %math library
 */
namespace math {
	template<typename> class vec3;
	class vec4;
	class mat33;
	class mat44;
	class quat;
	class plane;
	class transform;

	/** \brief exceptions
	 */
	namespace except {
	}

}

#endif

