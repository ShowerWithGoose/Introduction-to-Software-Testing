#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s); // @@ gets() has been removed from the C11 standard and causes a compilation error in modern compilers; use scanf("%s", s) or fgets() instead.
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++;
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;}
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ Logical error: fails to insert a decimal point after the first significant digit for numbers less than 1, violating the required output format.
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1);
}