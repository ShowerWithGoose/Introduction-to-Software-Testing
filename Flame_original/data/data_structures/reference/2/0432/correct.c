#include <stdio.h>
char a[10000],b[10000];
int c[10000],d[10000];
int main()
{
    int i,j,k,s=0;
    j=0;
    k=0;
    gets(a);
    for(i=0,j=0;a[i]!='=';i++)
    {
        if(a[i]!=' ')
        {
            b[j]=a[i];
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
           c[k]=j;
           k++;
        }
        if(b[i]=='+')
        {
            c[k]=0;
            k++;
        }
        if(b[i]=='-')
        {
            c[k]=-2;
            k++;
        }
        if(b[i]=='*')
        {
            c[k]=-3;
            k++;
        }
        if(b[i]=='/')
        {
            c[k]=-4;
            k++;
        }

    }
    c[k]='=';
    for(i=0;c[i]!='=';i++)
    {
       if(c[i]==-3)
       {c[i+1]=c[i+1]*c[i-1];
       c[i-1]=0;
       c[i]=0;}
       if(c[i]==-4)
       {c[i+1]=c[i-1]/c[i+1];
       c[i-1]=0;
       c[i]=0;
       }

    }
     for(i=0,j=0;c[i]!='=';i++)
    {
        if(c[i]!=0)
        {
            d[j]=c[i];
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
       s+=d[i];
    }
    printf("%d",s);
return 0;
}

