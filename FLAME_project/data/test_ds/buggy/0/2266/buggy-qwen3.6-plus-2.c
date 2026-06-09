#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int main()
{
    char str[1002];
    gets(str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='-')
        {
            if(str[i-1]<='z'&&str[i-1]>='a')
            {
                if(str[i+1]<='z'&&str[i+1]>='a')
                {
                    if(str[i-1]<str[i+1])
                    {
                        int max=str[i+1]-str[i-1];
                        for(int j=1;j<max;j++)
                        {
                            printf("%c",str[i-1]+j);
                        }
                    }
                }
            }
            if(str[i-1]<='Z'&&str[i-1]>='A') // @@ Should be 'else if' to form a mutually exclusive chain; otherwise, the final 'else' executes incorrectly when this condition fails
            {
                if(str[i+1]<='Z'&&str[i+1]>='A')
                {
                    if(str[i-1]<str[i+1])
                    {
                        int max=str[i+1]-str[i-1];
                        for(int j=1;j<max;j++)
                        {
                            printf("%c",str[i-1]+j);
                        }
                    }
                }
            }
            if(str[i-1]<='9'&&str[i-1]>='0') // @@ Should be 'else if' to correctly chain with previous conditions
            {
                if(str[i+1]<='9'&&str[i+1]>='0')
                {
                    if(str[i-1]<str[i+1])
                    {
                        int max=str[i+1]-str[i-1];
                        for(int j=1;j<max;j++)
                        {
                            printf("%c",str[i-1]+j);
                        }
                    }
                }
            }
            else // @@ Now correctly attached to the 'if-else if' chain, ensuring '-' is only printed when no expansion condition is met
            printf("-");
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}