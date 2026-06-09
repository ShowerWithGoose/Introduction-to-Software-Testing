#include<stdio.h>
#include<math.h>
#include<string.h>
char s[1000001]; // @@ [Array size mismatch: original declaration was 10000001 which is unusually large and may cause stack overflow; however, the real error is use of gets()]
int len,cnt;
int main()
{
   gets(s); // @@ [Use of unsafe and deprecated function 'gets' which was removed in C11; causes compilation error with modern compilers]
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [If input has no '.', loop runs past string end causing undefined behavior; also 'cnt' is uninitialized]
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
   printf("e%d",cnt-1);
}