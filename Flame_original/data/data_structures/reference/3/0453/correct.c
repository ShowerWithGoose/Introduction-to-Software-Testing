#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int pan(char s[])
{
    if(s[0]=='0'&&s[1]=='.')
        return 1;
    else
        return 2;
}
int main()
{
 char s[105];
 gets(s);
 int k=pan(s),lens=strlen(s),place=0;
 for(int i=0;i<lens;i++)
 {
     if(s[i]=='.')
     {
        place=i;
        break;
     }
 }
 if(k==1)
 {
     int flag=0,num=0;
  for(int i=place+1;i<lens;i++)
  {
     if(flag)
     {
         printf("%c",s[i]);
     }
     if(flag==0)
     {
         num++;
     }
        if(s[i]!='0'&&flag==0)
      {
          flag=1;
          printf("%c",s[i]);
          if(i!=lens-1)
          printf(".");

      }

  }

  printf("e-%d",num);
 }
 else if(k==2)
 {
 printf("%c",s[0]);
 printf(".");
 for(int i=1;i<lens;i++)
 {
     if(s[i]!='.')
        printf("%c",s[i]);
 }
 printf("e%d",place-1);
 }
 return 0;
}

