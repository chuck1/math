
#include <math/mat44.hpp>
#include <math/quat.hpp>
#include <math/transform.hpp>
#include <math/color.hpp>
#include <math/xml.hpp>

int main() {
	
	math::transform<double>		t;
	math::Color::color<double>	c;

	math::mat44<double>		m1;


	t = math::Xml::parse_transform<double>(NULL, t);
	
}




