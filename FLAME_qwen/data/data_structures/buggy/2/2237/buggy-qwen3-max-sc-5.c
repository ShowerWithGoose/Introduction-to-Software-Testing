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
          a+=b;op1=op2;}
        else
        {
            a-=b;op1=op2;
        }

      }
    printf("%d",a); // @@ [Missing newline in output may not match expected format exactly, but more critically: the program does not handle initial operator correctly if expression starts with '-', and fails to account for operator precedence across full expression due to flawed parsing logic. However, the reported error is "Compilation Error" with message "gcc: not found", which is not a code issue but environment issue. But assuming the real problem is logical: the code assumes first token is a number followed by an operator, but doesn't initialize op1 properly if input starts differently. Also, when op2 becomes '=' inside inner loop, op3 is never read, leading to undefined behavior. Most critically, after processing * and /, if op2 is '=', the outer loop should terminate, but the code still tries to apply op1 (which might be '+' or '-') to b, even though '=' means end. This leads to processing an extra operand incorrectly.]
}