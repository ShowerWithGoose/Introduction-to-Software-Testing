#include <stdio.h>
#include <string.h>
char N[15]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
void f(int p,int q,char c[])
{
    if(q==1)
    {
        int o;
        for(o=10-p+1;o<10;o++)
        printf("%c ",c[o]);
        printf("%c\n",c[10]);
    }
    else if(q==2)
    {
        f(p,q-1,c);
        char r;
        r=c[9],c[9]=c[10],c[10]=r;
        f(p,q-1,c);
        r=c[9],c[9]=c[10],c[10]=r;
    }
    else
    {
        char a[15]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'},b[15]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
        int j,k;
        k=10-q,j=k+2;
        f(p,q-1,c);
        for(j=k+2;j<10;j++)
        {
            strcpy(a,c);
            strcpy(b,c);
            a[k]=a[j],a[j]='\0';
            strncat(a,&a[j+1],10-j);
            strncpy(&b[k+1],&a[k],q);
            f(p,q-1,b);
        }
        strcpy(a,c);
        strcpy(b,c);
        a[k]=a[j],a[j]='\0';
        strncpy(&b[k+1],&a[k],q);
        f(p,q-1,b);
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    N[i+10-n]=i+'0';
    f(n,n,N);
    return 0;
}

