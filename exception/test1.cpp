#include <iostream>

using namespace std;

// 0.�����﷨
// 1.�纯��
// 2.�����ף�������
// 3. �ϸ�������ƥ��

void divide(int x, int y) {
	
	if (y == 0) {
		// �׳� int �쳣
		// return ����Ĳ�ִ��
		throw x;
	}
	cout << "div ���" << x/y << endl;
	
}

void MyDivide(int x, int y) 
{
	try{
					divide(x, y);
	}catch (...) {
					// ���봦���쳣ʱ���������׳�
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
