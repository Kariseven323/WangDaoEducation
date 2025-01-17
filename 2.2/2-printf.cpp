#include<iostream>
using namespace std;
int main()
{
    int age=21;
    printf("Hello %s,you are %d years old\n","Bob",age);
    int i=1001;
    float f=96.3;
    printf("student number=%5d,score=%5.2f\n",i,f);
    i=100;
    f=98.21;
    printf("student number=%-5d,score=%5.2f\n",i,f);
    return 0;
}