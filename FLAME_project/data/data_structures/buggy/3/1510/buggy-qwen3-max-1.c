#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; more critically, it doesn't handle input correctly when there are leading spaces or empty input, but the main issue here is logic error in parsing]
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++) // @@ [Loop starts at i=2 assuming "0." format, but skips s[1] which should be '.'; however, the real bug is that it prints every non-zero digit immediately without storing or counting properly, and truncates output due to incorrect loop bounds and printing logic]
      {
          if(s[i]!='0')
          {
              printf("%c",s[i]); // @@ [Prints significant digit immediately, but then later tries to print decimal point and remaining digits without proper control—this causes premature output and loss of trailing digits like '0' in '9012']
              if(num==0)
              {
              valid=i;
              num=valid-dot; // @@ [num = i - 1, which gives position after decimal; but exponent should be -(i - 1), and this calculation is off by one in usage]
              }
      
              if(flag==1&&i!=len-1) // @@ [This condition prints '.' after first non-zero digit only if it's not the last character, but fails to account for all subsequent digits including zeros that are significant (e.g., the '0' in '9012' is skipped because loop only prints non-zero digits)]
              {
                  printf(".");flag=0;
              }
          }
      }
      
      printf("e-%d",num); // @@ [Exponent is positive num, but should be negative: e.g., 0.000...9 at position i=8 (0-indexed) means exponent -8, but num = 8 - 1 = 7, so prints e-7 instead of e-8; also, missing digits due to skipping zeros]
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
                 num=dot-1; // @@ [This branch assumes number >= 1, but problem states input can have only one digit before decimal which can be 0, so this else branch may not even execute for valid inputs like "1.23"; however, main test case is in the 'if' branch so this isn't the primary error]
              } 
          }
          printf("e%d",num);
          
     }
      
   return 0;
}