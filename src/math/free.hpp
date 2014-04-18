#ifndef __MATH_FREE_H__
#define __MATH_FREE_H__

#ifdef TINYXML
#include <tinyxml2.h>
#endif

#include <math/quat.hpp>
#include <math/vec4.hpp>
#include <math/transform.hpp>
#include <math/color.hpp>

namespace math {
#ifdef TINYXML
	float           	xml_parse_float(tinyxml2::XMLElement*, float = 0.0);
	int			xml_parse_int(tinyxml2::XMLElement*, int);
	math::quat      	xml_parse_quat(tinyxml2::XMLElement*, math::quat);
	math::vec3      	xml_parse_vec3(tinyxml2::XMLElement*, math::vec3);
	math::transform		xml_parse_transform(tinyxml2::XMLElement*, math::transform = math::transform());
	math::color     	xml_parse_color(tinyxml2::XMLElement* element, math::color = math::black);
	math::vec4      	xml_parse_vec4(tinyxml2::XMLElement* element);
#endif

	quat			slerp(quat, quat, float);

	float			recipsqrt(float const &);

	void			hexdump(void*, size_t);
}

#endif


