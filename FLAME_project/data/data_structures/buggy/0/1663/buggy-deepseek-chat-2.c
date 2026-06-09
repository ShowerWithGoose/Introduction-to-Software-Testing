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
       if(a<b&&a>=48&&b<=57) // @@ The condition should check both a and b are digits (48-57), but b<=57 is insufficient; it should be b>=48&&b<=57. Also, the range check for a is incomplete (a>=48 is correct but b<=57 misses the lower bound for b).
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ The condition should check both a and b are lowercase letters (97-122), but b<=122 is correct; however, a>=97 is correct but missing b>=97. Actually, the condition is correct for lowercase, but the logic is flawed because it doesn't ensure both are lowercase; it only checks a>=97 and b<=122, which could allow a=97 and b=122, but b could be less than 97. The correct condition should be a>=97 && a<=122 && b>=97 && b<=122.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ This condition is incorrect: it mixes uppercase letters (65-90) with digits (48-57). It should check both a and b are uppercase letters (65-90). The correct condition should be a>=65 && a<=90 && b>=65 && b<=90.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
       else
       {
           printf("%c",'-'); // @@ This prints the '-' character when expansion conditions are not met, but the problem requires outputting the original '-' unchanged. However, the logic here is flawed because it prints '-' even when the '-' should be part of the original string (e.g., in "a-uB-F", the second '-' should be printed as is, but this code prints it only in the else branch, which may cause missing or extra characters). The correct approach is to print the '-' when no expansion occurs, but the current structure may skip printing the character before the '-' in some cases.
       }
    }
    else
    printf("%c",s[i]);
    
  }
  return 0;
}