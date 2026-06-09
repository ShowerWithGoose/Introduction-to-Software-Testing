#include<stdio.h>
#include<string.h>
char s[10000];
int main()
{
    gets(s);
    puts(s); // @@ 这行只是输出输入字符串，没有进行任何算术表达式求值，完全不符合题目要求。
    return 0;
}