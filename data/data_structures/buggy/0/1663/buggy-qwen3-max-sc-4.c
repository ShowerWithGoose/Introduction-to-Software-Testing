#include<stdio.h>
#include<string.h>
int main()
{
  char s[1000];
  int i,a,b,j;
  gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
      else if(a<b&&a>=65&&b<=57) // @@ [Logic error: condition checks uppercase start (a>=65) but digit end (b<=57), which is invalid; should be b<=90 for uppercase letters]
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