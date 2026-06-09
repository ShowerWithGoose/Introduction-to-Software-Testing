#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int powint(int a,int b);
int main()
{
    char s[1000],f[1000],e[1000];
    int fp[1000],x[1000],y[1000];
    gets(s);
    int l,i,j,k,p,t;
    for(i=j=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ') s[j++]=s[i];
    }
    s[j]='\0';
    i=j=0;
    l=strlen(s);
    fp[0]=-1;
    for(i=0;i<l;i++)
    {
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
        {
            f[j]=s[i];
            fp[j+1]=i;
            j++;
        }
    }
    f[j]='\0';
    p=strlen(f);
    for(i=1;i<=j;i++)
    {
        t=0;
        x[i-1]=0;
        for(k=fp[i]-1;k>fp[i-1];k--)
        {
            x[i-1]+=(s[k]-'0')*powint(10,t);
            t++;
        }
    }
    k=0;
    for(i=0;i<j;i++)
    {
        if(f[i]=='*')
        {
            x[i+1]=x[i+1]*x[i];
        }
        else if(f[i]=='/')
        {
            x[i+1]=x[i]/x[i+1];
        }
        else
        {
            y[k]=x[i];
            k++;
        }
    }
    for(i=j=0;f[i]!='\0';i++)
    {
        if(f[i]!='*'&&f[i]!='/') f[j++]=f[i];
    }
    f[j]='\0';
    l=strlen(f);
    for(i=0;i<l;i++)
    {
        if(f[i]=='+')
        {
            y[i+1]=y[i+1]+y[i];
        }
        else if(f[i]=='-')
        {
            y[i+1]=y[i]-y[i+1];
        }
        else if(f[i]=='=')
        {
            printf("%d",y[i]);
            break;
        }
    }
    return 0;
}

int powint(int a,int b)
{
    int i,r;
    r=1;
    for(i=0;i<b;i++)
    {
        r=r*a;
    }
    return r;
}



