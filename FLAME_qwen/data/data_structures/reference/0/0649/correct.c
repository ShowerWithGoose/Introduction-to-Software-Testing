#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[10000];
int allsimilar(char a,char b)
{
  if(islower(a)&&islower(b))
  {
    return 1;
  }
  else if(isupper(a)&&isupper(b))
  {
    return 1;
  }
  else if(isdigit(a)&&isdigit(b))
  {
    return 1;
  }
  return 0;
}
int main(void)
{
  scanf("%s",s);
  for(int i=0;i<strlen(s);i++)
  {
    if(s[i+1]=='-'&&s[i]<s[i+2]&&allsimilar(s[i],s[i+2]))
    {
      for(char tmp=s[i];tmp<s[i+2];tmp++)
      {
        putchar(tmp);
      }
      i++;
    }
    else
    {
      putchar(s[i]);
    }
  }
  return 0;
}
