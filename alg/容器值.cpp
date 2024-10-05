#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class Teacher {
    public:
        Teacher (char * name, int age) {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
            this->age = age;
        }
        Teacher (const Teacher &obj) {
            this->name = new char[strlen(obj.name) + 1];
            strcpy(this->name, obj.name);
            this->age = obj.age;
        }
        Teacher & operator= (const Teacher &obj) {
            // free old mem
            if (this->name != NULL)
                {
                    delete[] this->name;
                    this->name = NULL;
                    this->age = 0;
                }

            this->name = new char[strlen(obj.name) + 1];
            strcpy(this->name, obj.name);
            this->age = obj.age;
            return *this;
        }
        ~Teacher() {
            if (this->name != NULL)
            {
                delete[] this->name;
                this->name = NULL;
                this->age = 0;
            }
        }
        void printT() {
            std::cout << this->name << this->age << endl;
        }
    private:
        char * name;
        int age;

};

int main() {
    
    Teacher t1("t1", 31);
    vector<Teacher> v1;
    v1.push_back(t1);

    std::cout << "running this line!" << endl;
    return 0;
}