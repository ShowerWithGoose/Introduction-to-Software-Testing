#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s); // @@ gets() is unsafe and may cause buffer overflow; also, it's not standard C and may not be available in all compilers
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++) // @@ The loop starts from index 2, skipping the decimal point at index 1, but this assumes the input always has exactly one digit before the decimal point (0.x), which may not handle cases like "0.0" or other formats correctly
      {
          if(s[i]!='0')
          {
              printf("%c",s[i]);
              if(num==0)
              {
              valid=i;
              num=valid-dot; // @@ This calculation of exponent is incorrect; it should count the number of zeros after the decimal point before the first non-zero digit, but the logic is flawed
              }
      
              if(flag==1&&i!=len-1)
              {
                  printf(".");flag=0; // @@ The decimal point is placed after the first non-zero digit, but the loop may print multiple digits before the decimal point, violating the requirement of one digit before the decimal point
              }
          }
      }
      
      printf("e-%d",num); // @@ The exponent may be incorrect because num is not properly calculated
  }
  else
  {
          
          printf("%c.",s[0]); // @@ Always prints a decimal point after the first digit, even if the number is an integer (e.g., "123" should output "1.23e2", but this code would output "1.23.e2" incorrectly)
          for(int i=1;i<=len-1;i++)
          {
              if(s[i]!='.')
              {
                  printf("%c",s[i]);
              }
             else
             {
                 dot=i;
                 num=dot-1; // @@ The exponent calculation is incorrect; it should be the number of digits after the decimal point minus one, but this sets num to the position of the decimal point minus one, which is wrong
              } 
          }
          printf("e%d",num); // @@ The exponent may be incorrect due to the flawed calculation
          
     }
      
   return 0;
}