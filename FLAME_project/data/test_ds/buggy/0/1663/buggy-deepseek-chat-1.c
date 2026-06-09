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
       if(a<b&&a>=48&&b<=57) // @@ The condition should check both a and b are digits (48-57), but b<=57 is insufficient; also need a<=57 and b>=48. Additionally, the range check for digits should be a>=48 && a<=57 && b>=48 && b<=57.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ The condition should check both a and b are lowercase letters (97-122), but b<=122 is insufficient; also need a<=122 and b>=97. Should be a>=97 && a<=122 && b>=97 && b<=122.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ This condition is incorrect: it mixes uppercase letters (65-90) with digits (48-57). Should be a>=65 && a<=90 && b>=65 && b<=90 for uppercase letters. Also b<=57 is wrong for uppercase.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
       else
       {
           printf("%c",'-'); // @@ This prints the '-' character when expansion conditions are not met, but the problem requires outputting the '-' as part of the original string. However, the logic here is flawed because the '-' is already consumed in the if condition; the else should not print '-' separately. Instead, the original '-' should be printed when no expansion occurs, but the current structure prints it incorrectly. The correct approach is to print the '-' in the else branch only if it was not part of a valid expansion, but the condition checks are wrong, leading to missing or extra '-' characters.
       }
    }
    else
    printf("%c",s[i]);
    
  }
  return 0;
}