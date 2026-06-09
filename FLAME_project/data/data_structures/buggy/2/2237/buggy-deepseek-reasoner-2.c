#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c;
    char op1,op2,op3;
    scanf("%d %c",&a,&op1); // @@ Error: This reads the first number into a and the first operator into op1. However, the reference program initializes a=0 and op1='+', then reads the first number into b and operator into op2. This mis-handles leading high-precedence operators (like '/' or '*'), because later op1 is assumed to be only '+' or '-'.
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
          if(op1=='+') // @@ Error: op1 can be '*' or '/' at this point (from the initial read). This condition only handles '+' correctly; for other operators it goes to the else branch, which is incorrect for '*' and '/'.
          {
          a+=b;op1=op2;}
        else // @@ Error: This else branch assumes op1 is '-', but op1 could be '*' or '/', causing wrong arithmetic (e.g., treating '/' as '-'). It should handle all operator types properly.
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a);
}