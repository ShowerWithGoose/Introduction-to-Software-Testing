#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    int i=0,n=0,k=0,m;
    gets(a);
    for(i=0;i<=strlen(a);i++,n++)
    {
        b[n]=a[i];
        if(a[i+1]=='-')
        {
            if(a[i]>=65&&a[i]<=90&&a[i+2]>=65&&a[i+2]<=90&&a[i]+1<a[i+2]||a[i]>=97&&a[i]<=122&&a[i+2]>=97&&a[i+2]<=122&&a[i]+1<a[i+2]||a[i]>=48&&a[i]<=57&&a[i+2]>=48&&a[i+2]<=57&&a[i]+1<a[i+2])
            {
                m=i;
                for(k=0;(b[n]+1)!=a[m+2];n++,i++)
                {
                    b[n+1]=b[n]+1;
                }
                 i=m+1;
            }
        }
    }
    printf("%s",b);
    return 0;
}

