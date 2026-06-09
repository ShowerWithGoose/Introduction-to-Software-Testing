#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void reverse(char a[]);
int main()
{
    char a[1000],b[1000],c[1000];
    gets(a);
    int l,i,j,k,fp,p,f0,m;
    m=0;
    fp=0;f0=0;
    l=strlen(a);
    p=l;
    if(l==1&&a[0]=='0')
    {
        printf("0e0");
        return 0;
    }
    for(i=0;i<l;i++)
    {
        if(a[i]=='.')
        {
            fp=1;
            p=i;
        }
    }
    for(i=j=0;a[i]!='\0';i++)
    {
        if(a[i]!='.')
        {
            a[j++]=a[i];
        }
    }
    a[j]=0;
    l=strlen(a);
    for(i=j=0;i<l;i++)
    {
        if(a[i]!='0'||f0==1)
        {
            f0=1;
            b[j]=a[i];
            j++;
        }
        else if(a[i]=='0'&&f0==0)
        {
            m++;
        }
    }
    b[j]='\0';
    l=strlen(b);
    f0=0;
    j=0;
    for(i=l-1;i>=0;i--)
    {
        if(b[i]!='0'||f0==1)
        {
            f0=1;
            c[j]=b[i];
            j++;
        }
        else
        {
            continue;
        }
    }
    c[j]='\0';
    reverse(c);
    l=strlen(c);
    if(p>1||a[0]!='0')
    {
        printf("%c",c[0]);
        if(l!=1)
        {
            printf(".");
        }
        for(i=1;i<l;i++)
        {
            printf("%c",c[i]);
        }
        printf("e%d",p-1);
    }
    else
    {
        printf("%c",c[0]);
        if(l!=1)
        {
            printf(".");
        }
        for(i=1;i<l;i++)
        {
            printf("%c",c[i]);
        }
        printf("e-%d",m);
    }
    return 0;
}

void reverse(char a[])
{
    int c,i,j;
    for(i=0,j=strlen(a)-1;i<j;i++,j--)
    {
        c=a[i];
        a[i]=a[j];
        a[j]=c;
    }
}

