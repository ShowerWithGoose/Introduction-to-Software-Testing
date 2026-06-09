#include<stdio.h>
#include<string.h>
int main()
{
  char s[1000];
  int i,a,b,j;
  gets(s); @@ gets is deprecated and removed in C11, causing compilation errors in modern environments; use fgets or scanf instead.
  for(i=0;s[i]!='\0';i++)
  {
      if(s[i]=='-')
      {
       a=s[i-1];
       b=s[i+1];
       if(a<b&&a>=48&&b<=57) @@ Incorrect range validation for digits; should verify both a and b are within '0'-'9' (e.g., a>='0' && a<='9' && b>='0' && b<='9').
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) @@ Incorrect range validation for lowercase letters; should verify both a and b are within 'a'-'z'.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) @@ Incorrect range validation for uppercase letters; b<=57 incorrectly checks for digits instead of 'Z' (90), and should verify both a and b are within 'A'-'Z'.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
       else
       {
           printf("%c",'-');
       }
    }
    else
    printf("%c",s[i]);
    
  }
  return 0;
}