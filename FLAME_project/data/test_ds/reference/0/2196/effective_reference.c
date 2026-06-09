#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000],b[1000];
    int i=0,j=0,k=0,n;
    gets(a);
    for(i=0;i<=strlen(a);i++,j++)
    {
        b[j]=a[i];
        if(a[i+1]=='-')
        {
            if(a[i]>=65&&a[i]<=90&&a[i+2]>=65&&a[i+2]<=90&&a[i]+1<a[i+2]||a[i]>=97&&a[i]<=122&&a[i+2]>=97&&a[i+2]<=122&&a[i]+1<a[i+2]||a[i]>=48&&a[i]<=57&&a[i+2]>=48&&a[i+2]<=57&&a[i]+1<a[i+2])
            {
                n=i;
                for(k=0;(b[j]+1)!=a[n+2];j++,i++)
                {
                    b[j+1]=b[j]+1;
                }
                 i=n+1;
            }
        }
    }
    printf("%s",b);
    return 0;
}

