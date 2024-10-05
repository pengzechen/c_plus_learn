#include <iostream>
using namespace std;

class Tree {
};

class Animal {
	public: 
		virtual int cry() = 0;
};

class Cat:public Animal {
	public:
		virtual int cry() {
			cout << "Cat cry" << endl;
		}
		void CatRun() {
			cout << "Cat run" << endl;
		}
};

class Dog:public Animal {
	public:
		virtual int cry() {
			cout << "Dog cry" << endl;
		}
		void DogRun() {
			cout << "Dog run" << endl;
		}
};

void docry(Animal *base) {
	// 1.继承 2.父类指针指向子类对象 3.子类重写父类虚函数 => 多态
	base->cry();

	// dynamic_cast 在父类和子类继承中使用
	// 程序运行时动态判断
	Dog * pDog = dynamic_cast<Dog*>(base);
	if(pDog != NULL)
					pDog->DogRun();
	Cat * pCat = dynamic_cast<Cat*>(base);
	if(pCat != NULL)
					pCat->CatRun();

}

void printBuf(const char * p) {
	// p[0]= 'z';  此操作不允许
	char * p1 = NULL;
	p1 = const_cast<char*>(p);
	p1[0] = 'Z';
	cout << p << endl;
}

int main() {
		double pi = 3.1415;
		{
			int num1 = (int)pi;
			cout << "(int)pi: " << num1 << endl;
			// ????????????????????
			int num2 = static_cast<int>(pi);
			cout << "static_cast<int>(pi>: " << num2 << endl;
			char *p1 = "hello";
			int *p2 = NULL;
			// p2 = static_cast<char*>(p1);	
		}

		{
			char *p1 = "hello";
			int *p2 = NULL;
			// ??????????
			p2 = reinterpret_cast<int*>(p1);
			cout << p1 << endl;
			cout << p2 << endl;
		}
		
		{
			Dog d1;
			Cat c1;

			Animal *pBase = NULL;
			pBase = &d1;  // 父类指针指向子类对象
			pBase->cry();
			
			docry(&d1);
			docry(&c1);

		}

		{
			// const 
			// ?????????const????
			char buf[] = "aaaaafsdfsdf";
			char * buf2 = "sadsfasdklfjl";
			printBuf(buf);
		
		}

		cout << "This is end...." << endl;
		
		return 0;
}
