#include <iostream>
using namespace std;

template <typename T>
class MyVec;
template <typename T>
ostream & operator<< (ostream &out, const MyVec<T> &obj);

template <typename T>
class MyVec {
	public:
		MyVec(int size);
		MyVec(const MyVec &obj);
		~MyVec();
	public:
		T& operator[] (int index);

		MyVec & operator= (const MyVec &obj);
		friend ostream & operator<< <T> (ostream &out, const MyVec &obj);

		int GetLength() {
			return this->m_len;
		}
	private:
		T *m_space;
		int m_len;
};
