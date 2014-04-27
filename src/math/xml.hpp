#ifndef __MATH_XML_H__
#define __MATH_XML_H__

#include <tinyxml2.h>

#include <math/quat.hpp>
#include <math/vec4.hpp>
#include <math/transform.hpp>
#include <math/color.hpp>

namespace math {
#ifdef TINYXML2

	
	namespace Xml {
		template<typename T> T				parse_int(tinyxml2::XMLElement* element, int v) {

			if(!element) return v;

			char const * buf = element->GetText();

			v = atoi(buf);

			return v;
		}
		template<typename T> T				parse_float(tinyxml2::XMLElement* element, T f) {

			if(element == NULL) return f;

			char const * buf = element->GetText();

			scan(buf, f);

			return f;
		}
		template<typename T> math::vec3<T>		parse_vec3(tinyxml2::XMLElement* element, math::vec3<T> v) {
			
			if(!element) return v;
			
			float x, y, z;
			
			char const * buf = element->GetText();

			int c = sscanf(buf, "%f,%f,%f", &x, &y, &z);
			assert(c==3);
			
			math::vec3<T> ret(x,y,z);
			
			if(!ret.isSane()) {
				ret.print();
				exit(0);
			}
			
			return ret;
		}
		template<typename T> math::quat<T>		parse_quat(tinyxml2::XMLElement* element, math::quat<T> q) {

			if(element == NULL) return q;

			math::vec3<T> v = parse_vec3<T>(element->FirstChildElement("v"), math::vec3<T>(1.0,0.0,0.0));

			T a = parse_float<T>(element->FirstChildElement("a"), 0.0);

			printf("xml parse quat\n");
			v.print();
			printf("%f\n", a);

			return math::quat<T>(a, v);
		}       

		template<typename T> math::transform<T>		parse_transform(tinyxml2::XMLElement* element, math::transform<T> pose) {

			if(element == NULL) return pose;

			pose.p = parse_vec3<T>(element->FirstChildElement("p"), math::vec3<T>(0.0,0.0,0.0));
			pose.q = parse_quat<T>(element->FirstChildElement("q"), math::quat<T>(0.0, math::vec3<T>(1.0,0.0,0.0)));

			return pose;
		}
		template<typename T> math::Color::color<T>	parse_color(tinyxml2::XMLElement* element, math::Color::color<T> color) {

			if(element == NULL) return color;

			T r,g,b,a;

			char const * buf = NULL;

			buf = element->GetText();
			assert(buf);

			if(strcmp(buf, "red") == 0)
			{
				color = math::Color::red<T>();
			}
			else if(strcmp(buf, "green") == 0)
			{
				color = math::Color::green<T>();
			}
			else if(strcmp(buf, "blue") == 0)
			{
				color = math::Color::blue<T>();
			}
			else if(strcmp(buf, "cyan") == 0)
			{
				color = math::Color::cyan<T>();
			}
			else if(strcmp(buf, "magenta") == 0)
			{
				color = math::Color::magenta<T>();
			}
			else if(strcmp(buf, "yellow") == 0)
			{
				color = math::Color::yellow<T>();
			}
			else if(strcmp(buf, "white") == 0)
			{
				color = math::Color::white<T>();
			}
			else if(strcmp(buf, "black") == 0)
			{
				color = math::Color::black<T>();
			}
			else if(strcmp(buf, "rand") == 0) {
				color.rand();
			}
			else if(strcmp(buf, "sine") == 0) {
				printf("sine color\n");
				color = math::Color::color<T>(0.25, 0.5, 1.0, 1.0);
				//		math::color<T>::type::e::SINE,
				//		math::color<T>::type::e::SINE,
				//		math::color<T>::type::e::SINE);
			}
			else if(strcmp(buf, "saw") == 0) {
				printf("saw color\n");
				color = math::Color::color<T>(0.2, 0.5, 1.0, 1.0);
				//		math::color<T>::type::e::SAW,
				//		math::color<T>::type::e::SAW,
				//		math::color<T>::type::e::SAW);
			}
			else
			{
				int c = sscanf(buf, "%f,%f,%f,%f", &r, &g, &b, &a);
				if(c != 4)
				{
					printf("invalid color '%s'\n", buf);
					abort();
				}
				color = math::Color::color<T>(r,g,b,a);
			}

			return color;
		}
		template<typename T> math::vec4<T>		parse_vec4(tinyxml2::XMLElement* element) {

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
	}
#endif
}

#endif






