#include<stdio.h>
int main()
{
    int i;
    char c;
    scanf("%d", &i);
    printf("i=%d\n", i);
    fflush(stdin);//该函数对输入流没有作用，王道课程有误
    scanf("%c", &c);
    printf("c=%c\n", c);
    return 0;
}