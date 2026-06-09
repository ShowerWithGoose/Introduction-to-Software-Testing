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
       if(a<b&&a>=48&&b<=57) // @@ [The condition checks only that 'a' is >= '0' and 'b' <= '9', but does not ensure both are digits. It should also check that 'b' >= 48 and 'a' <= 57 to confirm both are in digit range.]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ [Similarly, this checks only that 'a' is >= 'a' and 'b' <= 'z', but doesn't ensure 'b' >= 97 and 'a' <= 122. Both characters must be lowercase letters.]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ [This condition is logically wrong: it checks if 'a' is an uppercase letter (>=65) and 'b' is a digit (<=57). This mixes types and will never correctly identify uppercase-to-uppercase expansions. It should be 'a>=65 && a<=90 && b>=65 && b<=90'.]
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