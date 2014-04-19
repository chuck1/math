#ifndef __MATH_FREE_H__
#define __MATH_FREE_H__

#include <tinyxml2.h>

#include <math/quat.hpp>
#include <math/vec4.hpp>
#include <math/transform.hpp>
#include <math/color.hpp>

namespace math {
	float           	xml_parse_float(tinyxml2::XMLElement*, float = 0.0);
	int			xml_parse_int(tinyxml2::XMLElement*, int);
	math::quat      	xml_parse_quat(tinyxml2::XMLElement*, math::quat);
	math::vec3<double>     	xml_parse_vec3(tinyxml2::XMLElement*, math::vec3<double>);
	math::transform		xml_parse_transform(tinyxml2::XMLElement*, math::transform = math::transform());
	math::color     	xml_parse_color(tinyxml2::XMLElement* element, math::color = math::black);
	math::vec4      	xml_parse_vec4(tinyxml2::XMLElement* element);

	quat			slerp(quat, quat, float);

	float			recipsqrt(float const &);

	void			hexdump(void*, size_t);
}

#endif


