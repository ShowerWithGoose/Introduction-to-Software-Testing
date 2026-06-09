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
            a2=a3; // @@ [The assignment should update a2 to a3, not x2 to x3. The line "x2=x3;" incorrectly overwrites the accumulated result with the new operand, breaking the calculation logic.]
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