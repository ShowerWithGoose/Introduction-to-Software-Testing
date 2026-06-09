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
            if(str[i-1]<='Z'&&str[i-1]>='A') // @@ Missing continue after lowercase expansion; code proceeds to check uppercase, causing extra dash print.
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
            if(str[i-1]<='9'&&str[i-1]>='0') // @@ Missing continue after uppercase expansion; code proceeds to check digit, causing extra dash print.
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
            else
            printf("-"); // @@ This else attaches only to the digit if, so it prints '-' even when lowercase or uppercase expansion succeeded. Should be restructured as else if chain with final else.
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}