#include "Person.h"

Person::Person()
{
    cout << "person init" << endl;
}

Person::Person(int age1, string name1)
{
    age = age1;
    name = name1;
}

void Person::toString()
{
    cout << "name is " << name << endl;
    cout << "age is " << age << endl;
}
