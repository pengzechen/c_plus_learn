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

