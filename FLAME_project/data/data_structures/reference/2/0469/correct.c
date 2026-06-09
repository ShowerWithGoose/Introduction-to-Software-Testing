#include <stdio.h>
#include <math.h>
#include <string.h>
char ch[1000];
int getnum(int n)
{
    int k;
    int num=0;
    for(k=n;ch[k]!='\0'&&ch[k]!='+'&&ch[k]!='-'&&ch[k]!='*'&&ch[k]!='/'&&ch[k]!='=';k++)
    {
        num=(num*10+(ch[k]-'0'));
    }
    return num;
}
int main()
{
    int i,j;
    int len;
    int num,mid,sum=0;
    gets(ch);
    for(i=0,j=0;ch[i]!='\0';i++)
    {
        if(ch[i]!=' ')
        {
            ch[j++]=ch[i];
        }
    }
    len=j;
    for(i=0;i<len;)
    {
        if(ch[i]<='9'&&ch[i]>='0')
        {
            num=getnum(i);
            mid=num;
            while(ch[i]<='9'&&ch[i]>='0')
            {
                i++;
            }
        }
        if(ch[i]=='+')
        {
            sum+=mid;
            mid=0;
            num=getnum(i+1);
            mid+=num;
            i++;
            while(ch[i]<='9'&&ch[i]>='0')
            {
                i++;
            }
        }
        if(ch[i]=='-')
        {
            sum+=mid;
            mid=0;
            num=getnum(i+1);
            mid-=num;
            i++;
            while(ch[i]<='9'&&ch[i]>='0')
            {
                i++;
            }
        }
        if(ch[i]=='*')
        {
            num=getnum(i+1);
            mid*=num;
            i++;
            while(ch[i]<='9'&&ch[i]>='0')
            {
                i++;
            }
        }
        if(ch[i]=='/')
        {
            num=getnum(i+1);
            mid/=num;
            i++;
            while(ch[i]<='9'&&ch[i]>='0')
            {
                i++;
            }
        }
        if(ch[i]=='=')
        {
            sum+=mid;
            printf("%d",sum);
            break;
        }
    }
    return 0;
}

