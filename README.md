\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_
\_                                                                    \_
\_   THE CITY COLLEGE OF NEW YORK, ELECTRICAL ENGINEERING DEPARTMENT  \_
\_          EE259, FALL 2018, DAY AND EVENING SECTIONS FALL 2018      \_
\_                                                                    \_
\_                              PROJECT 5                             \_
\_     GRADING GUIDE:                                                 \_
\_      4 Examples : 10 points each                                   \_
\_      6 Secret Tests: 10 points each                                \_
\_                                                                    \_
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

PROJECT 5 DESCRIPTION:

Write a C++ class definition called MATRIX whose prototype is defined 
as follows:

class MATRIX: public PROGRAM_BANK{

	friend MATRIX operator / (int, MATRIX) 
			// FRIEND FUNCTION; example: 5 / X;
			// Compute inverse of X using INHERITANCE;
			// Multiply each element of inverted matrix by 5; 
			// store the results into a temp MATRIX;
			// return the temp MATRIX;
	
	friend MATRIX operator * (int, MATRIX); 
			// FRIEND FUNCTION; example: 5 * X;
			// each element of the matrix X is 
			// multiplied by 5;
			// store the results into a temp MATRIX;
			// return the temp MATRIX;

	public:	// public methods for this class
	
	  MATRIX (int, int); 	// constructor;
			// example: MATRIX X(d1,d2);
			// creates a matrix object with
			// private variables dim1 = d1 and dim2 = d2
			// and initializes each element to 0;
  
	  MATRIX(int, int, char *); 
	  		// constructor;
			// example: MATRIX X(d1,d2,"in_name");
			// read the elements of the matrix
			// from a given file in_name; d1 and d2 are 
			// the two dimensions of the matrix;
				
	  void PRINT();	// example: X.PRINT();
			// print the elements of the matrix X
			// into out.5.txt file;
			// returns no values;

	  int  operator < (int); //example: if( X < b)
			// check if the minimum element of the matrix X
			// is less than b
			// returns 1 if so; returns 0 otherwise;
		
	  void operator = (MATRIX);
	  		// example X = Y;
			// Copy Y to X;
			// returns no values;		
		
	  void operator += (MATRIX);  
	  		// example: X += Y;
                        // matrix addition;
                        // store the results in X;
			// values of Y remain unchanged;
			// returns no values;
		
	  void operator *= (MATRIX); 
	  		// example: X *= Y;
			// matrix multiplication;
			// store the results in X;
			// values of Y remain unchanged;
			// returns no values;

	  MATRIX operator + (MATRIX); 
	  		// example: X + Y;
			// Create a temp matrix object; 
			// add each element of Y to each element of X;
			// return this temp matrix object;
			// values of X and Y remain unchanged;

	  MATRIX operator * (MATRIX); 
	  		// example: X * Y;
			// matrix multiplication;
			// store the results into a temp matrix
			// and return this temp matrix;
			// values of Y remain unchanged;

	  MATRIX operator / (MATRIX); 
	  		// example: X / Y;
			// get inverse of Y and multiply it with X;
			// put the results into a temp MATRIX
			// and return temp MATRIX;
			// X and Y remain unchanged;
			// USE INHERITANCE FOR MATRIX INVERSION;
	
	private:
  	  int dim1, dim2; // dimensions of the matrix;
			// if dim2 is 1, a vector (no need for special
			// handling of vectors; everything should work
			// for both matrices and vectors)
  	  double A[20][20]; // 2 dimensional array for the matrix elements;
	  char in_file[11]; // hold the input file name
 };

MAKE SURE THAT EVERY LINE YOUR WRITE INTO out.5.txt ENDS WITH endl.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of the constructor MATRIX is as follows:

	MATRIX X(d1, d2);	

where d1 and d2 should be stored in dim1 and dim2, respectively. 
Initialize all elements of A to 0.  

For inheritance, we need to include the following in the constructor:

	MATRIX::MATRIX(int d1, int d2)
		: PROGRAM_BANK(d1)
	{
		your constructor code goes here
	}

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of the constructor MATRIX is as follows:

	MATRIX X(d1, d2, "in_name");	

where  dim1 and dim2 (both integers, 1 <= dim1,dim2 <= 20) are the dimensions 
of the matrix, and in_name is (char string) the name of the input file.

The format of the matrix in the input file is:

	x_0_0		x_0_1		...	x_0_dim2-1
	x_1_0		x_1_1		...	x_1_dim2-1
	...
	x_dim1-1_0 	x_dim1-1_1 	... 	x_dim1-1_dim2-1

where x_i_j are double numbers.

For inheritance, we need to include the following in the constructor:

	MATRIX::MATRIX(int d1, int d2, char * file_name)
		: PROGRAM_BANK(d1, file_name)
	{
		your constructor code goes here
	}

