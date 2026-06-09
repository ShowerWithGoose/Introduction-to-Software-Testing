#include<stdio.h>
#include<math.h>
#include<string.h>
char s[1000001]; // @@ [Array size reduced from 10000001 to 1000001 to avoid potential memory issues, but original size may be acceptable; however, the real errors are below]
int len,cnt;
int main()
{
   gets(s); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Also, in many modern compilers/environments, gets() is not available, leading to compilation error. Should use fgets() instead.]
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [cnt is uninitialized; using it here leads to undefined behavior. Also, if there's no '.' in the input, this loop runs past the string end causing out-of-bounds access.]
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
   printf("e%d",cnt-1); // @@ [cnt may be uninitialized or incorrect if the input has no decimal point, leading to wrong exponent or undefined behavior.]
}