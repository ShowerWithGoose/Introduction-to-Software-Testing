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
            a1=a2+a1;
        else if(op1=='-')
            a1=a1-a2; // @@ [The original code `a1=a2-a1` incorrectly subtracts the accumulated result from the current term. For subtraction, we should subtract the current term (`a2`) from the accumulated result (`a1`). For example, if `a1` is 10 and `a2` is 5 (representing 10 - 5), the result should be 10 - 5 = 5, not 5 - 10 = -5.]
        op1 = op2;   
    }
 
    printf("%d",a1);
 
    return 0;
}