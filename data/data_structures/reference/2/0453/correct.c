#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
int a,c,sum=0;
char b;
int t[101]={0};
char s[101];
scanf("%d%c",&a,&b);
    while(b==' ')
    {
    scanf("%c",&b);
    }
    if(b=='=')
        t[0]=a;
while(b!='=')
{
    while(b==' ')
    {
    scanf("%c",&b);
    }
    if(b=='=')
    break;
    while(b=='*'||b=='/')
    {
    if(b=='*')
    {
        scanf("%d",&c);
        a*=c;
        scanf("%c",&b);
        while(b==' ')
    {
    scanf("%c",&b);
    }
    }
    else if(b=='/')
    {
        scanf("%d",&c);
        a/=c;
        scanf("%c",&b);
        while(b==' ')
    {
    scanf("%c",&b);
    }
    }
    }
    if(b=='-'||b=='+')
    {
        s[sum]=b;
        t[sum]=a;
        sum++;
        scanf("%d%c",&a,&b);
    }
    if(b=='=')
    {
        t[sum]=a;

    }
}
for(int i=0;i<sum;i++)
{
    if(s[i]=='+')
    {
        t[0]+=t[i+1];
    }
    else if(s[i]=='-')
    {
        t[0]-=t[i+1];
    }
}
printf("%d",t[0]);
  return 0;
}

