#include <iostream>
using namespace std;

#include <string>
#include <algorithm>
/*
    1、string的初始化 
    2、遍历 
    3、char*和string的互相转换
    4、连接 查找 替换
    5、截断 区间删除 插入
    6、反转 大小写转换
*/

int main() {

    {
    string s1 = "hello";
    string s2("hello");
    string s3 = s2;   // 会调用拷贝构造函数

    cout << s1 << s2 << s3 << endl;
    }
    {
        string s1 = "abcdefg";
        for(int i=0; i<s1.length(); i++) {
            cout << s1[i] << " ";  // 和at比较不能抛出异常
        }
        cout << endl;
        for(string::iterator it=s1.begin(); it!=s1.end();it++) {
            cout << *it << " ";
        }
        cout << endl;

        for (int i=0; i<s1.length(); i++) {
            cout << s1.at(i) << " ";  // 可以抛出异常
        }
        cout << endl;
    }
    {
        // char * 和string 转换
        string s1 = "hello";
        printf("%s\n", s1.c_str());
        
        char buf[30] = {'\0'};
        s1.copy(buf, s1.length());
        cout << buf << endl;
    }
    {
        // 连接字符串
        string s1 = "hello";
        string s2 = " world";
        s1 = s1 + s2;
        cout << s1 << endl;

        string s3 = "3333";
        string s4 = "4444";
        s3.append(s4);
        cout << s3 << endl;
    }
    {
        // 字符串的查找和替换
        string s1 = "wbm hello wbm 111 wbm 222 wbm 333";

        int index = s1.find("wbm", 0);  // 没找到返回－1
        cout << "index: " << index << endl;

        // 查找字符串中有几个wbm
        int temp = 0;
        while ((index = s1.find("wbm", temp)) != string::npos){
            cout << index << endl;
            temp += index + 1;
        }
        // 替换
        int offindex = s1.find("wbm", 0);
        while (offindex != string::npos)
        {
            cout << "offindex: " << offindex << endl;
            s1.replace(offindex, 3, "WBM");
            offindex += 1;
            offindex = s1.find("wbm", offindex);
        }
        cout << "s1: " << s1 << endl;
        
    }
    {
        // 字符串的区间删除和插入
        string s1 = "hello hello1 hello3";
        string::iterator it = find(s1.begin(), s1.end(), 'l');
        if (it != s1.end()) {
            s1.erase(it);
        }
        cout << "s1 delete l: " << s1 << endl;

        s1.erase(s1.begin(), s1.end());
        cout << "s1 delete l: " << s1 << endl;

        string s2 = "bbb";
        s2.insert(0, "AAA");
        s2.insert(s2.length(), "CCC");
        cout << "s2: " << s2 << endl;
    }

    {
        // string 的一些算法
        string s1 = "AAAbbb";
        // transform(s1.begin(), s1.end(), s1.begin(), toupper);
        // toupper 是函数的入口地址

        cout << s1 << endl;
    }

    return 0;
}