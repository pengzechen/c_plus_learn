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


// �쳣�ӿ�����
void divide() throw(int, char) {
	A a1, a2;
	cout << "divide Ҫ�����쳣��" << endl;
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
