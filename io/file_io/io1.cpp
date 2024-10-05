#include<iostream>
using namespace std;

#include <fstream>

int main() {
	
	{
		// 新建一个输出流
		ofstream fout("./2.txt");
		fout << "hello world" << endl;
		fout.close();
		
		
		ifstream fin("./2.txt");
		char ch;
		while((ch = fin.get()) != EOF){
			cout << ch;
		}
		fin.close();
	}
	
	return 0;
}