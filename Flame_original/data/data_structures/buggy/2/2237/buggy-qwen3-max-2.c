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
    printf("%d",a); @@ [Missing newline in output; though not causing compilation error, the main issue is logic. However, the reported error was "gcc: not found", which is environment-related, but assuming the real issue is logical: the program doesn't handle initial operator correctly and misuses else for division. Also, the loop may read past '=' because after reading '=', op2 becomes '=', but inner while condition fails, then outer loop uses op1 (which might be last operator) and processes b with op2='=', then sets op1='=', and exits. However, the critical flaw is using 'else' for division: it assumes if not '*', then must be '/', but op2 could be '+' or '-' or '=' at that point, causing erroneous division.]
}