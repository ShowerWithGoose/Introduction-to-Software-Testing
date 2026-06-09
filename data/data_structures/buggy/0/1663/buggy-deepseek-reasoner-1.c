#include<stdio.h>
#include<string.h>
int main()
{
  char s[1000];
  int i,a,b,j;
  gets(s); // @@ [gets is unsafe and may cause buffer overflow; also deprecated, but not a logical error]
  for(i=0;s[i]!='\0';i++)
  {
      if(s[i]=='-')
      {
       a=s[i-1]; // @@ [When i=0, s[-1] is out-of-bounds; undefined behavior]
       b=s[i+1];
       if(a<b&&a>=48&&b<=57) // @@ [Missing upper bound check for a (a<=57) and lower bound check for b (b>=48); could allow non-digit a to be considered as digit]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ [Missing upper bound for a (a<=122) and lower bound for b (b>=97)]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ [Condition incorrectly uses b<=57 (digit) instead of b<=90 for uppercase; also missing a<=90 and b>=65; effectively never matches uppercase]
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