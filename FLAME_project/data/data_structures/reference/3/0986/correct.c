# include <stdio.h>
# include <math.h>
# include <string.h>
# include<stdlib.h>
#include <ctype.h>
int main()
{
    char input[101];
    gets(input);
    int flag=1,i=0,k,l=1,n;
    while(flag)
    {
        if(input[0]!='0')
        {
            if(input[i]!='.')
            {
                i++;
            }
            else if (input[i]=='.')
            {
                n=i-1;
                printf("%c",input[0]);
                printf(".");
                for (k=1;k<i;k++)
                printf("%c",input[k]);
                for(k=i+1;k<strlen(input);k++)
                printf("%c",input[k]);
                flag=0;
            }
            else if(i=strlen(input))
            {
                n=strlen(input)-1;
                printf("%d.",input[0]);
                for(k=1;k<strlen(input);k++)
                printf("%c",input[k]);
                flag=0;
            }
        }
        else if(input[0]=='0'&&input[1]!='.')
        {
            printf("0");
            flag=0;
            n=0;
        }
        else if(input[0]=='0'&&input[1]=='.')
        {
            for(i=2;input[i]=='0';i++)
            {
                l++;
            }
            if(i>2)
            printf("%c.",input[i]);
            else
            printf("%c",input[i]);
            for(i=i+1;i<strlen(input);i++)
            {
                printf("%c",input[i]);
            }
            n=-l;
            flag=0;
        }
    }
    printf("e%d",n);
    return 0;
}
