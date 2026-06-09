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
    printf("%d",a); // @@ [The program incorrectly assumes the first operator applies to the initial value 'a' as if it were preceded by '+', but fails to handle cases where the expression starts with a negative term or misaligns operator precedence across segments. More critically, it does not correctly manage operator chaining when multiple low-precedence operators (+/-) appear after high-precedence groups (*//), because 'op1' is updated to 'op2' even when 'op2' might be '=' or part of a new segment, leading to incorrect accumulation. In the given test case, this causes mis-evaluation of the final large multiplication/division group and subsequent addition/subtraction.]
}