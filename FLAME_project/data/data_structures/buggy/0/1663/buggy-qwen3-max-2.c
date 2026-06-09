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
       if(a<b&&a>=48&&b<=57) // @@ [The condition checks only lower bound for 'a' and upper bound for 'b', but does not ensure both are digits (should be a>=48 && a<=57 && b>=48 && b<=57)]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ [Similarly, this checks only lower bound for 'a' and upper bound for 'b', but does not ensure both are lowercase letters (should be a>=97 && a<=122 && b>=97 && b<=122)]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ [This condition is logically wrong: uppercase letters (65-90) cannot be <=57 (which is '9'), so this block never executes correctly; also missing proper range check for uppercase]
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