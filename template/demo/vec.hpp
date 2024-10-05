#include <iostream>
using namespace std;
#include "vec.h"

// 如果vec内的内容是结构，该结构必须是可拷贝的
// 如果装teacher， teacher必须实现 拷贝 等于 左移

template <typename T>
MyVec<T>::MyVec(int size ) {
  m_space = new T[size];
  m_len = size;
}

template <typename T>
MyVec<T>::MyVec(const MyVec<T> &obj) {
  m_len = obj.m_len;
  m_space = new T[obj.m_len];

  // 拷贝数据
  for( int i=0; i<obj.m_len; i++) {
      m_space[i] = obj.m_space[i];
  }
}

template <typename T>
MyVec<T>::~MyVec(){
  if (m_space != NULL) {
      delete [] m_space;
      m_space = NULL;
      m_len = 0;
  }
}

template <typename T>
ostream & operator<< (ostream &out, const MyVec<T> &obj) {
  for (int i=0; i<obj.m_len; i++) {
	out << obj.m_space[i] << " ";
  }
  out << endl;
  return out;
}

template <typename T>
T& MyVec<T>::operator[] (int index){
  return m_space[index];
}

template <typename T>
MyVec<T> & MyVec<T>::operator= (const MyVec<T> &obj){
  if (m_space != NULL) {
      delete [] m_space;
      m_space = NULL;
      m_len = 0;
  }
  // 根据 obj 分配内存
  m_space = new T[obj.m_len];
  m_len = obj.m_len;

  // 拷贝
  for (int i=0; i<obj.m_len; i++) {
      m_space[i] = obj[i];
  }
  return *this;
}
	
