#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stdlib.h>
#include "/ee259/tools/pro_5/inversion.h"

using namespace std;

ifstream input_file_temp;	
ofstream output_file("out.5", ios::out);

class MATRIX: public PROGRAM_BANK{

	friend MATRIX operator / (int, MATRIX); 
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

	public:	// public interfaces for this class
	
	  MATRIX (int, int); // constructor;
			// example: MATRIX X(d1,d2);
			// creates a matrix object with
			// private variables dim1 = d1 and dim2 = d2
			// and initializes each element to 0;
  
	  MATRIX(int, int, char *); // constructor;
			// example: MATRIX X(d1,d2,"in_name");
			// read the elements of the matrix
			// from a given file in_name; d1 and d2 are 
			// the two dimensions of the matrix;
				
	  void PRINT();	// example: X.PRINT();
			// print the elements of the matrix X
			// into out.5 file;
			// returns no values;

	  int  operator < (int); //example: if( X < b)
			// check if the minimum element of the matrix X
			// is less than b
			// returns 1 if so; returns 0 otherwise;
	
	  void operator = (MATRIX ); // example X = Y;
			// Copy Y to X;
			// returns no values;		
		
	  void operator += (MATRIX);  // example: X += Y;
                        // matrix addition;
                        // store the results in X;
			// values of Y remain unchanged;
			// returns no values;
		
	  void operator *= (MATRIX); // example: X *= Y;
			// matrix multiplication;
			// store the results in X;
			// values of Y remain unchanged;
			// returns no values;

	  MATRIX operator + (MATRIX); // example: X + Y;
			// Create a temp matrix object; 
			// add each element of Y to each element of X;
			// return this temp matrix object;
			// values of X and Y remain unchanged;

	  MATRIX operator * (MATRIX); // example: X * Y;
			// matrix multiplication;
			// store the results into a temp matrix
			// and return this temp matrix;
			// values of Y remain unchanged;

	  MATRIX operator / (MATRIX); // example: X / Y;
			// get inverse of Y and multiply it with X;
			// put the results into a temp MATRIX
			// and return temp MATRIX;
			// X and Y remain unchanged;
			// USE INHERITENCE FOR MATRIX INVERSION;
	
	private:

  	  int dim1, dim2; // dimensions of the matrix;
			// if dim2 is 1, a vector (no need for special
			// handling of vectors; everything should work
			// for both matrices and vectors)

  	  double A[20][20]; // 2 dimensional array for the matrix elements;
	  char in_file[11]; // hold the input file name
 };


// FIRST CONSTRUCTOR
MATRIX::MATRIX(int d1, int d2)
        :PROGRAM_BANK(d1) // CALL THE CONSTRUCTOR OF THE BASE CLASS
{
	int dim1 = d1 - 1; //Convert to index form.
	int dim2 = d2 - 1;
	int allocatedMemory = sqrt(sizeof(A)/sizeof(A[0][0])); //Allocated Memory of Array.
							       //Assuming Array has equal dims.
	for(int i = 0; i < dim1; i++){ //Possibly do full allocated matrix.
		for(int j = 0; j < dim2; j++){
			A[i][j] = 0;
		}
	}
}

// SECOND CONSTRUCTOR
MATRIX::MATRIX(int d1, int d2, char * file_name)
        :PROGRAM_BANK(d1, file_name) // CALL THE CONSTRUCTOR OF THE BASE CLASS
{
	 // your constructor code goes here
	output_file << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	
	int allocatedMemory = sqrt(sizeof(A)/sizeof(A[0][0])); //Allocated Memory of Array.
	int in_file_length = sizeof(in_file)/sizeof(in_file[0]);
	int file_name_length = strlen(file_name);
	cout << in_file_length << endl;
	if(d1 >= 1 && d2 >= 1 && d1 <= allocatedMemory && d2 <= allocatedMemory && file_name_length < in_file_length){
	// store the input file name:
	strcpy(in_file, file_name);

	// define the input file
 	ifstream input_file(in_file,ios::in);
	
	int dim1 = d1 - 1; //Convert to index form.
	int dim2 = d2 - 1;
	for (int i = 0; i < dim1; i++){
		for(int j = 0; j < dim2; j++){
			input_file >> A[i][j];
		}
	}
	output_file << "+++ P5_OUTPUT >>> CREATED A " << d1 << " X " << d2 << " MATRIX FROM " << in_file << endl;
	}
	else{
		output_file << "+++ P5_OUTPUT >>> INPUT ERROR" << endl;
		output_file << "+++ P5_OUTPUT >>> UNABLE TO CREATE MATRIX" << endl;
		output_file << "+++ P5_OUTPUT >>> EXITING PROGRAM" << endl;
		output_file << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
		exit (EXIT_FAILURE);
	}
	output_file << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
}

MATRIX operator / (int c, MATRIX a_matrix)
{
        MATRIX temp_matrix(a_matrix.dim1, a_matrix.dim2);
	
	output_file << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	a_matrix.INVERT_MATRIX("OUT_5_TEMP.txt");
	input_file_temp.open("OUT_5_TEMP.txt", ios::in);

	for(int i = 0; i < temp_matrix.dim1; i++){
		for(int j = 0; j < temp_matrix.dim2; j++){
			input_file_temp >> temp_matrix.A[i][j];
		}
	}
	
	input_file_temp.close();
	input_file_temp.clear();
	output_file << "+++ P5_OUTPUT >>> THE RESULT OF c / X OPERATION IS:" << endl;
	for(int i = 0; i < temp_matrix.dim1; i++){
		for(int j = 0; j < temp_matrix.dim2; j++){
			temp_matrix.A[i][j] = temp_matrix.A[i][j] * c;
			output_file << temp_matrix.A[i][j] << " ";
		}
		output_file << endl;
	}
	output_file << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
        return temp_matrix;
}

MATRIX operator * (int c, MATRIX a_matrix)
{
        MATRIX temp_matrix(a_matrix.dim1, a_matrix.dim2);
	output_file << "+++ P5 START +++++++++++++++++++++++++++++++++++++++++" << endl;
	output_file << "+++ P5_OUTPUT >>> THE RESULT OF c * X OPERATION IS:" << endl;
	
	for(int i = 0; i < temp_matrix.dim1; i++){
		for(int j = 0; j < temp_matrix.dim2; j++){
			temp_matrix.A[i][j] = temp_matrix.A[i][j] * c;
			output_file << temp_matrix.A[i][j] << " ";
		}
		output_file << endl;
	}
	output_file << "+++ P5 END +++++++++++++++++++++++++++++++++++++++++++" << endl;
        return temp_matrix;
}

void
MATRIX::PRINT( )
{

}

int
MATRIX::operator < (int b)
{
        return 0;
}


void
MATRIX::operator = (MATRIX a_matrix)
{

}

void
MATRIX::operator += (MATRIX a_matrix)
{

}

void
MATRIX::operator *= (MATRIX a_matrix)
{

}

MATRIX
MATRIX::operator + (MATRIX a_matrix)
{
        MATRIX temp_matrix(dim1, dim2);


        return temp_matrix;
}

MATRIX
MATRIX::operator * (MATRIX a_matrix)
{
        MATRIX temp_matrix(dim1, dim2);


        return temp_matrix;
}

MATRIX
MATRIX::operator / (MATRIX a_matrix)
{
        MATRIX temp_matrix(dim1, dim2);


        return temp_matrix;
}
