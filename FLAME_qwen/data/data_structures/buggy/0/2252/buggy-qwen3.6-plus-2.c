#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s);
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ Incomplete range validation: only checks lower bound for left char and upper bound for right char, missing s[i-1]<='9' and s[i+1]>='0'.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ Incomplete range validation: missing s[i-1]<='z' and s[i+1]>='a' checks.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ Incomplete range validation: missing s[i-1]<='Z' and s[i+1]>='A' checks.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
        }
        else // @@ When s[i]=='-' but expansion conditions fail, the '-' character is not printed, causing it to be omitted from the output.
        {
            printf("%c",s[i]);
        }
    }
    printf("%s",s1); // @@ s1 is declared but never initialized or populated, printing it results in undefined behavior/garbage output.
    return 0;
}