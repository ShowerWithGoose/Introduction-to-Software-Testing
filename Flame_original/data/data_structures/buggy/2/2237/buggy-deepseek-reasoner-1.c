#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c;
    char op1,op2,op3;
    scanf("%d %c",&a,&op1); // @@ Error: This reads the first operator into op1, but the program only handles '+' and '-' for op1 correctly. Expressions starting with '*' or '/' will be mishandled because op1 is not initialized to '+' as in the reference program.
    while(op1!='=') // @@ Error: The loop condition uses op1, which may be '*' or '/', leading to incorrect behavior in the first iteration. The reference program initializes op1='+' and reads the first number separately.
    {
      scanf("%d %c",&b,&op2);
      while(op2=='*'||op2=='/')
      {
          scanf("%d %c",&c,&op3);
          if(op2=='*')b*=c;
          else  b=b/c;
          op2=op3;
      }  
          if(op1=='+') // @@ Error: This if-else only handles '+' and '-'. If op1 is '*' or '/', the else branch incorrectly applies subtraction, leading to wrong results.
          {
          a+=b;op1=op2;}
        else
        {
            a-=b;op1=op2; // @@ Error: The else branch assumes op1 is '-' but it could be '*' or '/', causing an incorrect operation.
        }

      }
    printf("%d",a);
}