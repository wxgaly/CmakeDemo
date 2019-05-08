#include <iostream>
#include "Person.h"
#include "Man.h"
// #include "file/FileUtil.h"
#include "Stack.cpp"
#include <pthread.h>
#include "UdpClient.h"
#include "A.cpp"

using namespace std;

struct thread_data
{
    int thread_id;
    char *message;
};

#define NUM_THREADS 5

void *say_hello(void *threadarg)
{
    struct thread_data *my_data;

    my_data = (struct thread_data *)threadarg;

    cout << "Thread ID : " << my_data->thread_id;
    cout << " Message : " << my_data->message << endl;
    pthread_exit(NULL);
}

void testThread()
{
    pthread_t tids[NUM_THREADS];
    // int indexes[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; ++i)
    {
        cout << "main() : 创建线程, " << i << endl;
        td[i].thread_id = i;
        td[i].message = (char *)"This is message";
        int ret = pthread_create(&tids[i], NULL, say_hello, (void *)&(td[i]));
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}

template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

void testTemplate()
{
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl;

    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << endl;

    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << endl;
}

int main(int, char **)
{
    // int a = 2;
    // int b = 3;

    // Person person;
    // person.age = 100;
    // person.name = "wangxuguang";
    // person.toString();

    // Person p1 = Person(1, "wxg");
    // p1.toString();

    // Man man1 = Man(10, "wxgaly", 1);
    // man1.toString();

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

    try
    {
        Stack<int> intStack;

        intStack.push(7);
        cout << intStack.top() << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    // testThread();

    // UdpClient udpclient;
    // udpclient.bind("127.0.0.1", 8080);
    // cout << "ip : " << udpclient.getIp() << endl;

    A<int> a;
    cout << a.add(1, 2) << endl;

    // testTemplate();
}
