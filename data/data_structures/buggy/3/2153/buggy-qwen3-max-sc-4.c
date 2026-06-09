#include<stdio.h>
#include<math.h>
#include<string.h>
char s[1000001]; // @@ [Array size reduced from 10000001 to 1000001 to avoid potential memory issues, though not the main error]
int len,cnt;
int main()
{
   gets(s); // @@ [Use of unsafe function 'gets' which was removed in C11; should use fgets instead. This may cause compilation error with modern compilers.]
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [If input has no '.', this loop runs past end of string causing undefined behavior. Also, 'cnt' is uninitialized, leading to unpredictable results.]
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
   printf("e%d",cnt-1); // @@ ['cnt' may be uninitialized or hold incorrect value if input contains no decimal point, leading to wrong exponent.]
}