#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearDot(char* s)
{
    int i,j;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]!='.') s[j++]=s[i];
    }
    s[j]='\0';
    return ;
}

void clearZero(char* s)
{
    int i,j,flag=0;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(flag==0)
        {
            if(s[i]!='0')
            {
                s[j++]=s[i];
                flag=1;
            }
        }
        else s[j++]=s[i];
    }
    s[j]='\0';
    s[j+1]='\0';
    return;
}

void insertDot(char* s)
{
    int i;
    for(i=strlen(s);i>1;i--)
    {
        s[i]=s[i-1];
    }
    s[i]='.';
    return ;
}

int main()
{
    char s[110];
    int i,j=0,ind;
    gets(s);
    if(s[0]=='0')
    {
        for(i=2;s[i]=='0';i++);
        ind=1-i;
        clearDot(s);
        clearZero(s);



    }
    else
    {
        for(i=0;s[i]!='.'&&s[i]!='\0';i++);
        ind=--i;
        clearDot(s);
        j=strlen(s);
        while(s[j-1]=='0')
        {
            s[j-1]='\0';
            j--;
        }

    }
    if(s[1]!='\0') insertDot(s);
    printf("%s",s);
    printf("e%d",ind);
    return 0;
}

