#include <iostream>
using namespace std;

int main() {
	{
		// int i;
		// long l;
		// char buf[1024];
		
		// cin >> i;
		// cin >> l;
		// cin >> buf;  // 不接受空格
		// cout << i << l << buf << endl;
	}
	{
		// char ch;  // EOF  ctl z
		// while((ch=cin.get()) != EOF) {
			// cout << ch << endl;
		// }
	}
	{
		// char a, b, c;
		// cin.get(a);
		// cin.get(b);
		// cin.get(c);
		
		// cout << a << b << c << endl;
		// cin.get(a).get(b).get(c);
		// cout << a << b << c << endl;
	}
	{
		// char buf1[256] = {0};
		// char buf2[256] = {0};
		
		// cout << "输入一个含有多个空格的字符串" << endl;
		
		// cin >> buf1;
		// cin.getline(buf2, 256);
		
		// cout << buf1 << endl;
		// cout << buf2 << endl;
	}
	
	{
		// ignore peek putback
		cin.peek();  //查看有无数据 
		char c;
		cin.get(c);
		cin.putback(c);
	}
	
	return 0;
}