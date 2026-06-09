#include<stdio.h>
#include<string.h>
int main()
{
  char s[1000];
  int i,a,b,j;
  gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this leads to compilation errors or warnings that prevent execution.]
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
      else if(a<b&&a>=65&&b<=57) // @@ [Logic error: This condition checks for uppercase letters (a>=65) but then requires b<=57 (which is '9'), mixing digit and uppercase ranges. It should be 'b<=90' for uppercase letters (A-Z).]
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