#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks.]
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [If the input has no decimal point, this loop runs past the end of the string, causing undefined behavior and potentially a crash or incorrect 'cnt'. Also, 'cnt' is uninitialized, leading to unpredictable results.]
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;}
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1);
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1); // @@ ['cnt' may be uninitialized or incorrect if the input lacks a decimal point, leading to wrong exponent output.]
}