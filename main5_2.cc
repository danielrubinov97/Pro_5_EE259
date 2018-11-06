//Example program : main5_2.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2,"in_5_21"), Y(2,2, "in_5_22"), Z(2,2);

	Z = X*Y;
	Z.PRINT();
	
	Z = X+Y;
	Z.PRINT();
	
	return 0;
}
