/*
 * @Author: wangxuguang 
 * @Date: 2019-05-30 18:00:19 
 * @Last Modified by: wangxuguang
 * @Last Modified time: 2019-05-30 19:21:33
 */
#include "UdpServer.h"

UdpServer::UdpServer()
{
    isStart = true;
    cout << "UdpServer init" << endl;
}

UdpServer::~UdpServer()
{
    cout << "UdpServer release" << endl;
}

void UdpServer::bind(const std::string &ip, int port)
{
    try
    {
        cout << "ip is " << ip << " ,port is " << port << endl;
        this->ip = ip;
        this->port = port;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void UdpServer::onReceived(char buffer[], int len)
{
    std::string msg(buffer, len);
    cout << "receive str: " << msg << endl;
}

void UdpServer::run()
{
    ip::udp::socket serverSocket(m_io_service, ip::udp::endpoint(ip::udp::v4(), port));
    // ip::udp::socket serverSocket(m_io_service, ip::udp::endpoint(ip::address_v4::from_string(ip), port));

    char buff[4096];

    while (this->isStart)
    {
        ip::udp::endpoint sender_ep;
        int len = serverSocket.receive_from(buffer(buff), sender_ep);
        this->onReceived(buff, len);
    }
}

void UdpServer::start()
{
    this->isStart = true;

    receiveTthread = boost::thread(&UdpServer::run, this);
    receiveTthread.join();
}

void UdpServer::stop()
{
    this->isStart = false;
}
