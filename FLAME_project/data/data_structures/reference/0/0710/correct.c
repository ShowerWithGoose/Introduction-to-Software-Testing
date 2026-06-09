#include <stdio.h>
int main()
{
    char s[1000];
    char a,b;
    int n;
    scanf("%s",&s);
     int i,j;
     for(i=0;s[i]!='\0';i++)
     {
         if(s[i]!='-')
            printf("%c",s[i]);
         else
         {a=s[i-1];
          b=s[i+1];
          if((a>='a'&&b<='z')||(a>='0'&&b<='9')||(a>='A'&&b<='Z'))
            {n=b-a;
         for(j=1;j<n;j++)
            printf("%c",a+j);

            }
            else
            printf("-");
         }
     }
     return 0;
}

