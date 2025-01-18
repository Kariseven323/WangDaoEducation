/**
 * @file 1-socket.cpp
 * @author your name (you@domain.com)
 * @brief 未完成代码部分
 * @version 0.1
 * @date 2025-01-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma comment(lib,"ws2_32.lib")
#include<iostream>
#include<winsock2.h>
#include<windows.h>
using namespace std;
int main(int argc,char *argv[])
{
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    if(WSAStartup(sockVersion,&wsaData)!=0)
    {
        return -1;
    }
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(slisten==INVALID_SOCKET)
    {
        printf("socker error !");
        return -1;
    }
}