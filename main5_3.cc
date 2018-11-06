//Example program : main5_3.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in_5_31"), Y(2,2, "in_5_32");

	X.PRINT();
	
	X *= Y;
	
	Y.PRINT();
	X.PRINT();
	
	return 0;
}
