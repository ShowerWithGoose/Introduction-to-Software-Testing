#include <stdio.h>
#include <string.h>
int main()
{
    int a=0,b,c;
    char A='+',B,C;
    while(A!='=')
    {
        scanf("%d %c",&b,&B);
        while(B=='*'||B=='/')
        {
            scanf("%d %c",&c,&C);
            if(B=='*')
                b=b*c;
            else
                b=b/c;
                B=C;
        }
        if(A=='+')
            a=a+b;
        else if(A=='-')
            a=a-b;
            A=B;
        if(A=='=')
            {
                printf("%d",a);
                break;
            }
    }
    return 0 ;
}




