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
            if(i == 0 || i == len - 1) // @@ [The program does not check if '-' is at the start or end of the string, leading to out-of-bound access when checking str[i-1] or str[i+1]. However, in this specific test case, it's not the main issue. The real problem is the missing 'continue' after expansion and incorrect handling of non-expansion cases.]
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
                        continue; // @@ [Missing 'continue' causes the '-' to be printed again after expansion, leading to extra '-' in output like '...t-u...'.]
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
                        continue; // @@ [Same as above: missing 'continue' leads to printing '-' again after successful expansion.]
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
                        continue; // @@ [Same issue: missing 'continue' causes redundant '-' output.]
                    }
                }
            }
            else
            printf("-"); // @@ [This 'else' only applies to the digit condition, not the entire expansion logic. So if the first two conditions (lower/upper) fail but digit condition also fails, it prints '-', but if any prior condition partially matches (e.g., types differ), it may fall through incorrectly. Also, even when no expansion occurs, the '-' should be printed, but due to flawed control flow, it might be printed twice or skipped.]
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}