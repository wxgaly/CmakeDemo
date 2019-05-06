#include "Man.h"

Man::Man(int age, string name, int sex1) : Person(age, name)
{
    sex = sex1;
}

Man::~Man()
{
    cout << "man " << name << " delete" << endl;
}

void Man::toString()
{
    Person::toString();
    cout << "sex is " << sex << endl;
}