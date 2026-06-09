#include<stdio.h>
#include<string.h>
#include<ctype.h>
char numResource[105];
int main(void)
{
  gets(numResource);
  int len=strlen(numResource);
  int locPoint=0;
  int begin=-1,end=-1;
  int usefulDigit=0;
  int p;
  for(int i=0;i<len;i++)
  {
    if(numResource[i]=='.')
    {
      if(end==-1)
      {
        end=i;
      }
      locPoint=i;
    }
    else if(numResource[i]!='0')
    {
      if(begin==-1)
      {
        begin=i;
      }
      usefulDigit++;
    }
  }
  p=end-begin;//指数部分
  if(p>0)
  {
    p--;
  }
  //0.000222->p=-4    222.22222->p=2
  
  if(usefulDigit==1)
  {
    putchar(numResource[begin]);
    putchar('e');
    printf("%d",p);
  }
  else
  {
    int count=0;
    for(int i=begin;i<len;i++)
    {
      if(isdigit(numResource[i]))
      {
        putchar(numResource[i]);
        count++;
      }
      if(count==1)
      {
        putchar('.');
        count++;
      }
      
    }
    putchar('e');
    printf("%d",p);
  }
  return 0;
}
