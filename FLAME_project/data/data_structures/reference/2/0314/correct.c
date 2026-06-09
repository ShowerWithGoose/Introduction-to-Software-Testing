#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char or[1000],a[1000],ch[500],ch2[500];
    int po=0,nb=0,nb2=1,i1,i2,num[500]={0},num2[500]={0},sum;
    gets(or);
    int orlen=strlen(or);
    i2=0;
    for(i1=0;i1<orlen;i1++)
    {
        if(or[i1]!=' ')
        {
            a[i2]=or[i1];
            i2++;
        }
    }
    int len=strlen(a);
    for(i1=0;i1<=len-1;i1++)
    {
        if(a[i1]=='+' || a[i1]=='-' || a[i1]=='*' || a[i1]=='/' || a[i1]=='=')
        {
            nb++;
            for(i2=po;i2<i1;i2++)
            {
                num[nb]+=pow(10,i1-i2-1)*(a[i2]-'0');
                ch[nb]=a[i1];
            }
            po=i1+1;
        }
    }
    num2[1]=num[1];
    for(i1=1;i1<nb;i1++)
    {
        if(ch[i1]=='*')
        {
            num2[nb2]*=num[i1+1];
        }
        else if(ch[i1]=='/')
        {
            num2[nb2]/=num[i1+1];
        }
        else
        {
            ch2[nb2]=ch[i1];
            nb2++;
            num2[nb2]=num[i1+1];
        }
    }
    sum=num2[1];
    for(i1=1;i1<nb2;i1++)
    {
        if(ch2[i1]=='+')
        {
            sum+=num2[i1+1];
        }
        else
        {
            sum-=num2[i1+1];
        }
    }
    printf("%d",sum);
    return 0;
}
