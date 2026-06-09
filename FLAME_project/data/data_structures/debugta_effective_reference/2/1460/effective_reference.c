#include <stdio.h>
char c[10000],b[10000];
int a[10000],d[10000];
int main()
{
    int i,j,k,ans=0;
    j=0;
    k=0;
    gets(c);
    for(i=0,j=0;c[i]!='=';i++)
    {
        if(c[i]!=' ')
        {
            b[j]=c[i];
            j++;
        }

    }
    b[j]='=';
    j++;
    b[j]='=';
    //puts(b);
    for(i=0;b[i]!='=';i++)
    {
        j=0;
        if(b[i]>='0'&&b[i]<='9')
        {
           for(;b[i]>='0'&&b[i]<='9';i++)
           j=j*10+b[i]-'0';
           a[k]=j;
           k++;
        }
        if(b[i]=='+')
        {
            a[k]=0;
            k++;
        }
        if(b[i]=='-')
        {
            a[k]=-2;
            k++;
        }
        if(b[i]=='*')
        {
            a[k]=-3;
            k++;
        }
        if(b[i]=='/')
        {
            a[k]=-4;
            k++;
        }

    }
    a[k]='=';
    for(i=0;a[i]!='=';i++)
    {
       if(a[i]==-3)
       {a[i+1]=a[i+1]*a[i-1];
       a[i-1]=0;
       a[i]=0;}
       if(a[i]==-4)
       {a[i+1]=a[i-1]/a[i+1];
       a[i-1]=0;
       a[i]=0;
       }

    }
     for(i=0,j=0;a[i]!='=';i++)
    {
        if(a[i]!=0)
        {
            d[j]=a[i];
            j++;
        }

    }
    d[j]='=';
    for(i=0;d[i]!='=';i++)
    {
       if(d[i]==-2)
       {
           d[i+1]*=-1;
           d[i]=0;
       }
    }
    for(i=0;d[i]!='=';i++)
    {
       ans+=d[i];
    }
    printf("%d",ans);
return 0;
}

