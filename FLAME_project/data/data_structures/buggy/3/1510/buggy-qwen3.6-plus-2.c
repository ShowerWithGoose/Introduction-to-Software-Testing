#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s);
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++)
      {
          if(s[i]!='0')
          {
              printf("%c",s[i]);
              if(num==0)
              {
              valid=i;
              num=valid-dot;
              }
      
              if(flag==1&&i!=len-1) // @@ The condition `i!=len-1` incorrectly stops printing the decimal point if the first significant digit is the last character, but more importantly, the logic for printing the decimal point is flawed. It prints '.' after the first non-zero digit if flag is 1. However, the problem requires that if there are more digits after the first significant one, a decimal point follows the first significant digit. The current logic prints the first significant digit, then checks if it's not the last char to print '.', which is correct for the position, BUT the loop continues to print subsequent digits. The issue in the specific test case `0.00000009123456789012` is that the code correctly identifies '9' as the first significant digit. It prints '9'. Then `num` becomes 8. `flag` is 1. `i` is index of '9'. Is `i != len-1`? Yes. So it prints '.'. Then `flag` becomes 0. The loop continues. It prints '1', '2', ... '0', '1', '2'. This part seems logically okay for structure. Let's look closer at the output. Buggy: `9.12345678912e-8`. Expected: `9.123456789012e-8`. The buggy output is missing `012` at the end and has `12` instead of `012`? No, `9.12345678912` vs `9.123456789012`. The buggy output truncated the trailing `012` or misread it. Wait, looking at the input `0.00000009123456789012`. The digits after 9 are `123456789012`. The buggy output prints `12345678912`. It skipped the `0`. Why? The loop `for(int i=2;i<=len-1;i++)` iterates through all characters after "0.". Inside, `if(s[i]!='0')` skips zeros. This is the error. Scientific notation preserves all significant digits, including zeros between non-zero digits. The code explicitly skips any '0' character in the fractional part when `s[0]=='0'`.
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
                 num=dot-1;
              } 
          }
          printf("e%d",num);
          
     }
      
   return 0;
}