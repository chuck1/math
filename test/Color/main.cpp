
#include <cmath>

#include <math/Color/Dynamic.hpp>

class Sine {
	public:
		float	step(float time) {
			return sin(time + phase);
		}
		float phase;
};

int main() {

	math::Color::Dynamic<float,Sine,Sine,Sine> c1;

	c1.r_.phase = 1.0;


}




