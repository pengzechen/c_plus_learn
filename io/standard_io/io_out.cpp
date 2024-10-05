#include <iostream>
using namespace std;

// c++ 格式化输出

int main() {
	cout << "<start>" ;
	cout.width(30);
	cout.fill('*');
	cout.setf(ios::showbase);
	cout.setf(ios::internal);
	cout << hex << 123 << "<end>" << endl;
	
	return 0;
}