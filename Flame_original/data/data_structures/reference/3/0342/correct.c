/*
 * @Author:
 * @Date: 2022-03-03 20:22:37
 * @LastEditors:
 * @LastEditTime: 2022-03-03 20:33:19
 * @FilePath: notation.c
 */
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define MAXN 110
char S[MAXN];
int len;

int main()
{
    gets(S);
    len = strlen(S);
    if(S[0] == '0')
    {
        int i = 2;
        while(S[i] == '0') ++i;
        if(i == len - 1)
            printf("%ce%d",S[i],-(i-1) ); 
        else
            printf("%c.%se%d",S[i],S+i+1,-(i-1) ); 
    }
    else
    {
        int i=1;
        while(S[i] != '.') ++i;
        printf("%c.",S[0]);
        for(int j=1;S[j] != '\0';++j)
        if(S[j] != '.')
            putchar(S[j]);
        printf("e%d",i-1);
    }
    return 0;
}
