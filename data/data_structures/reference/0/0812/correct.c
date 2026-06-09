#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include <ctype.h>

char str1[1000],str2[1500];

int main()
{
    int i=0,j=0,d,k=1;
    char a,b;
    scanf("%s",str1);
    for(;str1[i]!='\0';i++)
    {
        if(str1[i]!='-')
            str2[j++]=str1[i];

        else
        {
            a=str1[i+1],b=str1[i-1];
            if(a>b&&((a>='a'&&a<='z'&&b>='a'&&b<='z')||(a>='A'&&a<='Z'&&b>='A'&&a<='Z')||(a>='0'&&a<='9'&&b>='0'&&b<='9')))
               {
                  d=a-b;
                  k=1;
                  for(;k<d;k++,j++)
                  str2[j]=b+k;
               }
            else
                str2[j++]=str1[i];
        }
    }
    str2[j]='\0';
    printf("%s",str2);

    return 0;
}



