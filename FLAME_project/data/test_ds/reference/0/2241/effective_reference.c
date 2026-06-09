/*
 * @Author:
 * @Date: 2022-03-03 19:41:06
 * @LastEditors:
 * @LastEditTime: 2022-03-03 19:50:41
 * @FilePath: expand.c
 */
#include <stdio.h>
#include <string.h>
#define MAXN 100010
char S[MAXN];
int len;

int Judge(char x)
{
    if('0'<=x && x<='9') return 0;
    if('a'<=x && x<='z') return 1;
    if('A'<=x && x<='Z') return 2;
    return -1;
}

int main()
{
    scanf("%s",S+1);
    len = strlen(S+1);
    if(len <= 2) printf("%s",S+1);
    else
    {
        putchar(S[1]);
        for(int i=2;i<len;++i)
        {
            if(S[i] != '-') putchar(S[i]);
            else if(Judge(S[i-1]) == Judge(S[i+1]) && S[i-1]<S[i+1])
            {
                for(int b=S[i-1]+1;b<S[i+1];++b)
                    putchar(b);
            }
            else putchar(S[i]);
        }
        putchar(S[len]);
    }
    return 0;
}
