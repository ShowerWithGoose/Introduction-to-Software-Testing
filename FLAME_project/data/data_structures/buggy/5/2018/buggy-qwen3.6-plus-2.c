#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h> // @@ The function 'pow' is used in 'schangei', requiring the math library. While included, linking errors often occur if -lm is not passed to the compiler. However, the primary issue causing compilation/linking failure in many strict environments or specific judges for this code structure is the use of 'gets'.
typedef struct{
    long long coe;
    long long pow;
}s;
s a[1000],b[1000],c[1000],d[1000],huanxu;
char g[1000];
char h[1000];
long long schangei(char q[])
{
    long long num=0;
    int len=strlen(q);
    for(int i=0;i<len;i++)
    {
        num+=(q[i]-'0')*pow(10,len-1-i);
    }
    return num;
}

int main()
{
    int i,j;
    int ia=-1;
    int ib=-1;
    int ic=-1;
    int n=2;
    gets(g); // @@ 'gets' is deprecated and removed in C11 standard, causing compilation warnings or errors in modern compilers. It should be replaced with 'fgets'. Additionally, 'gets' does not check buffer bounds, leading to potential security issues.
    int len=strlen(g);
    for (i=0;i<len;i++)
    {
        if(g[i]>='0'&&g[i]<='9')
        {
            h[++ia]=g[i];
        }
        if(g[i]==' '||i==len-1)
        {
            if(n==2)
            {
                a[++ib].coe=schangei(h);
                memset(h,0,sizeof(h));
                ia=-1;
                n=1;
            }
            else if(n==1)
            {
                a[ib].pow=schangei(h);
                memset(h,0,sizeof(h));
                ia=-1;
                n=2;
            }
        }
    }
    
    gets(g); // @@ Same error as above: 'gets' is unsafe and deprecated/removed in modern C standards.
    len=strlen(g);
    ia=-1;
    n=2;
    for(i=0;i<len;i++)
    {
        if(g[i]>='0'&&g[i]<='9')
        {
            h[++ia]=g[i];
        }
        if(g[i]==' '||i==len-1)
        {
            if(n==2)
            {
                b[++ic].coe=schangei(h);
                memset(h,0,sizeof(h));
                ia=-1;
                n=1;
            }
            else if(n==1)
            {
                b[ic].pow=schangei(h);
                memset(h,0,sizeof(h));
                ia=-1;
                n=2;
            }
        }
    }
    
    int id=-1;
    for(i=0;i<=ib;i++)
    {
        for(j=0;j<=ic;j++)
        {
            id++;
            c[id].coe=a[i].coe*b[j].coe;
            c[id].pow=a[i].pow+b[j].pow;
        }
    }
    
    for(i=id;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(c[j].pow<c[j+1].pow)
            {
                huanxu=c[j];
                c[j]=c[j+1];
                c[j+1]=huanxu;
            }
        }
    }
    
    int ie=-1;
    for(i=0;i<id;i++)
    {
        if(ie==-1||c[i].pow!=d[ie].pow)
        {
            ie++;
            d[ie].coe=c[i].coe;
            d[ie].pow=c[i].pow;
        }
        else if(c[i].pow==d[ie].pow)
        {
            d[ie].coe+=c[i].coe;
        }
    }
    
    for(i=0;i<=ie;i++)
    {
        if(d[i].coe!=0)
        {
            printf("%lld %lld ",d[i].coe,d[i].pow);
        }
    }
    return 0;
}