#ifndef __GAL_CONTROL_PID_H__
#define __GAL_CONTROL_PID_H__

namespace math
{
	namespace control
	{
		class pid
		{
			public:
				void step(double);

				double last_;

				float x_;
				float target_;

				float p_;
				float i_;
				float d_;


		};
	}
}

#endif


