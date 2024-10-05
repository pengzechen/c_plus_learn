#include <iostream>
using namespace std;

class A {

	public:
		A() {
			cout << "constructor do" << endl;
		}

		~A() {
			cout << "deconstructor do" << endl;
		}
};


// 异常接口声明
void divide() throw(int, char) {
	A a1, a2;
	cout << "divide 要发生异常了" << endl;
	throw 1;
}

int main() {

	try {
		divide();
	} catch (int e) {
		cout << "int error" << endl;
	} catch (...) {
		cout << "unknown" << endl;
	}	
	return 0;
}
