#include <iostream>

#include <math/mat44.hpp>
#include <math/quat.hpp>
#include <math/transform.hpp>
#include <math/color.hpp>
#include <math/xml.hpp>

using namespace std;

int main() {
	
	math::transform<double>		t;
	math::Color::color<double>	c;

	math::mat44<double>		m1;
	
	// discrete
	int ** perm;
	int * trans;
	int n = math::discrete::p(3,3);
	cout << n <<endl;
	math::discrete::permutations(perm, trans, 3);
	math::print(perm,n,3);

	// mat44
	cout << m1.det() << endl;
	m1.getInverseTranspose();
	
	// quat
	math::quat<double>		q(m1);

	// xml
	t = math::Xml::parse_transform<double>(NULL, t);
	

}




