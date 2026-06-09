#include<stdio.h>
#include<string.h>
int main()
{
  char s[1000];
  int i,a,b,j;
  gets(s);
  for(i=0;s[i]!='\0';i++)
  {
      if(s[i]=='-')
      {
       a=s[i-1];
       b=s[i+1];
       if(a<b&&a>=48&&b<=57)
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122)
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ Error: The condition checks for uppercase letters (a>=65) but the upper bound is b<=57 (digits), which is inconsistent. It should check b<=90 for uppercase letters. Also, the condition should ensure both characters are of the same type (both uppercase letters), but here it mixes uppercase start with digit end.
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