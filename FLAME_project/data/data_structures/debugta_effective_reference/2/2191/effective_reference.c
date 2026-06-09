#include<stdio.h>
#include<ctype.h>
int main()
{
    char a[1000],b[1000],d[1000];
    int c[1000];
    int i=0,j=0,k,m=0,n=0,p,q=0,sum;
    c[0]=0;
    gets(a);
    for(; a[i]!='\0'; i++)
    {
        if(a[i]!=' ')
            b[j++]=a[i];
    }
    b[j]='\0';
    for(k=0; k<j; k++)
    {
        if(isdigit(b[k]))
            c[m]=10*c[m]+b[k]-'0';
        else
        {
            c[++m]=0;
            d[n++]=b[k];
        }
    }
    for(p=0; p<=k-1; p++)
    {
        if(d[p]=='*')
        {
            c[p+1]=c[p]*c[p+1];
            c[p]=0;
            if(p==0)
                d[p]='+';
            else
                d[p]=d[p-1];
        }
        if(d[p]=='/')
        {
            c[p+1]=c[p]/c[p+1];
            c[p]=0;
            if(p==0)
                d[p]='+';
            else
                d[p]=d[p-1];
        }

    }
    sum=c[0];
    for(q=0;q<m;q++)
    {
        if(d[q]=='+')
        {
            sum+=c[q+1];
        }
        if(d[q]=='-')
        {
            sum-=c[q+1];
        }
    }
    printf("%d",sum);
    return 0;
}

