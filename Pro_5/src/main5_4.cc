//Example program : main5_4.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in_5_41"), Y(2,2, "in_5_42"), Z(2,2);

	Z.PRINT();
	
	Z = X/ Y;
	Z.PRINT();
	
	Z = 3/Y;
	Z.PRINT();

	Z = 3 * Y;
	Z.PRINT();
	
	return 0;
}
