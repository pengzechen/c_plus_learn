#include <iostream>
using namespace std;

// 要进行类声明和函数声明
template <typename T>
class Complex;
template <typename T>
ostream & operator<< (ostream &out, Complex<T> &c3);


template <typename T>
class Complex {
				
	private:
		T a;
		T b;	
	public:
		Complex(T a, T b);
		void printCom();
		Complex operator+ (Complex &c2);
		
		//friend ostream & operator<<  (ostream &out, Complex<T> &c3);
		//注意 函数名称后面要写 <T>
		friend ostream & operator<< <T> (ostream &out, Complex &c3);

};

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






int main() {
	
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);

	Complex<int> c3 = c1 + c2;

	cout << c3 << endl;
	// ostream & operator<< (ostream &out, Complex &c3) ;
	
	cout << "this is complex single ... " << endl;
	return 0;
}
