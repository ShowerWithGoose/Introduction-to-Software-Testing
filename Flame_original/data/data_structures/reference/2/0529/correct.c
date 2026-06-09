#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int n(int x,int y,char fu)
{
    if(fu=='-')
        return (x-y);
    if(fu=='+')
        return (x+y);
    if(fu=='*')
        return (x*y);
    if(fu=='/')
        return (x/y);
}
int main()
{
    int a,b,c;
    char fu1,fu2;
    scanf("%d",&a);
    scanf(" %c",&fu1);
    if(fu1=='=')
        printf("%d",a);
    else
    {
        scanf("%d",&b);
        scanf(" %c",&fu2);
        if(fu2=='=')
            printf("%d",n(a,b,fu1));
        else
        {
            while(fu2!='=')
            {
                scanf("%d",&c);
                if((fu1=='*'||fu1=='/')&&(fu2=='*'||fu2=='/'))
                {
                    a=n(a,b,fu1);
                    b=c;
                    fu1=fu2;
                }
                else if((fu1=='*'||fu1=='/')&&(fu2=='+'||fu2=='-'))
                {
                    a=n(a,b,fu1);
                    b=c;
                    fu1=fu2;
                }
                else if((fu1=='+'||fu1=='-')&&(fu2=='*'||fu2=='/'))
                {
                    b=n(b,c,fu2);
                    c=0;
                    fu2='0';
                }
                else if((fu1=='+'||fu1=='-')&&(fu2=='+'||fu2=='-'))
                {
                    a=n(a,b,fu1);
                    b=c;
                    fu1=fu2;
                }
                scanf(" %c",&fu2);
            }
            printf("%d",n(a,b,fu1));
        }
    }

return 0;
}

