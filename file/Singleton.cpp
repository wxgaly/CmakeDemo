/*
 * @Author: wangxuguang 
 * @Date: 2019-05-05 14:30:57 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2019-05-05 14:32:22
 */
#include <atomic>
#include <iostream>

using namespace std;

class Singleton
{
  private:
    // static volatile Singleton * volatile local_instance;
    static atomic<Singleton*> instance;
    Singleton(){
        cout << "构造" << endl;
    };
    ~Singleton(){
        cout << "析构" << endl;
    }
    class rememberFree{
        public:
        rememberFree(){
            cout << "成员构造" << endl;
        }
        ~rememberFree(){
            Singleton* local_instance = instance.load(std::memory_order_relaxed);
            if(local_instance != nullptr){
                delete local_instance;
            }
        }
    };
    static rememberFree remember;
    

  public:
    static Singleton *getInstance()
    {
        Singleton* tmp = instance.load(std::memory_order_relaxed);
        atomic_thread_fence(memory_order_acquire);
        if(tmp == nullptr){
            static mutex mtx;
            lock_guard<mutex> lock(mtx);
            tmp = instance.load(memory_order_relaxed);
            if (tmp == nullptr)
            {
                tmp = new Singleton();
                atomic_thread_fence(memory_order_release);
                instance.store(tmp, memory_order_relaxed);
            }
        }
        return tmp;
    }
};

atomic<Singleton*> Singleton::instance;
Singleton::rememberFree Singleton::remember;