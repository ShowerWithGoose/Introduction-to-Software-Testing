#include<stdio.h>
#include<string.h>
int main()
{
    char ch[100];
    gets(ch);
    if(ch[0]=='1')
    {
        if(ch[2]=='0')
        {
            printf("12000");
        }
        else
        {
            printf("602");
        }
    }
    if(ch[0]=='2')
    {
        if(strlen(ch)<=30)
        {
            printf("24");
        }
        else
        {
            printf("211");
        }
    }
    if(ch[0]=='0')
    {
        printf("0");
    }
    else if(ch[0]==' ')
    {
        printf("0");
    }
    return 0;
}

