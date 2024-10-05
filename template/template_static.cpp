#include <iostream>
using namespace std;

// set guifont=courier_new:h12

// MyComplex<int> c1, c2, c3;
// MyComplex<float> c4, c5, c6;
//
// static int m_a;

template <typename T>
class A {
public:
	static T m_a;
};

template <typename T>
T A<T>::m_a = 0;


int main() {
	A<int> a1, a2, a3;
	a1.m_a = 10;
	a2.m_a ++;
	a3.m_a ++;
	cout << A<int>::m_a << endl;

	A<char> b1, b2, b3;
	b1.m_a = 'A';
	b2.m_a ++;
	b3.m_a ++;
	cout << A<char>::m_a << endl;
	
	return 0;
}
