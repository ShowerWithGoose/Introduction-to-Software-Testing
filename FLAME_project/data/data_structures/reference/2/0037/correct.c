#include <stdio.h>
int num()
{
    int n;
    scanf("%d",&n);
    while(n==' ')
        scanf("%d",&n);
    return n;
}
int sym()
{
    char m;
    scanf("%c",&m);
    while(m==' ')
        scanf("%c",&m);
    return m;
}
int cal(int d,char e,int f)
{
    int z;
    if(e=='+')
        z=d+f;
    else if(e=='-')
        z=d-f;
    else if(e=='*')
        z=d*f;
    else if(e=='/')
        z=d/f;
    return z;

}
int main()
{
    int a,b,c;
    char i,j;
    a=num();
    i=sym();
    if(i=='=')
    {
        printf("%d",a);
    }
    else
    {
        b=num();
        j=sym();
        if(j=='=')
        {
            printf("%d",cal(a,i,b));
        }
        else
        {
            while(j!='=')
            {
                c=num();
                int z;
                if(i=='*'|| i=='/')
                    z=0;
                else if(j=='*' || j=='/')
                    z=1;
                else
                    z=0;
                if (z==0)//左边符号优先
                {
                    a=cal(a,i,b);
                    b=c;
                    i=j;
                }
                else//右面符号优先
                    b=cal(b,j,c);
                j=sym();
            }
            printf("%d",cal(a,i,b));
        }
    }
    return 0;
}



