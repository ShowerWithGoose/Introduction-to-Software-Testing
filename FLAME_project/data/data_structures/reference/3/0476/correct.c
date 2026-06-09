#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int i = 0,j = 0,temp=0,sum0=1,k=0;
    char s[85];
    gets(s);
    for(i=0; i<strlen(s); i++)
    {
        if(!(isdigit(s[i])))
            temp=i;
    }
    if(temp==1&&s[0]=='0')
    {
        for(j=temp+1; j<strlen(s); j++)
        {
            if(s[j]=='0')
                sum0++;
            else if(s[j]!='0')
            {
                if(strlen(s)-j==1)
                printf("%c",s[j]);
                else
                    printf("%c.",s[j]);
                for(k=j+1; k<strlen(s); k++)
                    printf("%c",s[k]);
                printf("e-%d",sum0);
                break;

            }

        }
    }
    else if(temp==1&&s[0]!='0')
    {
     for(k=0;k<strlen(s);k++)
        printf("%c",s[k]);
     printf("e0");

    }
    else if(temp!=1)
    {
        printf("%c.",s[0]);
        for(k=1; k<strlen(s); k++)
        {       if(isdigit(s[k]))
            printf("%c",s[k]);
        }
        printf("e%d",temp-1);

    }
    return 0;
}

