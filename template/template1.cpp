#include <iostream>
using namespace std;

template <typename T>
void my_swap(T &a, T &b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}


template <typename Tsort>
int mySort(Tsort *myarray, int size) {
	int j = 0;
	int temp;
	for(int i=0; i<size; i++){
		for(j=i+1; j<size; j++) {
			if (myarray[i] < myarray[j]) {
				temp = myarray[i];
				myarray[i] = myarray[j];
				myarray[j] = temp;
			}
		}
	}
	return 0;
}


template <typename Tsort>
void myPrint(Tsort *myarray, int size) {
	for (int i=0; i<size; i++){
		cout << myarray[i] << " " ;
	}
	cout << endl;
}


int main() {
	{
		int a = 1;
		int b = 4;
		my_swap<int>(a, b);  // 显示类型调用
		//my_swap(a, b);     // 自动类型推导
		cout << "a: " << a << " b: "<< b << endl;
	}
	
	{
	
		int myarray[] = {2, 33, 44, 56, 66, 34};
		char myarray_char[] = {'s', 'd', 't', 'a', 'n'};
		
		int size = sizeof(myarray)/sizeof(*myarray);
		int size_char = sizeof(myarray_char)/sizeof(*myarray_char);
		
		cout << "before sort" << endl;
		myPrint(myarray, size);
		mySort(myarray, size);
		cout << "after sort" << endl;
		myPrint(myarray, size);
		
		cout << "before sort" << endl;
		myPrint(myarray_char, size_char);
		mySort(myarray_char, size_char);
		cout << "after sort" << endl;
		myPrint(myarray_char, size_char);
	
	}
	
	return 0;
}