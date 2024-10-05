#include <iostream>
using namespace std;
#include "vec.hpp"

int main() {
	MyVec<int> myval(10);
	for (int i=0; i<myval.GetLength(); i++) {
		myval[i] = i+1;
		cout << myval[i] << " ";
	}
	cout << endl;
	
	
	MyVec<int> myval2 = myval;
	for (int i=0; i<myval2.GetLength(); i++) {
		cout << myval2[i] << " ";
	}
	cout << endl;
	
	
	cout << myval2 << endl;
	return 0;
}