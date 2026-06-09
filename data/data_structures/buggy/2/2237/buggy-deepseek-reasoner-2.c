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
          else  b=b/c;
          op2=op3;
      }  
          if(op1=='+') // @@ The code assumes the first operator is only '+' or '-', but it can also be '*' or '/', leading to incorrect evaluation.
          {
          a+=b;op1=op2;}
        else // @@ The else branch incorrectly treats all other first operators (including '*' and '/') as subtraction, which violates operator precedence.
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a);
}