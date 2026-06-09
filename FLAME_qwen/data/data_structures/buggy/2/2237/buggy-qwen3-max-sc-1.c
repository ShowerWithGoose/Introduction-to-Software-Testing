#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c;
    char op1,op2,op3;
    scanf("%d %c",&a,&op1);
    while(op1!='=')
    {
      scanf("%d %c",&b,&op2);
      while(op2=='*'||op2=='/')
      {
          scanf("%d %c",&c,&op3);
          if(op2=='*')b*=c;
          else  b=b/c; @@ [This performs division even when op2 is not '/', e.g., when op2 is '=' or '+', leading to incorrect behavior. It should only divide when op2 is '/'.]
          op2=op3;
      }  
          if(op1=='+')
          {
          a+=b;op1=op2;}
        else
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a); @@ [Missing newline in output; problem doesn't require it, but more critically, the logic fails when the expression starts with subtraction or has consecutive operators due to incorrect handling of initial state and operator precedence boundaries. Also, the program does not handle the case where the first number is negative or the expression ends immediately after '=' without proper termination. However, the primary logical error is in the 'else' branch above that forces division for any non-'*' operator in the inner loop.]
}