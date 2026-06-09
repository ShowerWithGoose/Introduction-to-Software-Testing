#include<stdio.h>
#include<math.h>
#include<string.h>
char s[1000001]; // @@ [Array size reduced from 10000001 to 1000001 to avoid potential memory issues, but original may be acceptable; however, the real error is use of gets()]
int len,cnt;
int main()
{
   gets(s); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow and is removed in C11; should use fgets instead]
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [If input has no '.', this loop runs past end of string causing undefined behavior; also 'cnt' is uninitialized]
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;}
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1; // @@ [If all digits after decimal are zero or string ends early, this may read beyond null terminator]
      printf("%se-%d",s+cnt,cnt-1);
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1); // @@ ['cnt' may be uninitialized if input contains no decimal point, leading to undefined behavior]
}