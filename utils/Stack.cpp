/*
 * @Author: wangxuguang 
 * @Date: 2019-05-06 16:10:55 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2019-05-07 11:35:11
 */
#include "Stack.h"

template <class T>
Stack<T>::Stack()
{
    cout << "Stack init" << endl;
}

template <class T>
Stack<T>::~Stack()
{
    cout << "Stack release" << endl;
}

template <class T>
void Stack<T>::push (T const& elem) 
{ 
    // 追加传入元素的副本
    elems.push_back(elem);    
}

template <class T>
void Stack<T>::pop () 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::pop(): empty stack"); 
    }
    // 删除最后一个元素
    elems.pop_back();         
}
 
template <class T>
T Stack<T>::top () const 
{ 
    if (elems.empty()) { 
        throw out_of_range("Stack<>::top(): empty stack"); 
    }
    // 返回最后一个元素的副本 
    return elems.back();      
}
