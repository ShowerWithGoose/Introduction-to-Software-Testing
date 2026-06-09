#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char a[1000];
char b[1000];
int c[1000];
char d[1000];
int sum=0,num=0,num1=1;
int main()
{
    gets(a);
    int n=strlen(a);
int i=0,j=0,m=0,i1=0,j1=0,i2=0,j2=0;
while(i<n)
{
    if(a[i]!=' ')
        b[j++]=a[i];
    b[j]='\0';
    i++;
}
while(m<j)
{
    sum=0;
    while(b[m]>='0'&&b[m]<='9')
    {
        sum=sum*10+b[m]-'0';
        m++;
    }
    c[i1++]=sum;
    d[j1++]=b[m];
    m++;
}
num=c[0];
while(j2<j1)
{
    if(d[j2]=='*')
    {
        num*=c[j2+1];
    }
    if(d[j2]=='/')
    {
        num/=c[j2+1];
    }
    if((d[j2]=='+'||d[j2]=='-')&&(d[j2+1]=='+'||d[j2+1]=='-'||d[j2+1]=='='))
    {
        if(d[j2]=='+')
            num+=c[j2+1];
        else
           num-=c[j2+1];
    }
   else if((d[j2]=='+'||d[j2]=='-')&&(d[j2+1]=='*'||d[j2+1]=='/'))
    {
        i2=j2+1;
        num1=c[i2];
        while(d[i2]=='*'||d[i2]=='/')
        {
            if(d[i2]=='*')
             num1*=c[i2+1];
             else
            num1/=c[i2+1];
            i2++;
        }
        if(d[j2]=='+')
            num+=num1;
        else
            num-=num1;
        j2=i2-1;
    }
    j2++;
    if(j2=='=')
        break;
}
if(d[0]=='=')
    printf("%d\n",c[0]);
else
printf("%d\n",num);
return 0;
}

