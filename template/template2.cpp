#include <iostream>
using namespace std;

template <typename T>
class Person {
public :
	Person(T a) {
		this->a = a ;
	}
public :
	void printPerson() {
		cout << "a: " << this->a << endl;
	}
private :
	
	T a;
};

class Student: public Person<int> {
public: 
	Student(int a):Person<int>(a){
		this->b = a;
	}
private:
	int b;
};

template <typename T>
class Teacher: public Person<T> {
public:
	Teacher(T c, T a): Person<T>(a) {
		this->c = c;
	}
private:
	int c;
};


// 类模板做函数参数
void usePersion(Person<double> &p) {
	p.printPerson();
}

int main() {
	// {
		// Person<double> a(10.99);
		// a.printPerson();
		// usePersion(a);
	// }
	
	// {
		// Student stu(2);
		// stu.printPerson();
	// }
	
	Teacher<int> tea(3, 9);
	tea.printPerson();
	return 0;
}