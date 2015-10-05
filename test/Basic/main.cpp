#include <iostream>

#include <math/mat44.hpp>
#include <math/quat.hpp>
#include <math/transform.hpp>
#include <math/color.hpp>
#include <math/xml.hpp>

using namespace std;

int main() {
	
	math::transform<float>		t;
	math::Color::color<float>	c;

		
	
	// discrete
	int ** perm;
	int * trans;
	int n = math::discrete::p(3,3);
	cout << n <<endl;
	math::discrete::permutations(perm, trans, 3);
	math::print(perm,n,3);
	math::print(trans,n);
	
	// mat44
	math::mat44<float> m1(t);
	math::mat44<float> m2(m1);
	
	cout << m1.det() << endl;
	m1.getInverseTranspose();
	
	
	m1.getInverse() * m2;
	
	// quat
	printf("quat\n");
	math::quat<float> q;
	
	q = math::quat<float>(0, math::vec3<float>(1,0,0));
	
	cout << "sane = " << q.isSane() << endl;
	
	// xml
	t = math::Xml::parse_transform<float>(NULL, t);
	
	
}




