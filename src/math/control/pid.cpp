#include <PID/Controller.h>

void PID::Controller::Step(int usec)
{
	float e = target_ - x_;
	
	float a = (p_ * e) + (i_ * cum_) 
	
}


