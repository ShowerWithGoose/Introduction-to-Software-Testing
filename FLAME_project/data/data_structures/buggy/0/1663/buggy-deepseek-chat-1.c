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
       if(a<b&&a>=48&&b<=57) // @@ The condition should check both a and b are digits (48-57), but b<=57 is insufficient; also need a<=57 and b>=48. Additionally, the logic for uppercase and lowercase is incorrect.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ This condition only checks a>=97 (lowercase) and b<=122, but does not ensure b>=97 (lowercase). It should be a>=97 && a<=122 && b>=97 && b<=122.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ This condition is logically wrong: it checks a>=65 (uppercase) but b<=57 (digits), which mixes types. It should check both are uppercase: a>=65 && a<=90 && b>=65 && b<=90.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
       else
       {
           printf("%c",'-'); // @@ This prints the '-' character when expansion conditions are not met, but the original '-' character was already skipped in the loop. This causes extra '-' to appear. The correct approach is to print '-' only when it should be kept, but here the logic is flawed.
       }
    }
    else
    printf("%c",s[i]);
    
  }
  return 0;
}