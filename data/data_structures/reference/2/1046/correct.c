#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#define LL long long
#define true 1
char a[100];
void qukongge();
int panduan(char n);
int main()
{
    int i,j=0,k=0,l=0,front,m=0,n=0;
    int b[100];
    char c[100];
    gets(a);
    qukongge();
    for(i=0;a[i]!='\0';i++)
    {
        if(panduan(a[i])==0)
        {
            front=0;
           for(j=i-1;panduan(a[j])&&j>=0;j--);
           for(j++;j<=i-1;j++)
           {
               front=front*10+(a[j]-'0');
           }
           b[m++]=front;
           c[n++]=a[i];
        }
    }
    for(i=0;i<n;i++)
    {
        if(c[i]=='*')
        {
            l=b[i]*b[i+1];
            b[i]=0;
            b[i+1]=l;
        }
        else if(c[i]=='/')
        {
            l=b[i]/b[i+1];
            b[i]=0;
            b[i+1]=l;
        }
    }
    for(i=0;i<n;i++)
    {
        if(c[i]=='+')
        {
            for(j=i+1;b[j]==0&&j<m;j++);
            l=b[i]+b[j];
            b[i]=0;
            b[j]=l;
        }
        else if(c[i]=='-')
        {
            for(j=i+1;b[j]==0&&j<m;j++);
            l=b[i]-b[j];
            b[i]=0;
            b[j]=l;
        }
    }
    printf("%d\n",b[m-1]);
    return 0;
}
void qukongge()
{
    int i,j;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
        {
            for(j=i+1;a[j]==' ';j++);
            if(a[j]=='\0')
            {
                a[i]=a[j];
                break;
            }
            else
            {
                a[i]=a[j];
                a[j]=' ';
            }
        }
    }
}
int panduan(char n)
{
    if(n>='0'&&n<='9')
        return 1;
    else
        return 0;
}


