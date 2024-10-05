#include <iostream>
using namespace std;
#include <set>
#include <string.h>

/*
    59 60 61 62

    1、能比较大小的set集合
        基于数据类型的计较
        自定义数据类型的比较 --> 仿函数 函数对象
    2、set的查找和pair
    
*/

class Student {
    public:
    Student(const char* _name, int _age) {
        strcpy(this->name, _name);
        this->age = _age;
    }
    private:
    char name[64];
    public:
    int  age;
};

void main1() {
    /*
        1、集合元素唯一 自动排序 不能使用 at []
        2、红黑树
    */

    set<int> set1;
    set<int, greater<int>> set2;
    for (int i=0; i<5; i++) {
        int tmp = rand();
        set1.insert(tmp);

    }

    set1.insert(10);
    set1.insert(10);
    set1.insert(10);

    for(set<int>::iterator it=set1.begin(); it!=set1.end(); it++)
        cout << *it << endl;

    // 删除
    while (!set1.empty())
    {
        set<int>::iterator it = set1.begin();
        cout << *it << " ";
        set1.erase(set1.begin());
    }
    
}

struct FuncStudent{
    bool operator() (const Student &left, 
        const Student &right) {
        
        if (left.age < right.age) {
            return true;
        }else{
            return false;
        }
    }
};

void main2() {
    set<Student, FuncStudent> set1;
    Student s1("s1", 12);
    Student s2("s44", 44);
    Student s3("s16", 16);
    Student s4("s19", 19);
    set1.insert(s1);
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);

    for(set<Student, FuncStudent>::iterator it = set1.begin();
        it != set1.end(); it++)
        {
            cout << it->age << endl;
        }
    
    pair<set<Student, FuncStudent>::iterator, bool> pair4 = set1.insert(s4);
    if(pair4.second) {
        cout << "insert ok" << endl;
    }else{
        cout << "insert wrong" << endl;
    }
}

void main3() {
    /*
        set.find(elem);         //查找elem 元素，返回指向 elem 元素的迭代器。
        set.count(elem);        //返回容器中值为 elem 的元素个数。对 set 来说，要么是0，要么是1。对multiset来说，值可能大于1。
        set.lower_bound(elem);  //返回第一个>=elem 元素的迭代器
        set.upper_bound(elem);  // 返回第一个>elem 元素的迭代器。
        set.equal_rangelelem);  //返回容器中与 elem 相等的上下限的两个送代器。上限是闭区间，下限是开区间，如[beg;end)。
        以上函数返回两个选代器，而这两个迭代器被封装在 pair 中。以下讲解 pair 的合义与使用方法。
    
        set.clear();  delete all
        set.erase(pos);  删除pos迭代器所指元素，返回下一个元素的迭代器。
        set.erase(beg, end);
        set.erase(elem);
    
    */
    set<int> set1;
    for (int i=0; i<10; i++)
        set1.insert(i+1);
    for (set<int>::iterator it=set1.begin(); it!=set1.end(); it++)
        cout << *it << " ";
    cout << endl;

    set<int>::iterator it0 = set1.find(5);
    cout << *it0 << endl;

    set<int>::iterator it1 = set1.lower_bound(8); // 大于等于5的迭代器的位置
    cout << *it1 << endl;

    // 区间
    pair< set<int>::iterator, set<int>::iterator > mypair = set1.equal_range(5);
    cout << *mypair.first << *mypair.second << endl;

}

void main4() {
    multiset<int> m1;
    m1.insert(12);
    m1.insert(14);
    m1.insert(14);
    m1.insert(14);
    for (multiset<int>::iterator it = m1.begin(); it!=m1.end(); it++)
        cout << * it << endl;
}

int main() {
    // main1();
    // main2();
    // main3();
    main4();
    return 0;
}