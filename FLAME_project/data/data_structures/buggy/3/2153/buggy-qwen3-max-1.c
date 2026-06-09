#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s);
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [cnt is uninitialized, leading to undefined behavior; also, this loop assumes there's always a '.', which may not be safe, but the problem guarantees it. However, the main issue is that cnt starts with garbage value.]
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;}
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ [This prints the entire remaining string as the base without inserting a decimal point after the first digit, violating the requirement that scientific notation must have one digit before the decimal and the rest after (e.g., "9.123..." not "9123...")]
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1); // @@ [Because cnt was uninitialized and incremented from garbage, the exponent is incorrect. Even if cnt were initialized to 0, the logic counts digits before '.', so for "29.8", cnt becomes 2, then exponent is 1 (correct), but due to uninitialized cnt, actual behavior is unpredictable.]
}