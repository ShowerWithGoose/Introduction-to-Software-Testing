#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c;
    char op1,op2,op3;
    scanf("%d %c",&a,&op1); // @@ Reads the first operator into op1, but the subsequent logic assumes op1 is only '+' or '-', causing incorrect calculations if the expression starts with '*' or '/'.
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
          if(op1=='+') // @@ Only checks for '+', failing to handle cases where op1 is '*' or '/', which incorrectly falls through to the else block.
          {
          a+=b;op1=op2;}
        else
        {
            a-=b;op1=op2; // @@ Incorrectly defaults to subtraction for any operator other than '+', including '*' and '/'.
        }

      }
    printf("%d",a);
}