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
          if(op1=='+')
          {
          a+=b;op1=op2;} // @@ The assignment op1=op2 is inside the if block, but it should be executed after the if-else structure to ensure op1 is updated regardless of the branch taken.
        else
        {
            a-=b;op1=op2; // @@ Same issue: op1=op2 is inside the else block, but it should be moved outside to execute after the if-else.
        }

      }
    printf("%d",a);
}