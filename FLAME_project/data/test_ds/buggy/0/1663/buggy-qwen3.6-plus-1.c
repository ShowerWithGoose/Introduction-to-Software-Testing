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
       if(a<b&&a>=48&&b<=57) // @@ [Logical error: Condition only checks the lower bound of 'a' and upper bound of 'b'. It should explicitly verify that both 'a' and 'b' fall within the digit range [48, 57] to ensure they are of the same type.]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
     else if(a<b&&a>=97&&b<=122) // @@ [Logical error: Condition only checks the lower bound of 'a' and upper bound of 'b'. It should explicitly verify that both 'a' and 'b' fall within the lowercase letter range [97, 122].]
       {
           for(j=a+1;j<b;j++)
           printf("%c",j);
       }
      else if(a<b&&a>=65&&b<=57) // @@ [Logical error & Typo: The upper bound '57' is incorrect for uppercase letters; it should be '90'. Must verify both 'a' and 'b' are within the uppercase range [65, 90].]
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