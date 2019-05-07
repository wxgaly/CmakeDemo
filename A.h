#include <iostream>

using namespace std;

template <class T>
class A
{
public:
    A(/* args */);
    ~A();
    void test();
    T add(T a, T b);
};
