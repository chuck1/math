#ifndef __MATH_FREE_H__
#define __MATH_FREE_H__

#include <tinyxml2.h>

#include <math/quat.h>
#include <math/vec4.h>
#include <math/color.h>

namespace math
{
	float           xml_parse_float(tinyxml2::XMLElement* element);
        math::quat      xml_parse_quat(tinyxml2::XMLElement* element);
        math::vec3      xml_parse_vec3(tinyxml2::XMLElement* element);       
        math::color     xml_parse_color(tinyxml2::XMLElement* element);
        math::vec4      xml_parse_vec4(tinyxml2::XMLElement* element);
	
	float recipsqrt(float const &);
}
#endif
