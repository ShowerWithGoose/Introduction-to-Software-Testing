#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt; // @@ cnt is uninitialized; it should be initialized to 0 before use.
int main()
{
   gets(s); // @@ gets() is unsafe and deprecated; may cause buffer overflow, but not the main logical error.
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ cnt is used without initialization, leading to undefined behavior. Also, if no '.' exists, this loop may run out of bounds.
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;} // @@ Relies on cnt which is garbage; the logic itself duplicates the general case but is acceptable if cnt were correct.
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ Incorrect: for numbers like "0.15", this outputs "15e-2" instead of "1.5e-2". It omits the decimal point after the first non-zero digit.
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1); // @@ cnt is still uninitialized in this branch, making the exponent incorrect.
}