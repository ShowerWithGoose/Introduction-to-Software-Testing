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
       if(a<b&&a>=48&&b<=57) // @@ [Error: The condition b<=57 only checks if the end character is a digit, but does not ensure the start character 'a' is also a digit (a<=57). More importantly, this block handles digits. The next else-if handles lowercase. The third else-if is intended for uppercase but has a logical error in the range check.]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ [Error: Similar to above, this checks if start is lowercase (a>=97) and end is <= 'z' (122), but doesn't strictly ensure end is also lowercase (b>=97). However, the critical error is in the next block.]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ [Error: This condition is logically incorrect for uppercase letters. It checks if start is >= 'A' (65) but end is <= '9' (57). Since 'A' (65) is greater than '9' (57), this condition a>=65 && b<=57 can never be true if a < b. It should be checking for uppercase range, e.g., a>=65 && a<=90 && b>=65 && b<=90.]
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