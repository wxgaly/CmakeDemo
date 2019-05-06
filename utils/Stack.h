#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
private:
    /* data */
    vector<T> elems;

public:
    Stack();
    ~Stack();
    void push(T const &); // 入栈
    void pop();           // 出栈
    T top() const;        // 返回栈顶元素
    // bool empty() const
    // { // 如果为空则返回真。
    //     return elems.empty();
    // }
};

#endif