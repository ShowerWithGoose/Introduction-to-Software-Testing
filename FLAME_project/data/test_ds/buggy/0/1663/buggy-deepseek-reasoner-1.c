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
       if(a<b&&a>=48&&b<=57) // @@ Incomplete condition: should also check a<=57 and b>=48 to ensure both are digits.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ Incomplete condition: should also check a<=122 and b>=97 to ensure both are lowercase.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ Wrong condition: should check a>=65 && a<=90 && b>=65 && b<=90 for uppercase.
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