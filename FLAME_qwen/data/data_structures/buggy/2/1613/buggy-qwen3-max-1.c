#include<stdio.h>
#include<math.h>
#include<string.h> 
#include<stdlib.h>

int main()
{
    int x1, x2, x3;
    char a1, a2, a3;
    x1=0;
    a1='+';
    while(a1!='=')
    {
        scanf("%d %c", &x2, &a2);
        while(a2=='*'||a2=='/')
        {
            scanf("%d %c", &x3, &a3);
            if(a2=='*')
            {
                x2*=x3;
            }
            else if(a2=='/')
            {
                x2/=x3;
            }
            a2=a3; // @@ [The original code incorrectly assigns x2 = x3, which overwrites the accumulated result of multiplication/division with the new operand. It should update the operator (a2) to the next one (a3) to continue parsing correctly.]
        }
        if(a1=='+')
        {
            x1+=x2;
        }
        else if(a1=='-')
        {
            x1-=x2;
        }
        a1=a2;
    }
    printf("%d", x1);
    return 0;
}