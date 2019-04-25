#ifndef PERSION_H
#define PERSION_H

//你的代码写在这里
#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    int age;
    string name;
    Person();
    Person(int age, string name);
    void toString();
};

#endif