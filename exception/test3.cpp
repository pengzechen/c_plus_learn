#include <iostream>
using namespace std;

int my_strcpy1(char * to, char * from) {
	if(from == NULL){
		return 1;
	}
	if(to == NULL){
		return 2;
	}
	
	if(*from == 'a'){
		return 3;
	}
	while(*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	
	return 0;
}

int main1() {

	int ret = 0;
	char buf[20] = "sdfs";
	char buf2[100] = {0};
	
	ret = my_strcpy1(buf2, buf);
	if (ret != 0) {
		switch(ret){
			case 1:
			cout << "原出错" << endl;
			break;
			case 2:
			cout << "目标出错" << endl;
			break;
			case 3:
			cout << "拷贝过程出错" << endl;
			break;
			default:
			cout << "unknown" << endl;
		}
	}
	
	cout << buf2 << endl;
	return 0;
}


class BadSrcType{};
class BadDestType{};
class BadCheckType{
	public:
	BadCheckType() {  cout << "new" << endl; }
	BadCheckType(const BadCheckType & obj) {  cout << "copy new" << endl; }
	~BadCheckType() {  cout << "delete" << endl; }
};



void my_strcpy(char * to, char * from) {
	if(from == NULL){
		throw BadSrcType();
	}
	if(to == NULL){
		throw BadDestType();
	}
	
	if(*from == 'a'){
		throw BadCheckType();
	}
	while(*from != '\0') {
		*to = *from;
		to++;
		from++;
	}
	*to = '\0';
	
}

int main() {

	char buf[20] = "asdfs";
	char buf2[100] = {0};
	
	try{
		my_strcpy(buf2, buf);
	}catch(int e){
		cout << "int error" << endl;
		switch(e){
			case 1:
			cout << "from" << endl;
			break;
			case 2:
			cout << "to" << endl;
			break;
			case 3:
			cout << "check" << endl;
			break;
			default:
			cout << "unknown" << endl;
		}
	
	// -----------------------
	}catch(const char* e){
		cout << "char* error" << endl;
		cout << e << endl;
	
	// ------------------------
	}catch(BadSrcType &e){
		cout << "BadSrcType error" << endl;

	}catch(BadDestType &e){
		cout << "BadDestType error" << endl;

	}catch(BadCheckType &e){  //e 是拷贝过来的,若使用 &e 不是拷贝的， 指针用new delete
		cout << "BadCheckType error" << endl;
	// ---------------结论用 引用----------------
		
		
	}catch(...){
		cout << "unknown" << endl;
	}
	
	cout << buf2 << endl;
	return 0;
}