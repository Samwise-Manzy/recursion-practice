#include <iostream>

using namespace std;

double pow(double x, int y) 
{
	double product = 1;
	if ( y == 0) {					// base case
		return 1;
	} else if (y > 0){				// for positive exponents
		return x * pow(x, y-1);
	} else {						//enters if negative exponent
		y *= -1;
		return 1/(x * pow(x, y-1));
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
	else
		cout << pow(x,y) << endl;
		
		
	return 0;
}

