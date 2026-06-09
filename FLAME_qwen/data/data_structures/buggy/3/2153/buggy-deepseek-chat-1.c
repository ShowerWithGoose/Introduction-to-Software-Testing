#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s); // @@ gets() is unsafe and may cause buffer overflow; also, it's deprecated and removed from C11 standard, leading to compilation errors in modern compilers.
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ If there is no '.' in the string, this loop will run past the end of the string, causing undefined behavior.
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;} // @@ When cnt==1 and s[0]!='0', the output should be the original number with "e0", but the problem requires scientific notation with one digit before decimal, which may not be correct if the number has more digits.
   if(s[0]=='0') 
   {
      cnt=2; // @@ This assumes the decimal point is at index 1, but if the input is "0.xxx", the '.' is at index 1, so cnt=2 skips the '.' and the first zero after it, which may be incorrect if there are leading zeros after the decimal.
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ s+cnt is a pointer to the first non-zero digit, but it prints from that digit to the end of the string, which may include the decimal point and trailing digits incorrectly; also, the exponent calculation cnt-1 may be wrong if the decimal point position is not accounted for properly.
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1); // @@ cnt-1 may be incorrect because cnt was incremented in the first loop and may not represent the correct exponent (number of digits before the decimal point minus one) if the loop didn't find a '.'.
}