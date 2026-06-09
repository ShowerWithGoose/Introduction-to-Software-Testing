#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more critically, it doesn't handle input correctly when there are leading spaces or empty inputs, but the main issue here is logic error in parsing]
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++) // @@ [Loop starts at i=2 assuming "0." format, but fails to account for cases where significant digits start later; also, it prints every non-zero digit immediately without storing, causing loss of trailing zeros that are significant]
      {
          if(s[i]!='0')
          {
              printf("%c",s[i]);
              if(num==0)
              {
              valid=i;
              num=valid-dot; // @@ [num = i - 1, which gives exponent as (position after decimal), but should be negative exponent: e.g., '0.0009' → 9e-4, so exponent = -(i - 1). Here it computes positive num, then prints e-num, which is correct in sign, but logic is fragile]
              }
      
              if(flag==1&&i!=len-1) // @@ [This condition prints '.' after first non-zero digit only if it's not the last character, but it skips printing subsequent digits if they are zero, which violates "all digits are significant" — e.g., '0.00000009123456789012' loses the '0' before '12' at the end because zeros between non-zeros are skipped in output]
              {
                  printf(".");flag=0;
              }
          }
      }
      
      printf("e-%d",num);
  }
  else
  {
          
          printf("%c.",s[0]);
          for(int i=1;i<=len-1;i++)
          {
              if(s[i]!='.')
              {
                  printf("%c",s[i]);
              }
             else
             {
                 dot=i;
                 num=dot-1; // @@ [This assigns num based on position of '.', but if there's no decimal point, dot remains 0, leading to incorrect exponent. Also, this branch assumes number has decimal point, but problem allows integers like "123" → "1.23e2"]
              } 
          }
          printf("e%d",num);
          
     }
      
   return 0;
}