After reading the values successfully, the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> CREATED A dim1 X dim2 MATRIX FROM file_name
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

If there are errors in the input file data, the output to out.5.txt is:
 		
	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> INPUT ERROR
	+++ P5_OUTPUT >>> UNABLE TO CREATE MATRIX
	+++ P5_OUTPUT >>> EXITING PROGRAM
      	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++


After this message, the program terminates (i.e., it returns).
 
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The overloaded operator / is a friend function of the class since the 
first argument is not an object of the class. An example is:

	c / X

where c is an integer and X is an object of class MATRIX. First compute
the inverse of X using inherited class PROGRAM_BANK. Then multiply each
element of inverted matrix by c and store it in a temp MATRIX. Return temp. 

In your code of friend function operator /, you can run INVERT_MATRIX
method of PROGRAM_BANK as follows:

      friend MATRIX operator / (int x, MATRIX a_matrix)
	{
		...
		a_matrix.INVERT_MATRIX("OUT_5_TEMP.txt");
		...
	}

INVERT_MATRIX writes the inverted matrix into OUT_5_TEMP.txt file with the
following format:

        inv_0_0 	inv_0_1 	... 	inv_0_dim1-1
        ...
        inv_dim1-1_0 	inv_dim1_1 	... 	inv_dim1-1_dim1-1

You need to open OUT_5_TEMP.txt file and read the elements of the inverted matrix
into a temporary matrix. (NOTE: OUT_5_TEMP.txt NAME SHOULD NOT BE CHANGED).

The expected output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> THE RESULT OF c / X OPERATION IS:
	b_0_0   	b_0_1    ... b_0_d1-1
	...
	b_d1-1_0   	b_d1-1_1 ... b_d1-1_d1-1
      	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

where b_i_j is the element of the inverted matrix after it is multiplied
by integer c. 

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The overloaded operator * is a friend function of the class since the 
first argument is not an object of the class.  An example is :

	c * X

where c is an integer and X is an object of class MATRIX. Each element of X 
is multiplied by c and store the results in a temp MATRIX. Return temp. 

The expected output to out.5.txt is:
	
	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> THE RESULT OF c * X OPERATION IS:
	b_0_0   	b_0_1    ... b_0_d2-1
	...
	b_d1-1_0   	b_d1-1_1 ... b_d1-1_d2-1
      	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

where b_i_j is the element of the matrix after integer c multiplies 
each element of X.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

The definition of PRINT method is as follows:

	X.PRINT();

Print the contents of X into out.5.txt with the following format:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
	x_0_0 		x_0_1		...	x_0_dim2-1
	x_1_0 		x_1_1		...	x_1_dim2-1
	...
	x_dim1-1_0 	x_dim1-1_1 	... 	x_dim1-1_dim2-1
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example use of overloaded operator < method is as follows:

	if (X < b)

where X is an object of class MATRIX and b is an integer. This method 
checks if the minimum element of X is less than b.  If so, it returns 1 
with the following output to out.5.txt:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING TRUE
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

Otherwise, it returns 0 with the following output to out.5.txt:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING FALSE
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_ 

An example of overloaded operator = between two MATRIX objects is:

  	X = Y; 

which checks if the dimensions of X and Y objects of MATRIX are equal.
If so, it copies elements of Y into elements of X. Y remains unchanged.
The output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

If the dimensions do not match, the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> ERROR
	+++ P5_OUTPUT>>> INCOMPATIBLE MATRICES
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

 An example of overloaded operator += between two MATRIX objects is:
 
        X += Y;
 
where X and Y are objects of class MATRIX.  This operator adds X and Y
element by element, stores the results into X. If the dimensions are 
compatible, the output to out.5.txt is:
	
	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR += COMPLETED
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

If the dimensions do not match, the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> ERROR
	+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

Note that the values of Y remain unchanged.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

 An example of overloaded operator *= between two MATRIX objects is:
 
        X *= Y;
 
where X and Y are objects of class MATRIX.  This operator multiplies 
objects X and Y, and stores the results into object X. If the 
dimensions are compatible, the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR *= COMPLETED
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

If the dimensions do not match the output to out.5.txt is:
	
	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> ERROR
	+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

Note that the values Y remain unchanged.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

 An example of overloaded operator + is:
 
        X + Y;
 
where X and Y are objects of class MATRIX.  This operator creates a temporary
matrix object, adds Y[i][j] to X[i][j] and stores the results in the temporary
object. It then returns this object. If the dimensions of X and Y match, the 
output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR + COMPLETED
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

If the dimensions do not match the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> ERROR
	+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

Note that the values of X and Y remain unchanged.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example of overloaded operator * between two MATRIX objects is:
 
        X * Y;
 
