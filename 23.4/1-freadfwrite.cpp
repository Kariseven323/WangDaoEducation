/**
 * @file 1-freadfwrite.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char buf[20] = "hello\nworld";
    FILE *fp;
    int ret;
    fp = fopen("file.txt", "r+");
    if(NULL==fp)
    {
        perror("fopen");
        return -1;
    }
    ret = fwrite(buf, sizeof(char), strlen(buf), fp);
    // ret = fread(buf, sizeof(buf),strlen(buf) - 1, fp);
    // puts(buf);
    fclose(fp);
    return 0;
}