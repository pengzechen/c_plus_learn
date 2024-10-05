#include <iostream>
using namespace std;

#include <algorithm>
#include <deque>
#include <stack>
#include <queue>
#include <list>



void print(deque<int> &d1) {

    for (deque<int>::iterator it=d1.begin(); 
        it != d1.end(); it++) {
            std::cout << *it << " ";
        }
    std::cout << endl;
}

void main1() {
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_front(-11);
    d1.push_front(-12);
    d1.push_front(-13);

    print(d1);

    deque<int>::iterator it = find(d1.begin(), d1.end(), -13);
    if (it != d1.end()) {
        std::cout << distance(d1.begin(), it) << endl;
    }
}

void main2() {
    stack<int> s1;
    s1.push(1);
    s1.push(11);
    cout << "stack size: " << s1.size() << endl;
    while (!s1.empty())
    {
        int tmp = s1.top();
        cout << tmp << endl;
        s1.pop();
    }
}

void main3() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "queue size: " << q.size() << endl;
    cout << "queue head: " << q.front() << endl;

    while(!q.empty()) {
        int tmp = q.front();
        cout << tmp << " ";
        q.pop();
    }
}

void main4() {
    /*  1、list迭代器 ++ -- 不可以+3
        2、list节点序号从 0 开始
        3、list插入元素 3 号位置插入元素
        4、list删除操作 [0, 3) 
        5、删除3号位置元素， 意思解读
    */
   // list 基本操作

    list<int> li;
    for (int i=0; i<10; i++) {
        li.push_back(i);
    }
    cout << "list size: " << li.size() << endl;

    list<int>::iterator it = li.begin();
    while (it != li.end())
    {
        cout << * it << " ";
        it ++;
    }

    // list 不能随机访问
    
    it = li.begin();
    it++;
    it++;
    it++;
    li.insert(it, 100);
    // ！！在3号位置插入， 让原来的3变为4
    
    it = li.begin();
    while (it != li.end())
    {
        cout << * it << " ";
        it ++;
    }

    list<int>::iterator it3 = li.begin();
    it3++;
    it3++;
    li.erase(li.begin(), it3);  // 左闭右开
    li.remove(100);

    it = li.begin();
    while (it != li.end())
    {
        cout << * it << " ";
        it ++;
    }
}

void main5() {

    priority_queue<int> p1;
    // 默认是 最大值优先队列
    priority_queue<int, vector<int>, /*less*/greater<int>> p2;
    p1.push(3);
    p1.push(45);
    p1.push(23);
    p1.push(12);

    cout << "head: " << p1.top() << " size: " << p1.size() << endl;
    while (p1.size() > 0)
    {
        cout << p1.top() << " ";
        p1.pop();
    }

    

}


int main() {
    //main1();
    //main2();
    //main3();
    //main4();
    main5();
    return 0;
}