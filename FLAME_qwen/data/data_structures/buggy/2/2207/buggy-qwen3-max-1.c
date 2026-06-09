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
    op1 = '+'; // @@ [The initial operator is set to '+', but the logic for subtraction in the accumulation step is incorrect: it computes a1 = a2 - a1 instead of a1 = a1 - a2.]
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
            a1=a2-a1; // @@ [This line incorrectly subtracts a1 from a2 (a2 - a1) instead of subtracting a2 from a1 (a1 - a2), which reverses the intended operation and leads to wrong results.]
        op1 = op2;   
    }
 
    printf("%d",a1);
 
    return 0;
}