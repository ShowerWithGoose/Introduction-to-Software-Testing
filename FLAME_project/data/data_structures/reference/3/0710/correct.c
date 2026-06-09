#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char s[102]={0};
    int i=0,j=0;
    gets(s);

    if(s[1]=='.'&&s[0]=='0')
    {for(i=2;s[i]=='0';i++)
            i=i;
                 //printf("%c\n",s[i]);
          if(s[i+1]=='\0')
          {
              printf("%ce-%d",s[i],i-1);
          }
          if(s[i+1]!='\0')
          {   printf("%c.",s[i]);
               j=i;
              for(i=i+1;s[i]!='\0';i++)
                printf("%c",s[i]);
              printf("e-%d",j-1);
          }
    }
    if(s[0]!='0'&&s[1]!='.')
    {for(i=0;s[i]!='.';i++)
      i=i;
      j=i;
      printf("%c.",s[0]);
      for(i=1;s[i]!='\0';i++)
      {if(s[i]=='.')
          i=i;
       else
            printf("%c",s[i]);
      }printf("e%d",j-1);

    }
    if(s[0]!='0'&&s[1]=='.')
    {
        printf("%se0",s);
     }



    return 0;
}

