#include <stdio.h>

#include <math/array/array.h>

int main() {


	array<double,2> a;
	array<double,2> b;
	array<double,2> c;

	a.alloc(2,2);
	b.alloc(2,2);
	
	//printf("%i %i\n", a.shape[0], a.shape[1]);

	//a.print("%3.1f ");
	a.at<1,1>() = 1;
	
	b.at<0,1>() = 2;
	
	c = a + b;

	c.print("%3.1f ");



	return 0;
}


