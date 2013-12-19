#include <math/free.h>
#include <math/vec3.h>

float           math::xml_parse_float(TiXmlElement* element){
        if( !element )
        {
                return 0.0f;
        }

        float f;

        char const * buf = element->GetText();
        
        int c = sscanf(buf, "%f", &f);
        assert(c==1);

        return f;
}
math::quat      math::xml_parse_quat(TiXmlElement* element){
        if( !element )
        {
                return math::quat(0.0f, math::vec3(0,0,0));
        }
                
        float x, y, z, w;
                
        char const * buf = element->GetText(); 
        
        int c = sscanf(buf, "%f,%f,%f,%f", &x, &y, &z, &w);
        assert(c==4);
        
        return math::quat(w, math::vec3(x,y,z));

}       
math::vec3      math::xml_parse_vec3(TiXmlElement* element){       
        if( !element )
        {
                printf("element not found\n");
                exit(0);
                return math::vec3(0.0,0.0,0.0);
        }

        float x, y, z;

        char const * buf = element->GetText();

        int c = sscanf(buf, "%f,%f,%f", &x, &y, &z);
        assert(c==3);

        return math::vec3(x,y,z);
}
math::color     math::xml_parse_color(TiXmlElement* element) {
        if( !element )
        {
                printf("element not found\n");
                exit(0);
                return math::black;
        }

        float r,g,b,a;

        char const * buf = element->GetText();

        int c = sscanf(buf, "%f,%f,%f,%f", &r, &g, &b, &a);
        assert(c==4);

        return math::color(r,g,b,a);
}
math::vec4      math::xml_parse_vec4(TiXmlElement* element) {
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
float	math::recipsqrt(float const & f) {
	return ( sqrt(f)/f );
}