where X and Y are objects of class MATRIX.  This operator multiplies Matrix X 
and Matrix Y, stores the results into a temp matrix and returns
the temp matrix. If the dimensions are compatible, the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR * COMPLETED
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

If the dimensions do not match the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> ERROR
	+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

An example of the overloaded operator / between two MATRIX objects is:

	X / Y

The inverse of Y is implemented by using inherited class PROGRAM_BANK.
In your code for this overloaded operator, you can run INVERT_MATRIX
method of PROGRAM_BANK as follows:

        MATRIX MATRIX operator / (MATRIX a_matrix)
	{
		...
		a_matrix.INVERT_MATRIX("OUT_5_TEMP.txt");
		...
	}

INVERT_MATRIX writes the inverted matrix into OUT_5_TEMP.txt file with the
following format:

        inv_0_0 	inv_0_1 	... 	inv_0_dim1-1
        ...
        inv_dim1-1_0 	inv_dim1_1 	... 	inv_dim1-1_dim1-1

You need to open OUT_5_TEMP.txt file and read the elements of the inverted 
matrix into a temporary matrix. (NOTE: OUT_5_TEMP.txt NAME SHOULD NOT BE CHANGED).

The expected output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> OVERLOADED OPERATOR / COMPLETED
	+++ P5_OUTPUT >>> THE RESULT OF X/Y OPERATION IS:
	b_0_0   	b_0_1    ... b_0_d1-1
	...
	b_d1-1_0   	b_d1-1_1 ... b_d1-1_d1-1
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

where b_i_j is the element of the inverted matrix after the multiplication 
is complete.

If the dimensions do not match the output to out.5.txt is:

	+++ P5 START +++++++++++++++++++++++++++++++++++++++++
	+++ P5_OUTPUT >>> ERROR
	+++ P5_OUTPUT >>> INCOMPATIBLE MATRICES
	+++ P5 END +++++++++++++++++++++++++++++++++++++++++++

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_
 
 :::::::::::::: EXAMPLE 1 ::::::::::::::::::::: 
//Example program: main5_1.cc
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
---------------CONTENTS OF in_5_11 FILE-----------------
1 1 
1 1
---------------CONTENTS OF in_5_12 FILE-----------------
2 2
2 2
---------------EXPECTED CONTENTS OF out.5.txt FILE-----------------
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_11
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_12
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_12
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING TRUE
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR + COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR < RETURNING TRUE
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
2.00 2.00
2.00 2.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
3.00 3.00
3.00 3.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
:::::::::::::: EXAMPLE 2 ::::::::::::::::::::: 
//Example program: main5_2.cc
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
---------------CONTENTS OF in_5_21 FILE-----------------
1 1 
1 1
---------------CONTENTS OF in_5_22 FILE-----------------
2 2
2 2
---------------EXPECTED CONTENTS OF out.5.txt FILE--------
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_21
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_22
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR * COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
4.00 4.00
4.00 4.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR + COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
3.00 3.00
3.00 3.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
:::::::::::::: EXAMPLE 3 ::::::::::::::::::::: 
//Example program: main5_3.cc
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
---------------CONTENTS OF in_5_31 FILE-----------------
5 4 
2 3
---------------CONTENTS OF in_5_32 FILE-----------------
3 4
2 10
---------------EXPECTED CONTENTS OF out.5.txt FILE--------
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_31
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_32
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
5.00 4.00
2.00 3.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR *= COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
3.00 4.00
2.00 10.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
23.00 60.00
12.00 38.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
:::::::::::::: EXAMPLE 4 ::::::::::::::::::::: 
//Example program: main5_4.cc
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
---------------CONTENTS OF in_5_41 FILE-----------------
1 2 
3 4
---------------CONTENTS OF in_5_42 FILE-----------------
3 4
1 2
---------------EXPECTED CONTENTS OF out.5.txt FILE--------
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_41
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CREATED A 2 X 2 MATRIX FROM in_5_42
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
0.00 0.00
0.00 0.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR / COMPLETED
+++ P5_OUTPUT >>> THE RESULT OF X/Y OPERATION IS:
0.00 1.00
1.00 0.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
0.00 1.00
1.00 0.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> THE RESULT OF 3 / X OPERATION IS:
3.00   -6.00
-1.50   4.50
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
3.00   -6.00
-1.50   4.50
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> THE RESULT OF 3 * X OPERATION IS:
9.00 12.00
3.00  6.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> OVERLOADED OPERATOR = COMPLETED
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
+++ P5 START +++++++++++++++++++++++++++++++++++++++++
+++ P5_OUTPUT >>> CONTENTS OF MATRIX IS:
9.00 12.00
3.00  6.00
+++ P5 END +++++++++++++++++++++++++++++++++++++++++++
 
