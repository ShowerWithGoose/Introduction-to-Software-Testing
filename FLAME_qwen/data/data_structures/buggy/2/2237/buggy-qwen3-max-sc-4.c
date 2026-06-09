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
          else  b=b/c; @@ [This performs division even when op2 is not '/', e.g., if op2 is '=' or '+', leading to incorrect behavior. It should only divide when op2 is '/'.]
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
    printf("%d",a); @@ [Missing newline in output; problem doesn't require it, but more critically, the logic fails for expressions starting with subtraction or handling operator precedence correctly due to flawed control flow. However, the primary semantic error is in the 'else' used for division.]
}