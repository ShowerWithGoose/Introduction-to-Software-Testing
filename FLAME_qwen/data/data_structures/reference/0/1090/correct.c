#include<stdio.h>
#include<string.h>
#define max 100
int main()
{
  char s[max];
  int i=0;
  scanf("%s",s);
  for(i=0;i<strlen(s);i++)
  {
    if(s[i]!='-')
    printf("%c",s[i]);
    else
    {
      if(s[i-1]-'a'>=0&&s[i+1]-'a'>=0)//都是小写字母
      {
        s[i]=s[i-1]+1;
      while(s[i]<s[i+1])
      { printf("%c",s[i]);
        s[i]=s[i]+1;
      }
      }

      else if(s[i-1]-'a'<0&&s[i-1]-'A'>=0&&s[i+1]-'a'<0&&s[i+1]-'A'>=0)//大写字母
      {s[i]=s[i-1]+1;
      while(s[i]<s[i+1])
      { printf("%c",s[i]);
        s[i]=s[i]+1;
      }
      }

      else if(s[i-1]-'A'<0&&s[i-1]-'0'>=0&&s[i+1]-'A'<0&&s[i+1]-'0'>=0)//数字
       {
        s[i]=s[i-1]+1;
      while(s[i]<s[i+1])
      { printf("%c",s[i]);
        s[i]=s[i]+1;
      }
      }

      else printf("%c",s[i]);
    }
  }
  return 0;
}
