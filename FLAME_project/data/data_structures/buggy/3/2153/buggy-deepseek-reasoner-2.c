#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt;
int main()
{
   gets(s);
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [cnt is uninitialized before this loop, causing undefined behavior]
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;}
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ [Should print decimal point if there are multiple digits after leading zeros, e.g., "%c.%se-%d" instead of "%se-%d"]
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1);
}