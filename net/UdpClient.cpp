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

void UdpClient::bind(const std::string &ip, int port)
{
    try
    {
        cout << "ip is " << ip << " ,port is " << port << endl;
        this->ip = ip;
        this->port = port;

        ip::udp::endpoint local_endpoint(ip::udp::v4(), port);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

string UdpClient::getIp()
{
    return ip;
}

void UdpClient::sendPacket(const void *data, bool isBroadcast)
{
    io_service io_service;
    ip::udp::endpoint local_endpoint = ip::udp::endpoint(ip::udp::v4(), 16600);
    ip::udp::endpoint send_endpoint;
    ip::udp::socket socket(io_service, local_endpoint);
    if (isBroadcast)
    {
        send_endpoint = ip::udp::endpoint(ip::address_v4::broadcast(), 16601);
        socket_base::broadcast option(true);
        socket.set_option(option);
    }
    else
    {
        send_endpoint = ip::udp::endpoint(ip::address_v4::from_string(ip), 16601);
    }

    int len = socket.send_to(buffer(data, sizeof(data)), send_endpoint);
    cout << "send len: " << len << endl;
    socket.close();
}