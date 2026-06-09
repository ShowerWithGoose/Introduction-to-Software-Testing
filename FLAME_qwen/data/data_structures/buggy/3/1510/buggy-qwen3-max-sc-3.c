#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s); // @@ [Using `gets()` is unsafe and deprecated; it can cause buffer overflow and is removed in C11. Should use `fgets()` instead. Also, this may cause compilation errors or warnings depending on compiler settings.]
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++) // @@ [Loop starts at index 2 assuming input format "0.digits", but if input is just "0" or "0." without digits, this loop won't handle it correctly. Also, if the input has no decimal point, this logic fails.]
      {
          if(s[i]!='0')
          {
              printf("%c",s[i]);
              if(num==0)
              {
              valid=i;
              num=valid-dot; // @@ [This computes exponent as `i - 1`, but correct exponent for scientific notation when leading zeros exist should be negative of (position after decimal where first non-zero appears). For example, "0.00123" should give exponent -3, but this may compute incorrectly due to indexing assumptions.]
              }
      
              if(flag==1&&i!=len-1) // @@ [This condition prints a decimal point after the first significant digit only if it's not the last character. However, if there's only one significant digit (e.g., "0.005"), it won't print a decimal point, violating the requirement that base must have one digit before and after decimal if it's a decimal.]
              {
                  printf(".");flag=0;
              }
          }
      }
      
      printf("e-%d",num); // @@ [If no non-zero digit is found (e.g., input "0.000"), `num` remains 0, leading to output like "e-0", which is invalid since exponent should reflect actual position. Also, the program doesn't handle all-zero inputs as per problem constraints (which say all digits are significant, so this case may not occur, but logic is fragile).]
  }
  else
  {
          
          printf("%c.",s[0]); // @@ [Always prints a decimal point even if the number has only one digit total (e.g., input "5" becomes "5." which violates the rule: if base is integer, it should have no decimal point. The problem states: if only one digit before decimal, it can be 0; otherwise first digit non-zero. But for numbers like "5", scientific notation should be "5e0", not "5.e0".]
          for(int i=1;i<=len-1;i++)
          {
              if(s[i]!='.')
              {
                  printf("%c",s[i]);
              }
             else
             {
                 dot=i;
                 num=dot-1; // @@ [`num` is only set if a '.' is encountered. If input has no decimal point (e.g., "123"), `num` remains uninitialized (0), leading to wrong exponent (e.g., "1.23e0" instead of "1.23e2"). This causes incorrect output for integers without decimal points.]
              } 
          }
          printf("e%d",num); // @@ [If input has no decimal point, `num` is 0 (uninitialized behavior actually—since `num` was initialized to 0 at declaration, but logically wrong), so exponent is wrong. For "123", expected "1.23e2", but outputs "1.23e0".]
          
     }
      
   return 0;
}