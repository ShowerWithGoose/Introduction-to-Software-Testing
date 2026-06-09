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
       if(a<b&&a>=48&&b<=57) // @@ The condition b<=57 only checks if the end character is a digit, but does not ensure the start character 'a' is also a digit (a>=48 includes letters/symbols in ASCII if not upper bounded). More importantly, it fails to check that both are of the SAME type. For 'B-F', a='B'(66), b='F'(70). This condition fails correctly. However, the next condition is problematic.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ Similar logic error. It checks if start is lowercase and end is <= 'z'. It doesn't strictly enforce that 'b' is also lowercase (though usually implied by context, strict type matching requires b>=97). But the critical error is in the next block.
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ Logical Error: This condition intends to handle uppercase letters, but uses b<=57 ('9'). '57' is the ASCII code for '9'. Uppercase letters are 65-90. So this condition will almost never be true for valid uppercase ranges (e.g., B=66, F=70. 70 <= 57 is false). It should be b<=90 and additionally check b>=65 to ensure same type.
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