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

using namespace std;

class UdpClient
{
private:
    string ip;
    int port;

public:
    UdpClient();
    void bind(string ip, int port);
    string getIp();
};

#endif