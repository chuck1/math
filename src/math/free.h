#ifndef __MATH_FREE_H__
#define __MATH_FREE_H__

#include <tinyxml/tinyxml.h>

#include <math/quat.h>
#include <math/vec4.h>
#include <math/color.h>

namespace math
{
	float           xml_parse_float(TiXmlElement* element);
        math::quat      xml_parse_quat(TiXmlElement* element);
        math::vec3      xml_parse_vec3(TiXmlElement* element);       
        math::color     xml_parse_color(TiXmlElement* element);
        math::vec4      xml_parse_vec4(TiXmlElement* element);
	
	float recipsqrt(float const &);
}
#endif
