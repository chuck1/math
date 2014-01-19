#include <math/raw/raw.h>

int     math::raw::vec4::from_math(math::vec4 const & v)
{
        x = v.x;
        y = v.y;
        z = v.z;
	w = v.w;
        
        return 0;
}
math::vec4      math::raw::vec4::to_math()
{
        math::vec4 v;   
                        
        v.x = x;
        v.y = y;        
        v.z = z;
        v.w = z;
	
        return v;
}
int     math::raw::vec3::from_math(math::vec3 const & v)
{
        x = v.x;
        y = v.y;
        z = v.z;
        
        return 0;
}
math::vec3      math::raw::vec3::to_math()
{
        math::vec3 v;   
                        
        v.x = x;
        v.y = y;        
        v.z = z;
                
        return v;
}
int     math::raw::quat::from_math(math::quat const & v)
{                       
        x = v.x;
        y = v.y;        
        z = v.z;
        w = v.w;
                
        return 0;       
}                       
math::quat      math::raw::quat::to_math()
{                       
        math::quat v;   
                
        v.x = x;
        v.y = y;
        v.z = z;
        v.w = w;
        
        return v;
}
int     math::raw::transform::from_math(math::transform const & v)
{
        p.from_math(v.p);
        q.from_math(v.q);
        
        return 0;
}
math::transform         math::raw::transform::to_math() {
        
        math::transform t(p.to_math(), q.to_math());
        
        return t;
}
/*int     math::raw::color::from_math(math::color const & v)
{                       
        r = v.r;
        g = v.g;        
        b = v.b;
        a = v.a;
                
        return 0;       
}                      
math::color	math::raw::color::to_math()
{                       
        math::color v;
                
        v.r = r;
        v.g = g;
        v.b = b;
        v.a = a;
        
        return v;
}*/


