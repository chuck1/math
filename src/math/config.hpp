#ifndef __MATH_CONFIG_H__
#define __MATH_CONFIG_H__

#define MATH_DEBUG_1_FUNCTION printf("%s\n", __PRETTY_FUNCTION__);

#include <exception>

/** \brief %the %math library
 */
namespace math {
	template<typename> class vec3;
	template<typename> class vec4;
	template<typename> class mat33;
	template<typename> class mat44;
	template<typename> class quat;
	template<typename> class plane;
	template<typename> class transform;

	/** \brief exceptions
	 */
	namespace except {
	}

}

#endif

