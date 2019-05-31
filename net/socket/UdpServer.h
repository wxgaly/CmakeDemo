/*
 * @Author: wangxuguang 
 * @Date: 2019-05-30 17:59:07 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2019-05-30 20:27:30
 */
#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

using namespace std;
using namespace boost::asio;

class UdpServer
{
private:
    string ip;
    int port;
    bool isStart;
    io_service m_io_service;
    boost::thread receiveTthread;

public:
    UdpServer();
    void bind(const std::string &ip, int port);
    void onReceived(char buffer[], int len);
    void start();
    void stop();
    void run();
    ~UdpServer();
};

#endif