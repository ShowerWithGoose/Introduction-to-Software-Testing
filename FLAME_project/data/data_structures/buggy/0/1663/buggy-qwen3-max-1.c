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
       if(a<b&&a>=48&&b<=57) // @@ [The condition checks only that 'a' is >= '0' and 'b' <= '9', but does not ensure both are digits. Should also check b>=48 and a<=57.]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ [The condition checks only that 'a' is >= 'a' and 'b' <= 'z', but does not ensure both are lowercase letters. Should also check b>=97 and a<=122.]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ [This condition is logically incorrect: it checks uppercase start (a>=65) but requires b<=57 (digit '9'), which can never be true for uppercase letters (which start at 65). It should check b<=90 and also b>=65.]
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