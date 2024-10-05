#include <iostream>
#include <map>
#include <string>
using namespace std;

void main1() {
// map 元素的添加、遍历、删除
    map<int, string> map1;
    map1.insert(pair<int, string>(1, "teacher01"));
    map1.insert(make_pair(2, "teacher02"));
    map1.insert(map<int, string>::value_type(3, "teacher03"));
    map1[4] = "teacher04";

    for (map<int, string>::iterator it=map1.begin(); it!=map1.end(); it++)
        cout << it->first << it->second << endl;
    
    while (map1.empty())
    {
        map<int, string>::iterator it = map1.begin();
        cout << it->first << it->second << endl;
        map1.erase(it);
    }
}

void main2() {
// 四种插入方法有哪些不同

    map<int, string> map1;
    pair< map<int, string>::iterator, bool > mypair1;

    mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
    if(mypair1.second){
        cout << "insert ok" << endl;
        cout << mypair1.first->first << mypair1.first->second << endl;
    }else{
        cout << "insert wrong" << endl;
    }
    mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
    if(mypair1.second){
        cout << "insert ok" << endl;
        cout << mypair1.first->first << mypair1.first->second << endl;
    }else{
        cout << "insert wrong" << endl;
    }

    map1.insert(make_pair(2, "teacher02"));
    map1.insert(map<int, string>::value_type(3, "teacher03"));
    map1[4] = "teacher04";
    map1[4] = "teacher44";

    for (map<int, string>::iterator it=map1.begin(); it!=map1.end(); it++)
        cout << it->first << it->second << endl;
}

void main3() {
    // 查找
    map<int, string> map1;
    map1.insert(pair<int, string>(1, "teacher01"));
    map1.insert(make_pair(4, "teacher02"));
    map1.insert(map<int, string>::value_type(3, "teacher03"));
    map1[4] = "teacher04";

    map<int, string>::iterator it;
    it = map1.find(100);
    if(it == map1.end()) {
        cout << "key=100 not exaist" << endl; 
    }

    map<int, string>::iterator it2;
    map<int, string>::iterator it3;
    pair<map<int, string>::iterator , map<int, string>::iterator> mypair;
    mypair = map1.equal_range(3);

    if(mypair.first == map1.end()) {
        cout << "pair first not exaist" << endl;
    }else{
        cout << mypair.first->first << mypair.first->second << endl;
    }

    if(mypair.second == map1.end()) {
        cout << "pair second not exaist" << endl;
    }else{
        cout << mypair.second->first << mypair.second->second << endl;
    }

}


int main() {

    // main1();
    // main2();
    main3();
    return 0;
}