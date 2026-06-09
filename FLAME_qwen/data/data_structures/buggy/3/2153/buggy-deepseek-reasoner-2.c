#include<stdio.h>
#include<math.h>
#include<string.h>
char s[10000001];
int len,cnt; // @@ [cnt is not initialized, leading to undefined behavior when used in the for loop on line 9]
int main()
{
   gets(s); // @@ [gets is deprecated and removed in C11; using it may cause compilation error or security warning]
   len=strlen(s);
   for(int i=0;s[i]!='.';i++) cnt++; // @@ [cnt was not initialized, so this loop increments an indeterminate value]
   if(cnt==1&&s[0]!='0') {printf("%se0",s);return 0;}
   if(s[0]=='0') 
   {
      cnt=2;
      while(s[cnt]=='0') cnt+=1;
      printf("%se-%d",s+cnt,cnt-1); // @@ [This prints the entire remaining substring without inserting a decimal point after the first digit, e.g., "0.00123" becomes "123e-3" instead of "1.23e-3"]
      return 0;
   }
   printf("%c.",s[0]);
   for(int i=1;i<len;i++) if(s[i]!='.') putchar(s[i]);
   printf("e%d",cnt-1);
}