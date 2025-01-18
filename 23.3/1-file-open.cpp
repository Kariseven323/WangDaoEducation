/**
 * @file 1-file-open.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-01-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include<iostream>
using namespace std;
int main()
{
    FILE *fp;
    fp = fopen("file.txt", "r+");
    if(NULL==fp)
    {
        perror("fopen");
        return -1;
    }
    char c;
    while((c=fgetc(fp))!=EOF)
    {
        printf("%c", c);
    }
    printf("\n");
    fputc('a', fp);
    return 0;
}