/*
 * @Author: wangxuguang 
 * @Date: 2019-05-06 16:12:00 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2019-05-06 16:49:31
 */
#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

class UdpClient
{
private:
    string ip;
    int port;
    io_service m_io_service;

public:
    UdpClient();
    void bind(const std::string& ip, int port);
    void sendPacket(void* data, bool isBroadcast);
    string getIp();
};

#endif