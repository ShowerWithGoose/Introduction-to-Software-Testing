#include<stdio.h>
#include<string.h>
int main()
{
  char s[1000];
  int i,a,b,j;
  gets(s); // @@ gets() is unsafe and may cause buffer overflow; use fgets() instead
  for(i=0;s[i]!='\0';i++)
  {
      if(s[i]=='-')
      {
       a=s[i-1];
       b=s[i+1];
       if(a<b&&a>=48&&b<=57) // @@ Condition should check both a and b are digits: a>=48 && b<=57 && a<=57 && b>=48
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ Condition should check both a and b are lowercase letters: a>=97 && b<=122 && a<=122 && b>=97
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ Condition is incorrect: should check uppercase letters (a>=65 && b<=90 && a<=90 && b>=65), but uses b<=57 (digits) instead
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
       else
       {
           printf("%c",'-'); // @@ Should print the '-' character directly, not as a character constant with quotes; use printf("-") or printf("%c", '-')
       }
    }
    else
    printf("%c",s[i]);
    
  }
  return 0;
}