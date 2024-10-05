#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;
template <typename T>
class show_elemet_t {
    public:
    void operator() (T &t) {
        std::cout << t << endl;
    }
};

// 普通函数
void print(int a) {
    std::cout << a << endl;
}

// 函数模板 
template <typename T>
void printT(T &t) {
    std::cout << t << endl;
}


// 函数对象的调用很像一个函数
void main1() {
    int a = 10;
    show_elemet_t<int> s;
    s(a);
}

// 函数对象属于类对象，突破了函数的概念，能保持调用状态信息
void main2() {
    vector <int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    // 匿名函数对象，匿名仿函数
    for_each(v1.begin(), v1.end(), show_elemet_t<int>());
    // 通过回调函数
    for_each(v1.begin(), v1.end(), print);

}

int main() {
    main2();
    return 0;
}