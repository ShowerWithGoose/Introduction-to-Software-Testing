#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
int main()
{
    char str[1002];
    gets(str); // @@ gets() is deprecated and removed in C11, which causes compilation errors in modern environments; use fgets() instead.
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]=='-')
        {
            if(str[i-1]<='z'&&str[i-1]>='a') // @@ Missing boundary check (i>0), accessing str[-1] when i=0 causes undefined behavior.
            {
                if(str[i+1]<='z'&&str[i+1]>='a') // @@ Missing boundary check (i<len-1), accessing out-of-bounds memory when '-' is at the end of the string.
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
            if(str[i-1]<='Z'&&str[i-1]>='A') // @@ Should be 'else if' to form a mutually exclusive chain; otherwise, the final 'else' incorrectly executes for valid lowercase expansions.
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
            if(str[i-1]<='9'&&str[i-1]>='0') // @@ Should be 'else if' to correctly chain conditions; ensures the 'else' below only triggers when no expansion criteria are met.
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
            else // @@ This 'else' only pairs with the immediately preceding 'if' (digit check), causing incorrect output (printing '-') for valid letter expansions.
            printf("-");
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}