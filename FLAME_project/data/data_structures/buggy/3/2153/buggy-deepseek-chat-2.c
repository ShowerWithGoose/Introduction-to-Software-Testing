#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s);
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++;
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;}
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ Error: This prints the entire remaining string after leading zeros, but the expected output requires only one digit before the decimal point (e.g., "9.") and the rest after. The code should output the first non-zero digit, a decimal point, and the remaining digits, then the exponent.
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1);
}