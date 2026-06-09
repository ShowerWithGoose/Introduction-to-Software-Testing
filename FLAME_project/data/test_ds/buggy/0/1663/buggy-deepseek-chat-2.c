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
       if(a<b&&a>=48&&b<=57) // @@ The condition should check both a and b are digits (48-57), but b<=57 is insufficient; it should be b>=48&&b<=57. Also, the range check for a is incomplete (a>=48 is correct but b<=57 allows non-digit characters less than 48 to pass).
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ The condition should check both a and b are lowercase letters (97-122), but b<=122 is insufficient; it should be b>=97&&b<=122. Also, a>=97 is correct but b<=122 allows non-lowercase characters less than 97 to pass.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ This condition is incorrect: it mixes uppercase letters (a>=65) with digits (b<=57). It should check both are uppercase letters (65-90), i.e., a>=65&&a<=90&&b>=65&&b<=90. Also, b<=57 is wrong for uppercase range.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
       else
       {
           printf("%c",'-'); // @@ This prints the '-' character when expansion conditions are not met, but the original '-' character was already consumed by the if(s[i]=='-') check. The correct behavior is to output '-' only when it should be preserved (e.g., when types don't match or a>=b). However, the logic here outputs '-' for all else cases, which may duplicate or misplace hyphens. Additionally, the original '-' is not printed in the else branch of the outer if, causing missing hyphens in non-expansion cases.
       }
    }
    else
    printf("%c",s[i]);
    
  }
  return 0;
}