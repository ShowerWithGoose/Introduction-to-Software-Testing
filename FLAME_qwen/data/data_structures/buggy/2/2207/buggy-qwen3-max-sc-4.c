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
        scanf("%d %c",&a2,&op2);   // @@ [The format specifier "%d %c" may fail to correctly parse input with spaces or when '=' is read as op2, leading to undefined behavior. Also, the logic for handling subtraction is incorrect: it computes a2 - a1 instead of a1 - a2.]
   
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
            a1=a2-a1; // @@ [Incorrect subtraction order: should be a1 -= a2 (i.e., a1 = a1 - a2), not a1 = a2 - a1. This reverses the operands and produces wrong results for subtraction.]
        op1 = op2;   
    }
 
    printf("%d",a1);
 
    return 0;
}