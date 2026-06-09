#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s); // @@ gets() is unsafe and may cause buffer overflow; also, it's not standard C and may not be available in all compilers.
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++) // @@ The loop starts at i=2, skipping the first two characters (including the decimal point), but the logic for handling the first non-zero digit after the decimal point is incorrect. It does not properly handle cases where the first non-zero digit is at position 2 or later, and the exponent calculation (num=valid-dot) is wrong.
      {
          if(s[i]!='0')
          {
              printf("%c",s[i]);
              if(num==0)
              {
              valid=i;
              num=valid-dot; // @@ The exponent calculation is incorrect. For numbers like 0.001, the exponent should be -3, but this calculates num = 3 - 1 = 2, leading to e-2 instead of e-3.
              }
      
              if(flag==1&&i!=len-1)
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
                 num=dot-1; // @@ The exponent calculation is incorrect. For numbers like 123.45, the exponent should be 2 (since 1.2345e2), but this calculates num = 3-1 = 2, which is correct for this case. However, it does not handle cases where there are leading zeros before the decimal point (e.g., 0.123 should go to the first branch).
              } 
          }
          printf("e%d",num);
          
     }
      
   return 0;
}