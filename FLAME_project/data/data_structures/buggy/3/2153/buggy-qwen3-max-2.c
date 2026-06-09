#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s);
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [cnt is uninitialized, leading to undefined behavior; also, this loop assumes there is always a '.', which may not be safe, but the problem guarantees it]
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;} // @@ [This branch handles numbers like "5.3" as "5.3e0", but according to the problem, if there's only one digit before '.', and it's non-zero, it should be normalized to "5.3e0" — however, the real issue is that cnt is garbage due to no initialization]
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ [Fails to insert decimal point after first significant digit; e.g., outputs "91234...e-8" instead of "9.1234...e-8"]
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1); // @@ [cnt was never initialized to 0, so its value is indeterminate; even if fixed, exponent calculation may be off because cnt counts digits before '.', but loop starts at 0 and stops at '.', so for "29.8", cnt becomes 2, then prints e1 (2-1=1) which is correct, but only if cnt started at 0]
}