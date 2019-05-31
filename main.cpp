#include <iostream>
// #include "Person.h"
// #include "Man.h"
// #include "file/FileUtil.h"
// #include "Stack.cpp"
#include <pthread.h>
#include "UdpClient.h"
#include "socket/UdpServer.h"
// #include "A.cpp"
// #include <boost/date_time.hpp>
#include <boost/version.hpp>
#include <boost/asio.hpp>

#include <Poco/Net/DatagramSocket.h>
#include <Poco/Thread.h>

// using namespace std;
using namespace boost::asio;
using namespace Poco::Net;

#define byte unsigned char
#define PACKET_HEAD_SIZE 24
#define PAKKET_SEQUENCE_OFFSET 4

#define PACKET_TYPE_OFFSET 8

#define PACKET_PARAM1_OFFSET 10

#define PACKET_PARAM2_OFFSET 12

#define PACKET_LEN_OFFSET 16

#define PACKET_HEAD_RESEVD 20 //reserved for the user implements the protocol.

#define PACKET_HEAD_CHECKSUM_OFFSET 22

struct thread_data
{
    int thread_id;
    char *message;
};

#define NUM_THREADS 5

// void *say_hello(void *threadarg)
// {
//     struct thread_data *my_data;

//     my_data = (struct thread_data *)threadarg;

//     cout << "Thread ID : " << my_data->thread_id;
//     cout << " Message : " << my_data->message << endl;
//     pthread_exit(NULL);
// }

// void testThread()
// {
//     pthread_t tids[NUM_THREADS];
//     // int indexes[NUM_THREADS];
//     struct thread_data td[NUM_THREADS];
//     int i;
//     for (i = 0; i < NUM_THREADS; ++i)
//     {
//         cout << "main() : 创建线程, " << i << endl;
//         td[i].thread_id = i;
//         td[i].message = (char *)"This is message";
//         int ret = pthread_create(&tids[i], NULL, say_hello, (void *)&(td[i]));
//         if (ret != 0)
//         {
//             cout << "pthread_create error: error_code=" << ret << endl;
//         }
//     }
//     //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
//     pthread_exit(NULL);
// }

template <typename T>
inline T const &Max(T const &a, T const &b)
{
    return a < b ? b : a;
}

// void testTemplate()
// {
//     int i = 39;
//     int j = 20;
//     cout << "Max(i, j): " << Max(i, j) << endl;

//     double f1 = 13.5;
//     double f2 = 20.7;
//     cout << "Max(f1, f2): " << Max(f1, f2) << endl;

//     string s1 = "Hello";
//     string s2 = "World";
//     cout << "Max(s1, s2): " << Max(s1, s2) << endl;
// }

void handler(const boost::system::error_code &ec)
{
    std::cout << "5 s." << std::endl;
}

void testPOCOUdp()
{
    try
    {
        SocketAddress bindAddress = SocketAddress(IPAddress(), 16600);
        DatagramSocket sender = DatagramSocket(bindAddress, true);
        SocketAddress sendAddress = SocketAddress(IPAddress("192.168.0.6"), 16601);

        // sender.setBroadcast(true);
        int ret = sender.sendTo("1", 1, sendAddress, 0);
        std::cout << "testPOCOUdp ret : " << ret << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    Poco::Thread::sleep(20);
}

short checkSum(byte buff[], int offset, int count)
{
    short sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += buff[offset + i];
    }
    return sum;
}

void shortToBytes(byte buff[], int offset, short value)
{
    buff[offset] = (byte)value;
    buff[offset + 1] = (byte)(value >> 8);
}

void intToBytes(byte buff[], int offset, int value)
{
    buff[offset] = (byte)value;
    buff[offset + 1] = (byte)(value >> 8);
    buff[offset + 2] = (byte)(value >> 16);
    buff[offset + 3] = (byte)(value >> 24);
}

byte *packHeadData(int sequence, short type, short what, int param2, int count)
{
    int head = 0x4e4f5641;
    byte sendBuffer[PACKET_HEAD_SIZE] = {0};
    intToBytes(sendBuffer, 0, head);
    intToBytes(sendBuffer, PAKKET_SEQUENCE_OFFSET, sequence);
    shortToBytes(sendBuffer, PACKET_TYPE_OFFSET, type);
    shortToBytes(sendBuffer, PACKET_PARAM1_OFFSET, what);
    intToBytes(sendBuffer, PACKET_PARAM2_OFFSET, param2);
    intToBytes(sendBuffer, PACKET_LEN_OFFSET, count);

    short headCheckSum = checkSum(sendBuffer, 0, PACKET_HEAD_SIZE - 2);
    shortToBytes(sendBuffer, PACKET_HEAD_CHECKSUM_OFFSET, headCheckSum);
    for (int i = 0; i < PACKET_HEAD_SIZE; i++)
    {
        cout << "sendBuffer[" << i << "] = " << (int)sendBuffer[i] << endl;
    }
    return sendBuffer;
}

void sendUdp()
{
    boost::this_thread::sleep(boost::posix_time::seconds(3)); 
    UdpClient udpclient;
    udpclient.bind("192.168.0.6", 16600);
    std::cout << "ip : " << udpclient.getIp() << std::endl;
    // byte data[] = {1, 2, 3, 4};
    byte* data = packHeadData(-1, (short) 0x8855, 0x81, 0, 0);

    for (int i = 0; i < PACKET_HEAD_SIZE; i++)
    {
        cout << "data[" << i << "] = " << *(data + i) << endl;
    }
    
    udpclient.sendPacket(data, PACKET_HEAD_SIZE, true);
}

void testBoostUdp()
{
    UdpServer udpServer;
    udpServer.bind("127.0.0.1", 16600);
    udpServer.start();
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

    // try
    // {
    //     Stack<int> intStack;

    //     intStack.push(7);
    //     cout << intStack.top() << endl;
    // }
    // catch (const std::exception &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // testThread();

    // A<int> a;
    // cout << a.add(1, 2) << endl;

    // testTemplate();

    // std::cout << "Boost版本: " << BOOST_VERSION << std::endl;
    // boost::posix_time::time_duration td(1, 10, 30, 1000);
    // cout << boost::posix_time::to_simple_string(td) << endl;

    // boost::asio::io_service io_service;
    // boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));
    // timer.async_wait(handler);
    // io_service.run();

    // io_service io_service;
    // ip::udp::endpoint local_endpoint(ip::udp::v4(), 16600);
    // // ip::udp::endpoint remote_endpoint(ip::address_v4::from_string("192.168.0.6"), 16611);
    // ip::udp::endpoint broadcast_endpoint(ip::address_v4::broadcast(), 16601);
    // ip::udp::socket socket(io_service, local_endpoint);
    // socket_base::broadcast option(true);
    // socket.set_option(option);
    // socket.send_to(buffer((void*)0, 0/*the size of contents*/), broadcast_endpoint);

    // testPOCOUdp();

    boost::thread t1(&sendUdp);
    testBoostUdp();
    
}
