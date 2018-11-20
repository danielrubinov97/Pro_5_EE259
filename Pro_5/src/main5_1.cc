//Example program : main5_1.cc
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in_5_11"), Y(2,2, "in_5_12"), Z(2,2, "in_5_12");

	if (X < 2)
	{}
	else
	{
		Y.PRINT(); // shouldn't print;
	}

	Z = X + Y;

	if (Z < 5)
	{
		Y.PRINT(); // print;
	}
	else
	{}

	Z.PRINT(); // print;
	
	return 0;
}
