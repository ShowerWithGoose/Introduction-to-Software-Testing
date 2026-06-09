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
      
              if(flag==1&&i!=len-1) // @@ The condition `i!=len-1` incorrectly stops printing the decimal point if the first significant digit is the last character, but more importantly, it fails to print the decimal point after the first significant digit if there are subsequent digits. The logic `flag==1` ensures the dot is printed only once after the first non-zero digit. However, the condition `i!=len-1` prevents printing the dot if the first non-zero digit is at the very end of the string (which implies no fractional part follows, so maybe correct?), BUT the main issue is that it prints the dot *before* checking if there are more digits. Actually, the standard scientific notation requires a dot if there are digits after the first one. The current code prints the dot immediately after the first significant digit if `flag==1`. The error is that `flag` is set to 0, so subsequent digits don't trigger the dot. This part is actually okay for placing the dot. The real error is likely in how trailing zeros or all digits are handled. Let's look closer. The input is `0.00000009123456789012`. The first non-zero is '9' at index 9. `valid`=9, `dot`=1, `num`=8. It prints '9'. Then `flag==1` and `i!=len-1` (9 != 21), so it prints '.'. `flag` becomes 0. Then it continues loop. For i=10 to 21, it prints s[i]. This seems correct for this case. Wait, let's re-read the buggy output: `9.12345678912e-8`. Expected: `9.123456789012e-8`. The buggy output is missing `012` at the end? No, `9.12345678912` has 11 digits after dot. Input `9123456789012` has 13 digits. The buggy output truncated the last two digits `012`? Or maybe `9012` became `12`? Let's trace carefully.
              // The loop runs from i=2 to len-1.
              // Input: 0.00000009123456789012
              // Indices: 0:'0', 1:'.', 2:'0' ... 8:'0', 9:'9', 10:'1', 11:'2', 12:'3', 13:'4', 14:'5', 15:'6', 16:'7', 17:'8', 18:'9', 19:'0', 20:'1', 21:'2'
              // i=9: s[9]='9'. Print '9'. num=0 -> valid=9, num=8. flag=1, i!=21 -> Print '.', flag=0.
              // i=10: s[10]='1'. Print '1'.
              // ...
              // i=18: s[18]='9'. Print '9'.
              // i=19: s[19]='0'. Print '0'.
              // i=20: s[20]='1'. Print '1'.
              // i=21: s[21]='2'. Print '2'.
              // Output so far: 9.123456789012. This matches expected base.
              // Why did the buggy output say `9.12345678912e-8`?
              // Ah, I might have miscounted the input length or indices.
              // Let's check the provided Buggy Output again: `9.12345678912e-8`.
              // It seems digits `0` and `1` before the final `2` are missing? Or `9012` became `12`?
              // If the code is correct logically for this path, where is the error?
              
              // Let's look at the `else` branch (number >= 1).
              // The problem states: "If there’s only one digit before the decimal point, it can be 0".
              // The code handles `s[0]=='0'` separately.
              
              // Is it possible `gets` is reading incorrectly? No.
              // Is it possible `strlen` is wrong? No.
              
              // Let's look at the `flag` logic again.
              // `if(flag==1&&i!=len-1)`
              // If the first significant digit is NOT the last character, print dot.
              // This is correct.
              
              // Wait, look at the Buggy Output provided in the prompt: `9.12345678912e-8`.
              // My trace produced `9.123456789012e-8`.
              // Why would the provided "Buggy Output" differ from my trace of the "Source Code"?
              // Perhaps the "Source Code" provided IS the buggy code, and I need to find why IT produces the wrong answer.
              // But my trace shows it SHOULD produce the right answer for that specific input.
              
              // Let's re-read the code carefully.
              // `for(int i=2;i<=len-1;i++)`
              // `if(s[i]!='0')`
              // Inside this block:
              // `printf("%c",s[i]);`
              // `if(num==0) { valid=i; num=valid-dot; }`
              // `if(flag==1&&i!=len-1) { printf(".");flag=0; }`
              
              // What if there are zeros BETWEEN significant digits?
              // e.g. `9.01`.
              // i points to '9'. Print '9'. Dot printed.
              // i points to '0'. `s[i]!='0'` is FALSE. It skips printing '0'.
              // THIS IS THE ERROR.
              // The code only prints non-zero digits after the decimal point in the `s[0]=='0'` case.
              // It skips any '0' that appears after the first significant digit.
              // In `0.00000009123456789012`, the '0' at index 19 is skipped.
              // So it prints 9, then dot, then 1,2,3,4,5,6,7,8,9, (skips 0), 1, 2.
              // Result: `9.12345678912`.
              // This matches the Buggy Output exactly!
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