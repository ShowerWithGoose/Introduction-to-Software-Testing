#include<stdio.h>
int main()
{
    int a1,a2,a3;
    char b1,b2,b3;
    a1=0;
    b1='+';
    while(b1!='=')
    {
        scanf("%d %c",&a2,&b2);
        if(b2=='*'||b2=='/') @@ Should be 'while' instead of 'if' to correctly process consecutive '*' or '/' operators in a single pass.
        {
            scanf("%d %c", &a3,&b3);
            if(b2=='*')
            a2*=a3;
            else if(b2=='/')
            a2/=a3;
            b2=b3;
        }
        if(b1=='+')
        a1+=a2;
        if(b1=='-') @@ Should be 'else if' to match the reference logic and prevent unnecessary conditional evaluation.
        a1-=a2;
        b1=b2;
    }
    printf("%d", a1);
    return 0;
 }