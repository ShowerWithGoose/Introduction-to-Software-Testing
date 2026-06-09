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
            if(i == 0 || i == len - 1) // @@ [Missing boundary check: when '-' is at the start or end, str[i-1] or str[i+1] is invalid, leading to undefined behavior or incorrect output]
            {
                printf("-");
                continue;
            }
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
                        continue; // @@ [Missing 'continue' causes '-' to be printed again via the 'else' clause below]
                    }
                }
            }
            if(str[i-1]<='Z'&&str[i-1]>='A')
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
                        continue; // @@ [Missing 'continue' causes '-' to be printed again via the 'else' clause below]
                    }
                }
            }
            if(str[i-1]<='9'&&str[i-1]>='0')
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
                        continue; // @@ [Missing 'continue' causes '-' to be printed again via the 'else' clause below]
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only pairs with the last 'if' (digit check), not the entire expansion logic. So if a valid lowercase or uppercase expansion fails digit check, it incorrectly prints '-'. Also, even when expansion occurs, without 'continue', this prints '-' again.]
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}