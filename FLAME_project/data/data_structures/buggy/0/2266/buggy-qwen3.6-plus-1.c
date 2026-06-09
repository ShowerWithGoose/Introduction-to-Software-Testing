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
                        continue; // @@ The original code lacks a continue statement here, causing the subsequent 'if' blocks to be evaluated and potentially printing '-' or other characters incorrectly when a valid expansion occurs. It also fails to skip the printing of the '-' character itself in the else branch below if expansion happens.
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
                        continue; // @@ Same as above: missing continue after successful expansion prevents correct flow control, leading to potential double processing or incorrect output of '-'.
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
                        continue; // @@ Same as above: missing continue after successful expansion.
                    }
                }
            }
            else
            printf("-"); // @@ This else is only associated with the last if (digit check). If the first two ifs (lower/upper) fail but the digit check isn't entered due to structure, this logic is flawed. More importantly, if none of the expansion conditions are met, we should print the '-'. However, because the previous blocks don't have else-if or proper continues, this logic is tangled. The main issue revealed by the test case `a-uB-F` is that when `a-u` expands, it prints `bc...t`, but then falls through. The `B-F` part: `B` is printed by the `else` branch of `if(str[i]=='-')`? No. Let's trace `a-u`. `i` is at `-`. `a` is lower, `u` is lower, `a<u`. Expands. Prints `b..t`. Missing continue. Falls through to next `if`. `a` is not upper. Falls through to next `if`. `a` is not digit. Enters `else` of the last `if`. Prints `-`. So output is `abc...t-`. Then loop continues. Next char `u`. Printed. Then `B`. Printed. Then `-`. `B` is upper, `F` is upper, `B<F`. Expands `CDE`. Missing continue. Falls through. `B` not digit. Enters `else` of last `if`. Prints `-`. Output `...uBCDE-F`. Expected `...tuBCDEF`. The bugs are: 1. Missing `continue` after each successful expansion block. 2. The `else printf("-")` is attached only to the digit check. It should print `-` if NO expansion happened.
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}