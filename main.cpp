#include <iostream>
#include "Person.h"

int main(int, char**) {
    int a = 2;
    int b = 3;
    
    Person person;
    person.age = 100;
    person.name = "wangxuguang";
    person.toString();

    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "Hello, world!\n";
}
