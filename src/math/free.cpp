#include <stdio.h>

#include <math/free.hpp>
#include <math/vec3.hpp>

#ifdef TINYXML
int math::xml_parse_int(tinyxml2::XMLElement* element, int v) {
	
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
math::quat math::xml_parse_quat(tinyxml2::XMLElement* element, math::quat q) {
	
	if(element == NULL) return q;
	
	math::vec3<double> v = xml_parse_vec3(element->FirstChildElement("v"), math::vec3<double>(1.0,0.0,0.0));
	float a = xml_parse_float(element->FirstChildElement("a"), 0.0);
	
	return math::quat(a, v);
}       
math::vec3<double> math::xml_parse_vec3(tinyxml2::XMLElement* element, math::vec3<double> v) {
	
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
math::transform math::xml_parse_transform(tinyxml2::XMLElement* element, math::transform pose) {
	
	if(element == NULL) return pose;
	
	pose.p = xml_parse_vec3(element->FirstChildElement("p"), math::vec3<double>(0.0,0.0,0.0));
	pose.q = xml_parse_quat(element->FirstChildElement("q"), math::quat(0.0, math::vec3<double>(1.0,0.0,0.0)));
	
	return pose;
}
math::color math::xml_parse_color(tinyxml2::XMLElement* element, math::color color) {

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
	else if(strcmp(buf, "rand") == 0)
	{
		color = math::color::rand();
	}
	else if(strcmp(buf, "sine") == 0)
	{
		printf("sine color\n");
		color = math::color(0.25, 0.5, 1.0, 1.0,
				math::color::type::e::SINE,
				math::color::type::e::SINE,
				math::color::type::e::SINE);
	}
	else if(strcmp(buf, "saw") == 0)
	{
		printf("saw color\n");
		color = math::color(0.2, 0.5, 1.0, 1.0,
				math::color::type::e::SAW,
				math::color::type::e::SAW,
				math::color::type::e::SAW);
	}
	else
	{
		int c = sscanf(buf, "%f,%f,%f,%f", &r, &g, &b, &a);
		if(c != 4)
		{
			printf("invalid color '%s'\n", buf);
			abort();
		}
		color = math::color(r,g,b,a);
	}

	return color;
}
math::vec4      math::xml_parse_vec4(tinyxml2::XMLElement* element) {

	if( !element )
	{
		printf("element not found\n");
		exit(0);
		return math::vec4(0,0,0,0);
	}

	float r,g,b,a;

	char const * buf = element->GetText();

	int c = sscanf(buf, "%f,%f,%f,%f", &r, &g, &b, &a);
	assert(c==4);

	return math::vec4(r,g,b,a);
}
#endif

math::quat math::slerp(math::quat q0, math::quat q1, float u) {

	q0.normalize();
	q1.normalize();

	math::quat z = q0 * q1.getConjugate();
	float t = acos(z.w);

	math::quat q =  q0 * (sin((1-u)*t) / sin(t)) + q1 * (sin(u*t) / sin(t));

	return q;
}


float	math::recipsqrt(float const & f) {
	return ( sqrt(f)/f );
}
void math::hexdump(void* v, size_t s) {

	unsigned char* c = (unsigned char*)v;
	unsigned char* end = c + s;

	for(; c < end; ++c)
	{
		printf("%02X ", *c);
	}
	printf("\n");
}



