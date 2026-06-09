#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s); // @@ [gets() is unsafe and removed from C11 standard; use fgets() instead]
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [If there is no '.' in the input, this loop will run out of bounds, causing undefined behavior]
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;} // @@ [When cnt==1 and s[0]!='0', the input has no decimal point, but the loop assumes a '.' exists; also, printing the whole string s may include a newline from gets()]
   if(s[0]=='0') 
   {
      cnt=2; // @@ [This assumes the decimal point is at index 1, but if input is "0.xxx", the '.' is at index 1, so cnt should be 1, not 2; also, if input is "0" alone, this logic fails]
      while(s[cnt]=='0') cnt+=1; // @@ [If s[cnt] is '\0' (end of string), this loop will continue past the string, causing out-of-bounds access]
      printf("%se-%d",s+cnt,cnt-1); // @@ [s+cnt points to the first non-zero digit after the decimal, but the exponent calculation cnt-1 is incorrect; also, if there are no digits after the decimal, this prints nothing]
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1); // @@ [cnt is the position of the decimal point, but for numbers like "12.34", cnt=2, exponent should be 1, not cnt-1=1 (correct here by coincidence); for "123.45", cnt=3, exponent should be 2, but cnt-1=2 (correct); however, for numbers with no decimal point, cnt is uninitialized or wrong]
}