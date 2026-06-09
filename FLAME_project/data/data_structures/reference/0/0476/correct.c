#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    char s[100];
    int i=0,j=0,k=-1,p=0;
    gets(s);
    for(i=0; i<strlen(s); i++)
    {
        if(s[i]=='-')
        {
            for(j=k+1; j<i; j++)
                printf("%c",s[j]);

            if(islower(s[i-1])&&islower(s[i+1])&&(s[i+1])>(s[i-1]))
            {
                for(j=1; j<s[i+1]-s[i-1]; j++)
                    printf("%c",(s[i-1]+j));
                k=i;
            }
            else  if(isupper(s[i-1])&&isupper(s[i+1])&&(s[i+1])>(s[i-1]))
            {
                for(j=1; j<s[i+1]-s[i-1]; j++)
                    printf("%c",(s[i-1]+j));
                k=i;
            }
            else  if(isdigit(s[i-1])&&isdigit(s[i+1])&&(s[i+1])>(s[i-1]))
            {
                for(j=1; j<s[i+1]-s[i-1]; j++)
                    printf("%c",(s[i-1]+j));
                k=i;
            }
            else
                k=-1,p=i;
        }
    }
    if(k!=-1)
    for(j=1; j<strlen(s)-k; j++)
        printf("%c",s[j+k]);
        else
    {
        for(;p<strlen(s);p++)
            printf("%c",s[p]);
    }

    return 0;
}

