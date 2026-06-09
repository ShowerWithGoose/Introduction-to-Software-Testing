#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int readFloat(char *);
int main()
{
    int n1 = 0,n2 = 0,len = 0;
    char afn[105] = {};
    len = readFloat(afn);
    for (; (afn[n1] != '.')&&(afn[n1] != 0); n1++)
    {
    }
    for (;afn[n2] == '0' ;n2++)
    {
    }
    if (afn[n2] == '-')
    {
        putchar(afn[n2]);
        n2 += (afn[n2+1] == '0')?2:1; 
    }
    if (afn[n2] == '.')
    {
        n2++;
       for (;afn[n2] == '0' ;n2++)
        {
        } 
    }
    putchar(afn[n2]);
    int count = 0;
    for (size_t i = n2+1; i < len; i++)
    {
        if (afn[i] > '0' && afn[i] <= '9')
        {
            count++;
        }
    }
    if (count > 0)
    {
        putchar('.');
    }
    for (size_t i = n2 + 1; i < len; i++)
    {
        if (afn[i] != '.')
        {
            putchar(afn[i]);
        }
    }
    printf("e%d", (n1 - n2) > 0 ? n1-n2-1:n1-n2);
    return 0;
}

int readFloat(char *num)
{
    char a;
    int n = 0;
    while (((a = getchar()) != EOF) && (a != '\n'))
    {
        num[n] = a;
        n++;
    }
    return n;
}
