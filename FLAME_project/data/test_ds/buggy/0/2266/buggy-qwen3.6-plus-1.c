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
                        for(int j=1;j<max;j++) // @@ The loop condition should be j<=max to include the end character in the expansion.
                        {
                            printf("%c",str[i-1]+j);
                        }
                    }
                }
            }
            if(str[i-1]<='Z'&&str[i-1]>='A') // @@ Should be 'else if' to form a mutually exclusive chain, preventing the final 'else' from incorrectly printing '-' when a lowercase expansion occurs.
            {
                if(str[i+1]<='Z'&&str[i+1]>='A')
                {
                    if(str[i-1]<str[i+1])
                    {
                        int max=str[i+1]-str[i-1];
                        for(int j=1;j<max;j++) // @@ The loop condition should be j<=max to include the end character in the expansion.
                        {
                            printf("%c",str[i-1]+j);
                        }
                    }
                }
            }
            if(str[i-1]<='9'&&str[i-1]>='0') // @@ Should be 'else if' to maintain the mutually exclusive chain for the 'else' clause.
            {
                if(str[i+1]<='9'&&str[i+1]>='0')
                {
                    if(str[i-1]<str[i+1])
                    {
                        int max=str[i+1]-str[i-1];
                        for(int j=1;j<max;j++) // @@ The loop condition should be j<=max to include the end character in the expansion.
                        {
                            printf("%c",str[i-1]+j);
                        }
                    }
                }
            }
            else
            printf("-");
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}