#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c; // @@ Variable 'a' is uninitialized. It should be initialized to 0 to correctly serve as the accumulator for the expression result.
    char op1,op2,op3; // @@ Variable 'op1' is uninitialized. It should be initialized to '+' to match the reference logic and ensure correct operator handling from the start.
    scanf("%d %c",&a,&op1);
    while(op1!='=')
    {
      scanf("%d %c",&b,&op2);
      while(op2=='*'||op2=='/')
      {
          scanf("%d %c",&c,&op3);
          if(op2=='*')b*=c;
          else  b=b/c;
          op2=op3;
      }  
          if(op1=='+')
          {
          a+=b;op1=op2;}
        else // @@ The 'else' block implicitly assumes 'op1' is '-', which may cause incorrect subtraction if 'op1' holds an unexpected value. Using a separate 'if(op1=='-')' is safer.
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a);
}