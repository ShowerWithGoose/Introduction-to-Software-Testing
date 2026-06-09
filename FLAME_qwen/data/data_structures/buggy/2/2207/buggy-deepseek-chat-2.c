#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
int main()
{
    int a1,a2,a3;
    char op1,op2,op3;
    a1 = 0;
    op1 = '+';
    while(op1!='=')
    {
        scanf("%d %c",&a2,&op2);   
   
        while(op2=='*' || op2=='/')
        {
            scanf("%d %c",&a3,&op3);
            if(op2=='*')
                a2 *= a3;
            else if(op2=='/')
                a2 /= a3;
            op2 = op3;   
        }
      
        if(op1=='+')
            a1=a2+a1; // @@ [Error: The order of subtraction is wrong. For subtraction, the expression should be a1 = a1 - a2, not a1 = a2 - a1. This causes incorrect results when subtracting.]
        else if(op1=='-')
            a1=a2-a1; // @@ [Error: The order of subtraction is wrong. For subtraction, the expression should be a1 = a1 - a2, not a1 = a2 - a1. This causes incorrect results when subtracting.]
        op1 = op2;   
    }
 
    printf("%d",a1);
 
    return 0;
}