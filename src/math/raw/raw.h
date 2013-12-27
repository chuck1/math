#ifndef __MATH_RAW_H__
#define __MATH_RAW_H__

#include <math/vec3.h>
#include <math/transform.h>
#include <math/color.h>

namespace math
{
        namespace raw
        {
                struct vec3
                {
                        int             from_math(math::vec3 const &);
                        math::vec3      to_math();

                        float   x, y, z;
                };
                struct quat
                {

                        int             from_math(math::quat const &);
                        math::quat      to_math();

                        float   x, y, z, w;
                };
                struct transform
                {
                        math::transform         to_math();
                        int                     from_math(math::transform const &);

                        vec3    p;
                        quat    q;
                };
		struct color
		{
			math::color	to_math();
                        int		from_math(math::color const &);

			float r, g, b, a;
		};
        }
}

#endif



