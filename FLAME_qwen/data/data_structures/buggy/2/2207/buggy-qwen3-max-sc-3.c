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
    op1 = '+'; // @@ [The initial operator is set to '+', but the first number read should be treated as the starting value. However, the logic below subtracts incorrectly when op1 is '-', and more critically, the subtraction logic is inverted.]
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
            a1=a2+a1;
        else if(op1=='-')
            a1=a2-a1; // @@ [This is incorrect: it should be a1 = a1 - a2, not a2 - a1. This reverses the operands in subtraction, leading to wrong results.]
        op1 = op2;   
    }
 
    printf("%d",a1);
 
    return 0;
}