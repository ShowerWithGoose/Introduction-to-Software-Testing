#include<stdio.h>
#include<math.h>
#include<string.h> 
#include<stdlib.h>
#define oso 1e-12
int main()
{
    int a0,b,c,d=1,e,f,g,h,e0,fff=0,k,i,m,t=1,n,j,flag=0,sum=0;
    char a,fh='*',fh2='+';
    while(1)
    {
        if(fff%2!=0)
        {
            while(scanf("%c",&a)!=' ') // @@ scanf returns the number of items successfully read, not the character itself. The condition != ' ' is logically incorrect and relies on the inner break to function.
            {
                if(a!=' ')
                    break;
            }
        }
        else
            scanf("%d",&b);
        if(fff%2!=0&&(a=='-'||a=='+'))
        {
            d/=t;
            if(fh2=='+')
            {
                sum+=d;
            }
            else
            {
                sum-=d;
            }
            fh2=a;
            fh='*';
            d=1;
            t=1;
            fff++;
            continue;
        }
        else if(fff%2!=0&&a=='=')
        {
            d/=t;
            if(fh2='+') // @@ Assignment operator '=' is used instead of comparison operator '=='. This will always evaluate to true and incorrectly modify fh2, leading to wrong calculation results.
            {
                sum+=d;
            }
            else
            {
                sum-=d;
            }
            break;
        }
        else if(fff%2!=0)
        {
            fh=a;
        }
        else
        {
            if(fh=='*')
            {
                d*=b;
            }
            else if(fh=='/')
            {
                t*=b;
            }
        }
        fff++;
    }
    printf("%d",sum);
    return 0;
 }