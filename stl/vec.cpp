#include <iostream>
using namespace std;

/*
    1、数组的尾部添加和弹出元素
    2、通过数组的方式访问vector
    3、vector迭代器
       输出迭代、输入迭代、正向迭代、双向迭代
    4、删除
       区间删除、指定元素删除、指定位置删除
*/
#include <vector>

int main() {
    vector<int> v1;
    cout<< v1.size() << endl;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout<< v1.size() << endl;


    cout << v1.front();
    v1.front() = 11;  // 函数返回值当左值 应该返回一个引用
    
    while(v1.size() != 0) {
        cout << "tail: " << v1.back() << endl;
        v1.pop_back();  // 删除尾部元素
    }

    {
        // vector 初始化
        vector<int> v1;
        v1.push_back(1);
        v1.push_back(2);
        v1.push_back(3);

        vector<int> v2 = v1;
        vector<int> v3(v1.begin(), v1.end());        
    }
    {
        // vector 遍历
        vector<int> v1(10);
        for (int i=0; i<10; i++)
            v1[i] = i+1;
        for (int i=0; i<10; i++)
            cout << v1[i] << endl;

    }
    {
        // 迭代器
        vector<int> v1(10);
        for (int i=0; i<10; i++) 
            v1[i] = i+10;
        
        for (vector<int>::iterator it=v1.begin(); 
            it!=v1.end(); it++){  // end 指向最后 以后一个
            cout << *it << endl;
        }
        // 逆序遍历
        for (vector<int>::reverse_iterator it=v1.rbegin();
            it!=v1.rend(); it ++)
            cout << *it << endl;
    }

    {
        // vector 删除
        vector<int> v1(10);
        for (int i=0; i<10; i++) 
            v1[i] = i+100;

        v1.erase(v1.begin(), v1.begin() + 3);
        for (vector<int>::iterator it=v1.begin(); 
            it!=v1.end(); it++){  // end 指向最后 以后一个
            cout << *it << endl;
        }

        for (vector<int>::iterator it = v1.begin();
            it!=v1.end(); ) {

                if (*it == 109)
                    it = v1.erase(it);
                else
                    it++;
        }

        for (vector<int>::iterator it=v1.begin(); 
            it!=v1.end(); it++){  // end 指向最后 以后一个
            cout << *it << endl;
        }

    }
    return 0;
}