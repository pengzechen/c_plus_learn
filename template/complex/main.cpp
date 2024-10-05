#include <iostream>
using namespace std;

#include "complex.hpp"

int main() {
	
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;

	cout << c3 << endl;
	// ostream & operator<< (ostream &out, Complex &c3) ;
	
	cout << "this is complex single ... " << endl;
	return 0;
}