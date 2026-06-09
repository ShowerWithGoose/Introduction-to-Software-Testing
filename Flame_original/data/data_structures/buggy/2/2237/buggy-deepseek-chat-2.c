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
          else  b=b/c; // @@ The else branch incorrectly uses integer division for all non-multiplication cases, but op2 could be '/' only; however, the logic is correct for this specific case, but the else is unnecessary and could cause issues if op2 is not '/' (though it always is here). The real error is that the program does not handle the case where the first number is read and op1 is '=', but the main issue is missing handling of the initial operator.
          op2=op3;
      }  
          if(op1=='+')
          {
          a+=b;op1=op2;} // @@ Missing semicolon after a+=b? Actually there is a semicolon, but the brace placement is odd. The real error: after a+=b, op1=op2 is inside the if block, but the else block also sets op1=op2. This is fine, but the program fails to handle the case where the expression starts with a negative number or has no initial operator. The main error is that the program does not correctly initialize op1 and handle the first number properly; it assumes the first operator is always '+' or '-', but the reference program initializes op1='+' and reads the first number as a2. This program reads a and op1, but if op1 is '=', it exits immediately, which is incorrect for a valid expression.
        else
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a);
}