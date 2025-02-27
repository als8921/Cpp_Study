#include <iostream>
#include <cstring>
using namespace std;
class Person{
    private:
        int age;
        char * name;

    public:
        Person(const char * name, int age) : age(age)
        {
            this->name = new char[strlen(name) + 1];
            strcpy(this->name, name);
        }
        Person(Person &person) : age(person.age)
        {
            this->name = new char[strlen(person.name) + 1];
            strcpy(this->name, person.name);
        }

        ~Person()
        {
            delete []name;
            cout << "Destructer\n"; 
        }
};


int main()
{
    Person p1("assd", 12);
    Person p2 = p1;
}