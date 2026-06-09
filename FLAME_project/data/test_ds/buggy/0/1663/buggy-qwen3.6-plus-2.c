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
       if(a<b&&a>=48&&b<=57) // @@ Incorrect range validation for digits. It only checks the lower bound of 'a' and upper bound of 'b', failing to ensure both characters are strictly within the digit range [48, 57].
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ Incorrect range validation for lowercase letters. It only checks the lower bound of 'a' and upper bound of 'b', failing to ensure both characters are strictly within the lowercase range [97, 122].
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ Incorrect range validation for uppercase letters. The upper bound 57 corresponds to the digit '9', not uppercase letters. It should verify both characters are within the uppercase range [65, 90].
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