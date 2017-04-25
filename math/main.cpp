/*
	1 Raise a number to a power
	2 Reduce a fraction // ust use two pass by reference parameters
	3 Show the Fibonacci Series // should ask the user how hight to go in the series
	4 Display Pascal's Triangle // should ask how far down to draw the triangle
	5 Sort Data in a file // must use any sort other that a Bubble Sort
*/

#include<iostream>

using namespace std;

void powerOf(double&, int&);
void reduceFraction(int&, int&);
void fibonacciSeries(int);
void pascalsTri(int); // NOT FINISHED!!
void sortData(); // Not started

int main() {

	
	double number = 2.6;
	int exponent = 3;
	
	int numerator = 48;
	int denominator = 14;
	
	cout << "power of :" << endl;
	powerOf(number, exponent);
	
	cout << "reduce fraction :" << endl;
	reduceFraction(numerator, denominator);	
	
	
	cout << "fibonacci :" << endl;
	fibonacciSeries(99);
		
	cout << "pascals :" << endl;
	pascalsTri(10);
	
	return 0;
}

void powerOf(double& number, int& exponent) {
	cout << number << "^" << exponent << " = ";
	double answer = number;
	for(exponent; exponent > 1; exponent--) {
		number*=answer;
	}	
	cout << number << endl;;	
}

void reduceFraction(int& numerator, int& denominator) {	
	if(denominator == 0) {
		cout << "ERROR" << endl;
	}else{
		if(numerator % denominator == 0) {
			cout << numerator / denominator << endl;
		}else {
			for(int i = 10; i > 1; i--) {
				if( (numerator % i ==0 ) && (denominator % i== 0) ) {
					numerator = numerator/i;
					denominator = denominator/i;
				}
			}
			cout << numerator << " / " << denominator << endl;
		}
	}	
}

void fibonacciSeries(int maxFib) {
	int numA = 1, numB = 1;
	int numAB;
	cout << numA << endl;
	cout << numB << endl;
	while( (numA < maxFib) && (numB < maxFib) ) {
		numAB = numA + numB;		
		cout << numAB << endl;
		
		numA = numB;
		numB = numAB;
	}	
}


void pascalsTri(int rows) {
	int twoDTri[rows][rows];

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows; j++) {
			twoDTri[i][j] = 1;
		}
	}
	
	for(int i = 1; i < rows; i++) {
		for(int j = 1; j < rows; j++) {
			twoDTri[i][j] = twoDTri[i-1][j] + twoDTri[i][j-1];
		}
	}

	for(int i = 0; i < rows; i++) {
		for(int j = 0; j < rows-i; j++) {
			cout << twoDTri[i][j] << "\t";
		}
		cout << "\n";
	}

}





