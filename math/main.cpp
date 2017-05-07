/*
	1 Raise a number to a power
	2 Reduce a fraction // ust use two pass by reference parameters
	3 Show the Fibonacci Series // should ask the user how hight to go in the series
	4 Display Pascal's Triangle // should ask how far down to draw the triangle
	5 Sort Data in a file // must use any sort other that a Bubble Sort
*/

#include<iostream>

using namespace std;

int menu();
void factorial(int&);
void powerOf(double&, int&);
void reduceFraction(int&, int&);
void fibonacciSeries(int);
void pascalsTri(int&);
void insertionSort(int, int*);

int main() {
	int choice;

	choice = menu();
	while(choice != 7) {
		switch(choice) {
			
			case 1:
				int num;
				cout << "\nFactorial: " << endl;
				cout << "\n!n = ";
				cin >> num;				
				
				factorial(num);
				choice = 0;
				break;
			
			case 2:
				double number;
				int exponent;
				cout << "\nPower of :" << endl;
				cout << "\nNumber = ";
				cin >> number;
				cout << "Exponent = ";
				cin >> exponent;
			
				powerOf(number, exponent);
				choice = 0;
				break;
			
			case 3:
				int numerator;
				int denominator;
				cout << " Reduce fraction :" << endl;
				cout << "\nNumberator = ";
				cin >> numerator;
				cout << "Denominator = ";
				cin >> denominator;				
				
				reduceFraction(numerator, denominator);	
				choice = 0;
				break;
			
			case 4:
				int fib;
				cout << "Fibonacci :" << endl;
				cout << "\nMax = ";
				cin >> fib;
				
				fibonacciSeries(fib);
				choice = 0;
				break;
			
			case 5:
				int rows;
				cout << "Pascal's Triangle:" << endl;
				cout << "\nTriangle hight = ";
				cin >> rows;
				
				pascalsTri(rows);
				choice = 0;
				break;
			
			case 6:
				int len;
				int arr[100];
				cout << " Insertion Sort:" << endl;
				cout << "\nAmout of Data(100max) = ";
				cin >> len;
											
				for(int i = 0; i < len; i++) {
					cout << "\nItem " << i+1 << " = ";
					cin >> arr[i];					
				}		
						
				insertionSort(len, arr);
				choice = 0;
				break;
			
			case 7:
				break;
				
			default:
				choice = menu();
				break;
		}
	}	
	return 0;
}

int menu() {
	int choice;
	cout << "Math Functions" << endl
		<< "____________________" << endl
		<< "(1) Factorial" << endl
		<< "(2) Power" << endl
		<< "(3) Reduce Fraction" << endl
		<< "(4) Fibonacci" << endl
		<< "(5) Pascal's Triangle" << endl
		<< "(6) Sort Data" << endl
		<< "(7) QUIT\n>> ";
	cin >> choice;
	
	return choice;
}

void factorial(int& num) {
	long long fact = num;
	while(num > 1) {
		fact *= --num;
	}
	cout << fact << endl;
	
	cout << "\n--------------------" << endl;
}

void powerOf(double& number, int& exponent) {
	cout << number << "^" << exponent << " = ";
	double answer = number;
	for(exponent; exponent > 1; exponent--) {
		number*=answer;
	}	
	cout << number << endl;;	
	
	cout << "\n--------------------" << endl;
}

void reduceFraction(int& numerator, int& denominator) {	
	if(denominator == 0) {
		cout << " -ERROR-" << endl;
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
	
	cout << "\n--------------------" << endl;
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
	
	cout << "\n--------------------" << endl;
}

void pascalsTri(int& rows) {	
	for (int i = 0; i < rows; i++) {
        int val = 1;
        for (int j = 1; j < (rows - i); j++) {
            cout << "\t";
        }
        for (int k = 0; k <= i; k++) {
            cout << "\t\t" << val;
            val = val * (i - k) / (k + 1);
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "\n--------------------" << endl;
}

void insertionSort(int len, int *arr) {
	
	int j, index;
	
	for(int i = 1; i < len; i++) {
		index = arr[i];
		j = i;
		
		while( (j > 0) && (arr[j-1] > index)) {
			arr[j] = arr[j-1];
			j = j - 1;
		}
		arr[j] = index;		
	}
	
	cout << " Sorted:" << endl;
	for(int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
}
