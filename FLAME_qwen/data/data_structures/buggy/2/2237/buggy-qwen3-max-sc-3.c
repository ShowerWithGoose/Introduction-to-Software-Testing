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
          else  b=b/c; @@ [This performs division even when op2 is not '/', e.g., if op2 is '=', it will still do division due to using 'else' instead of 'else if (op2 == '/')']
          op2=op3;
      }  
          if(op1=='+')
          {
          a+=b;op1=op2;}
        else
        {
            a-=b;op1=op2; @@ [This assumes op1 is either '+' or '-', but op1 could be other values (e.g., from initial input), leading to incorrect behavior. Also, after processing multiplication/division, op2 might be '=', and assigning it to op1 ends loop, but subtraction is applied incorrectly if original op1 wasn't '-']
        }

      }
    printf("%d",a);
}