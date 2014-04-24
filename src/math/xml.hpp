#ifndef __MATH_XML_H__
#define __MATH_XML_H__

#include <tinyxml2.h>

#include <math/quat.hpp>
#include <math/vec4.hpp>
#include <math/transform.hpp>
#include <math/color.hpp>

namespace math {
#ifdef TINYXML
	int	xml_parse_int(tinyxml2::XMLElement* element, int v) {

		if(!element) return v;

		char const * buf = element->GetText();

		v = atoi(buf);

		return v;
	}
	float math::xml_parse_float(tinyxml2::XMLElement* element, float f) {

		if(element == NULL) return f;

		char const * buf = element->GetText();

		int c = sscanf(buf, "%f", &f);
		assert(c==1);

		return f;
	}
	template<typename T> math::quat<T> math::xml_parse_quat(tinyxml2::XMLElement* element, math::quat<T> q) {

		if(element == NULL) return q;

		math::vec3<double> v = xml_parse_vec3(element->FirstChildElement("v"), math::vec3<double>(1.0,0.0,0.0));
		float a = xml_parse_float(element->FirstChildElement("a"), 0.0);

		return math::quat<T>(a, v);
	}       
	template<typename T> math::vec3<T> math::xml_parse_vec3(tinyxml2::XMLElement* element, math::vec3<double> v) {

		if( !element )
		{

			return v;
		}

		float x, y, z;

		char const * buf = element->GetText();

		int c = sscanf(buf, "%f,%f,%f", &x, &y, &z);
		assert(c==3);

		return math::vec3<double>(x,y,z);
	}
	template<typename T> math::transform<T> math::xml_parse_transform(tinyxml2::XMLElement* element, math::transform<T> pose) {

		if(element == NULL) return pose;

		pose.p = xml_parse_vec3(element->FirstChildElement("p"), math::vec3<T>(0.0,0.0,0.0));
		pose.q = xml_parse_quat(element->FirstChildElement("q"), math::quat<T>(0.0, math::vec3<T>(1.0,0.0,0.0)));

		return pose;
	}
	template<typename T> math::color<T> math::xml_parse_color(tinyxml2::XMLElement* element, math::color<T> color) {

		if(element == NULL) return color;

		float r,g,b,a;

		char const * buf = NULL;

		buf = element->GetText();
		assert(buf);

		if(strcmp(buf, "red") == 0)
		{
			color = math::red;
		}
		else if(strcmp(buf, "green") == 0)
		{
			color = math::green;
		}
		else if(strcmp(buf, "blue") == 0)
		{
			color = math::blue;
		}
		else if(strcmp(buf, "cyan") == 0)
		{
			color = math::cyan;
		}
		else if(strcmp(buf, "magenta") == 0)
		{
			color = math::magenta;
		}
		else if(strcmp(buf, "yellow") == 0)
		{
			color = math::yellow;
		}
		else if(strcmp(buf, "white") == 0)
		{
			color = math::white;
		}
		else if(strcmp(buf, "black") == 0)
		{
			color = math::black;
		}
		else if(strcmp(buf, "rand") == 0) {
			color = math::color<T>::rand();
		}
		else if(strcmp(buf, "sine") == 0) {
			printf("sine color\n");
			color = math::color<T>(0.25, 0.5, 1.0, 1.0,
					math::color<T>::type::e::SINE,
					math::color<T>::type::e::SINE,
					math::color<T>::type::e::SINE);
		}
		else if(strcmp(buf, "saw") == 0) {
			printf("saw color\n");
			color = math::color<T>(0.2, 0.5, 1.0, 1.0,
					math::color<T>::type::e::SAW,
					math::color<T>::type::e::SAW,
					math::color<T>::type::e::SAW);
		}
		else
		{
			int c = sscanf(buf, "%f,%f,%f,%f", &r, &g, &b, &a);
			if(c != 4)
			{
				printf("invalid color '%s'\n", buf);
				abort();
			}
			color = math::color<T>(r,g,b,a);
		}

		return color;
	}
	template<typename T> math::vec4<T>      math::xml_parse_vec4(tinyxml2::XMLElement* element) {

		if( !element )
		{
			printf("element not found\n");
			exit(0);
			return math::vec4<T>(0,0,0,0);
		}

		float r,g,b,a;

		char const * buf = element->GetText();

		int c = sscanf(buf, "%f,%f,%f,%f", &r, &g, &b, &a);
		assert(c==4);

		return math::vec4<T>(r,g,b,a);
	}
#endif


	float					      	xml_parse_float(tinyxml2::XMLElement*, float = 0.0);
	int						xml_parse_int(tinyxml2::XMLElement*, int);
	template <typename T> math::quat<T>		xml_parse_quat(tinyxml2::XMLElement*, math::quat<T>);
	template <typename T> math::vec3<T>		xml_parse_vec3(tinyxml2::XMLElement*, math::vec3<T>);
	template <typename T> math::vec4<T>		xml_parse_vec4(tinyxml2::XMLElement*);
	template <typename T> math::transform<T>	xml_parse_transform(tinyxml2::XMLElement*, math::transform<T>());
	template <typename T> math::color<T>		xml_parse_color(tinyxml2::XMLElement* element, math::color<T> = math::black);
}

#endif






