#include<stdio.h>
#include<string.h>
#include<ctype.h>
int expand(int i,char str[]);
int main(void)
{
    char str[999];
    gets(str);
    int i;
    for(i=0;i<strlen(str);i++)
    {
        if(str[i]=='-')
        {
            if(expand(i,str)==0)
                putchar('-');
        }
        else putchar(str[i]);
    }
}
int expand(int i,char str[])
{
    int sign=0;
    if(isdigit(str[i-1])&&isdigit(str[i+1])&&(str[i-1]<str[i+1])) sign=1;
    else if(islower(str[i-1])&&islower(str[i+1])&&(str[i-1]<str[i+1])) sign=1;
    else if(isupper(str[i-1])&&isupper(str[i+1])&&(str[i-1]<str[i+1])) sign=1;
    if(sign==1)
    {
        char ch=str[i-1]+1;
        while(ch<str[i+1])
        {
            putchar(ch);
            ch++;
        }
    }
    return sign;
}

