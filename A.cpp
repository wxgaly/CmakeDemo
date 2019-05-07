#include "A.h"

template <class T>
A<T>::A()
{
    cout << "A init" << endl;
}

template <class T>
A<T>::~A()
{
    cout << "A release" << endl;
}

template <class T>
void A<T>::test()
{
    cout << "A test" << endl;
}

template <class T>
T A<T>::add(T a, T b)
{
    return a + b;
}