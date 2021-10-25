#include <iostream>
////***** Uncomment the following #include to support later code for a comparison 
////***** of the two functions --- pow() v.s. improvedPow().
////***** In Linux, e.g., (zeus.cs.txstate.edu), you might need the option "-std=c++11"
////***** to make it compile by g++, as chrono might not be supported in earlier standard.
////***** For example, $ g++ -std=c++11 improvedPow.cpp -o a
#include <chrono>

using namespace std;

////***** In order to do the *optional* runtime comparison,
////***** copy the double pow(double x, int y)
////***** you implemented in pow.cpp
////***** to replace the following commented code block.
////***** See the comments in main(), try to compare
////***** the running time of your pow() and improvedPow().

double pow(double x, int y) 
{
	double product = 1;
	if ( y == 0) {
		return 1;
	} else if (y > 0){
		return x * pow(x, y-1);
	} else {
		y *= -1;
		return 1/(x * pow(x, y-1));
	}
}

double improvedPow(double x, int y)
{
	double temp;
	if (y == 1) {							// base case
		return x;
	} else if (y > 0) {						// for positive exponents
		if (y%2 == 0) {						// determines if even/odd exponent
			temp = improvedPow(x, y/2);		// decroments by y/2 for each recursion
			return temp * temp;
		} else {							// for odd exponents
			y -= 1;
			temp = improvedPow(x, y/2);
			return temp * temp * x;
		}
	} else if (y < 0) {						// enters for negative exponents
		y *= -1;
		return 1/improvedPow(x, y);
	} else {								// for exponent 0
		return 1;
	}
}


int main() 
{
	cout << "To calculate x^y ..." << endl;
	
	double x;
	int y;
	cout << "Please enter x: ";
	cin >> x;
	cout << "Please enter y: ";
	cin >> y;
	
	if(x == 0) {
		if (y > 0)
			cout << 0 << endl;
		else
			cout << "x^y is not defined" <<endl;
	}
	else {
		cout << improvedPow(x,y) << endl;
	

////***** Uncomment the following code block to get some sense about the running time 
////***** of the two functions --- pow() v.s. improvedPow().
////***** In Linux, e.g., (zeus.cs.txstate.edu), you might need the option "-std=c++11"
////***** to make it compile by g++, as chrono might not be supported in earlier standard.
////***** For example, $ g++ -std=c++11 improvedPow.cpp -o a

		cout << "To get this result..." << endl;
		
		chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();
		pow(x,y);
		chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::nanoseconds>( t2 - t1 ).count();
		cout << "pow(x,y) would take time: " << duration << " ns" << endl;
		
		t1 = chrono::high_resolution_clock::now();
		improvedPow(x,y);
		t2 = chrono::high_resolution_clock::now();
		duration = chrono::duration_cast<chrono::nanoseconds>( t2 - t1 ).count();
		cout << "improvedPow(x,y) would take time: " << duration << " ns" << endl;
	}		
		
	return 0;
}


