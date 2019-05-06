/*
 * @Author: wangxuguang 
 * @Date: 2019-05-05 14:15:25 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2019-05-05 19:09:06
 */
#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <atomic>
#include <iostream>
#include <fstream>

using namespace std;

class FileUtil
{
private:
    // static volatile FileUtil * volatile local_instance;
    static atomic<FileUtil *> instance;
    FileUtil()
    {
        cout << "构造" << endl;
    };
    ~FileUtil()
    {
        cout << "析构" << endl;
    }
    class rememberFree
    {
    public:
        rememberFree()
        {
            cout << "成员构造" << endl;
        }
        ~rememberFree()
        {
            FileUtil *local_instance = instance.load(std::memory_order_relaxed);
            if (local_instance != nullptr)
            {
                delete local_instance;
            }
        }
    };
    static rememberFree remember;

public:
    static FileUtil *getInstance()
    {
        FileUtil *tmp = instance.load(std::memory_order_relaxed);
        atomic_thread_fence(memory_order_acquire);
        if (tmp == nullptr)
        {
            static mutex mtx;
            lock_guard<mutex> lock(mtx);
            tmp = instance.load(memory_order_relaxed);
            if (tmp == nullptr)
            {
                tmp = new FileUtil();
                atomic_thread_fence(memory_order_release);
                instance.store(tmp, memory_order_relaxed);
            }
        }
        return tmp;
    }
    void testWrite()
    {
        ofstream outfile;
        outfile.open("afile.txt");

        outfile << "测试写入数据  aaa " << endl;
        outfile.close();
    }

    void testRead()
    {
        string data;
        ifstream infile; 
        infile.open("afile.txt");

        infile >> data;

        cout << data << endl; 
        
        infile.close();
    }
};

atomic<FileUtil *> FileUtil::instance;
FileUtil::rememberFree FileUtil::remember;

#endif