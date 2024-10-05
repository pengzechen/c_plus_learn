#include <iostream>
using namespace std;
#include <exception>

class MyException : public exception {
	public:
		MyException(const char * p) {
			this->m_p = p;
		}
		virtual const char * what() {
			cout << "MyException exception" << endl;
			return m_p;
		}
	private:
		const char * m_p;
};

void test(){
	throw MyException("test exception");
}

int main() {
	try{
		test();
	}catch(MyException &e){
		e.what();
	}catch(...){
		cout << "unknown exception" << endl;
	}
	return 0;
}
