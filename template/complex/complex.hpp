#include <iostream>
#include "complex.h"
using namespace std;

template <typename T>
Complex<T>::Complex(T a, T b) {
	this->a = a;
	this->b = b;
}

template <typename T>
Complex<T> Complex<T>::operator+(Complex<T> &c2) {
	Complex tmp(a+c2.a, b+c2.b);
	return tmp;
}

template <typename T>
void Complex<T>::printCom() {
	cout << "a: " << a << " b: " << b << endl;	
}


template <typename T>
ostream & operator<< (ostream &out, Complex<T> &c3) {
	cout << c3.a << " + " << c3.b << "i" << endl;
	return out;
}



