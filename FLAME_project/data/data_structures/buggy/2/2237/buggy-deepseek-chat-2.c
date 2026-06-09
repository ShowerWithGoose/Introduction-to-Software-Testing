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
          a+=b;op1=op2;} // @@ Error: The assignment op1=op2 should be placed after the if-else block, not inside the if block. Currently, when op1 is '+', op1 is updated to op2 inside the if, but when op1 is '-', op1 is updated in the else block. However, the else block is missing the op1=op2 assignment, causing op1 to not be updated when op1 is '-', leading to an infinite loop or incorrect processing. Additionally, the logic for handling the first number is incorrect; the reference program initializes a=0 and uses op1='+' to handle the first term, but this code reads the first number into a directly, which changes the algorithm.
        else
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a);
}