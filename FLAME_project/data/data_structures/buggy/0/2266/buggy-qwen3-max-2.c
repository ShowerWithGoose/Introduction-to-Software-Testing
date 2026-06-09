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
            if(i == 0 || i == len - 1) // @@ [Missing boundary check: when '-' is at the start or end, accessing str[i-1] or str[i+1] leads to undefined behavior or incorrect logic]
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
                        continue; // @@ [Missing 'continue' causes '-' to be printed again after expansion]
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
                        continue; // @@ [Missing 'continue' causes '-' to be printed again after expansion]
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
                        continue; // @@ [Missing 'continue' causes '-' to be printed again after expansion]
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only pairs with the last 'if' (digit check), not all three type checks. So if the first two checks fail but digit check also fails, it prints '-', but if any earlier check passes without expansion (e.g., a-Z), it falls through and doesn't print '-'. Also, even when expansion happens, without 'continue', this may still execute.]
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}