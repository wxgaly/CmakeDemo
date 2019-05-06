#include <iostream>
#include "Person.h"
#include "Man.h"
// #include "file/FileUtil.h"
#include "Stack.h"

using namespace std;

int main(int, char **)
{
    // int a = 2;
    // int b = 3;

    Person person;
    person.age = 100;
    person.name = "wangxuguang";
    person.toString();

    // Person p1 = Person(1, "wxg");
    // p1.toString();

    Man man1 = Man(10, "wxgaly", 1);
    man1.toString();

    // int *p = &a;
    // cout << "*p " << *p << endl;

    // int arr[3] = {1, 2, 3};
    // int *index = arr;

    // for (size_t i = 0; i < 3; i++)
    // {
    //     cout << "arr[" << i << "] = " << *index << endl;
    //     index++;
    // }

    // index = &arr[2];

    // for (int i = 2; i >= 0; i--)
    // {
    //     /* code */
    //     cout << "arr[" << i << "] = " << *index << endl;
    //     index--;
    // }

    // std::cout << "a + b = " << a + b << std::endl;
    // std::cout << "Hello, world!\n";

    // FileUtil *fileUtil = FileUtil::getInstance();
    // // fileUtil->testWrite();
    // fileUtil->testRead();

    // try
    //  {
    //     Stack<int> intStack;
        
    //     cout << intStack.top() << endl;

    //     intStack.push(7);
    //     // cout << intStack.top() << endl;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
}
