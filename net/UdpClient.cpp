/*
 * @Author: wangxuguang 
 * @Date: 2019-05-06 16:16:14 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2019-05-06 16:50:18
 */
#include "UdpClient.h"

UdpClient::UdpClient()
{
    cout << "UdpClient init" << endl;
}

void UdpClient::bind(string ip, int port)
{
    cout << "ip is " << ip << " ,port is " << port << endl;
    this->ip = ip;
    this->port = port;
}

string UdpClient::getIp()
{
    return ip;
}