#include<stdio.h>
#include<string.h>
int main()
{
    int a,b,c;
    char op1,op2,op3;
    scanf("%d %c",&a,&op1); // @@ Error: reads first number into a and first operator into op1; should initialize a=0, op1='+' and read first number into b instead.
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
          if(op1=='+') // @@ Error: op1 may be '*' or '/' from the first operator, but this condition only handles '+' and '-'.
          {
          a+=b;op1=op2;}
        else
        {
            a-=b;op1=op2; // @@ Error: for op1 = '/' or '*', subtraction is incorrect; should perform the corresponding operation on a and b.
        }

      }
    printf("%d",a);
}