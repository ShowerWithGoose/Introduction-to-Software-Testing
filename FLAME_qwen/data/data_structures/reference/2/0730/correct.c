#include <stdio.h>
int a,b,c;
char d,e,f;
int main()
{
    scanf("%d %c",&a,&d);
    if(d=='=')
    printf("%d",a);
    else
    {
        scanf("%d %c",&b,&e);
        while(e!='=')
        {
            if(d=='*'||d=='/')
            {
                while(d=='*'||d=='/')
                {
                    if(d=='*')
                    a*=b,d=e;
                    else if(d=='/')
                    a/=b,d=e;
                    if(e=='=')
                    break;
                    else
                    scanf("%d %c",&b,&e);
                }
            }
            else if(d=='+'||d=='-')
            {
                if(e=='+'||e=='-')
                {
                    if(d=='+')
                    a+=b,d=e;
                    else if(d=='-')
                    a-=b,d=e;
                    scanf("%d %c",&b,&e);
                }
                else if(e=='*'||e=='/')
                {
                    scanf("%d %c",&c,&f);
                    while(e=='*'||e=='/')
                    {
                        if(e=='*')
                        b*=c,e=f;
                        else if(e=='/')
                        b/=c,e=f;
                        if(f=='=')
                        break;
                        else
                        scanf("%d %c",&c,&f);
                    }
                    if(d=='+')
                    a+=b,d=e,b=c,e=f;
                    else if(d=='-')
                    a-=b,d=e,b=c,e=f;
                }
            }
        }
        if(d=='+')
        a+=b;
        else if(d=='-')
        a-=b;
        printf("%d",a);
    }
    return 0;
}

