
/*Multimap

//1个key值可以对应多个valude =>分组

公司有销售部 sale (员工2)、术研发部 development (1人)、财务部 Financial (2人)
//人员信息有:姓名，年龄，电话、工资等组成
//通过 multimap进行信息的插入、保存、显示 + 分部门显示员工信息
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Person {
    public:
    string name;
    int age;
    string tel;
    double saly;

};

void main1() {
    Person p1, p2, p3, p4, p5;
    p1.name = "111";
    p1.age = 31;

    p2.name = "2222";
    p2.age = 32;

    p3.name = "3333";
    p3.age = 33;

    p4.name = "444";
    p4.age = 34;

    p5.name = "55";
    p5.age = 35;

    multimap<string, Person> map2;

    // sale 部门
    map2.insert(make_pair("sale", p1));
    map2.insert(make_pair("sale", p2));

    // dev 部门
    map2.insert(make_pair("dev", p3));
    map2.insert(make_pair("dev", p4));

    // financial 部门
    map2.insert(make_pair("financial", p5));
    
    for (multimap<string, Person>::iterator it=map2.begin(); it!=map2.end(); it++) {
        cout << it->first << "\t" << it->second.name << endl;
    }
    cout << "iterator end" << endl;

    // 按部门显示 显示dev部门的全部人员
    int dev_cnt = map2.count("dev");
    cout << "dev person num: " << dev_cnt << endl;
    multimap<string, Person>::iterator it2;
    it2 = map2.find("dev");

    int tag = 0;
    while(it2 != map2.end() && tag < dev_cnt)
    {
        cout << it2->first << "\t" << it2->second.name << endl;
        it2++;
        tag ++;
    }

}

void main2() {
    Person p1, p2, p3, p4, p5;
    p1.name = "111";
    p1.age = 31;
    p2.name = "2222";
    p2.age = 32;
    p3.name = "3333";
    p3.age = 33;
    p4.name = "444";
    p4.age = 34;
    p5.name = "55";
    p5.age = 35;
    multimap<string, Person> map2;

    // sale 部门
    map2.insert(make_pair("sale", p1));
    map2.insert(make_pair("sale", p2));

    // dev 部门
    map2.insert(make_pair("dev", p3));
    map2.insert(make_pair("dev", p4));

    // financial 部门
    map2.insert(make_pair("financial", p5));

    for (multimap<string, Person>::iterator it=map2.begin(); it!=map2.end(); it++) {
        cout << it->first << "\t" << it->second.name << endl;

        if (it->second.age == 32) {
            it->second.name = "name2";
        }
    }

    for (multimap<string, Person>::iterator it=map2.begin(); it!=map2.end(); it++) {
        cout << it->first << "\t" << it->second.name << endl;
    }
    cout << "iterator end" << endl;
}

int main() {
    // main1();
    main2();
    return 0;
}