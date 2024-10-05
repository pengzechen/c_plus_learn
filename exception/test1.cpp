#include <iostream>

using namespace std;

// 0.基本语法
// 1.跨函数
// 2.网上抛，不处理
// 3. 严格按照类型匹配

void divide(int x, int y) {
	
	if (y == 0) {
		// 抛出 int 异常
		// return 后面的不执行
		throw x;
	}
	cout << "div 结果" << x/y << endl;
	
}

void MyDivide(int x, int y) 
{
	try{
					divide(x, y);
	}catch (...) {
					// 不想处理异常时可以往上抛出
		      throw;
	}
}

int main() {
	try {
		MyDivide(10, 2);
		MyDivide(100, 0);
	} catch (int e) {
		cout << e << "div by 0" << endl;	
	} catch (...) {
		cout << "unknown error" << endl;
	};
	return 0;
}
