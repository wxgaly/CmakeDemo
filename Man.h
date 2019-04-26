#ifndef MAN_H
#define MAN_H

//继承
#include "Person.h"

class Man : Person
{
public:
    int sex;
    Man();
    Man(int age, string name, int sex);
    ~Man();
    void toString();
};

#endif
