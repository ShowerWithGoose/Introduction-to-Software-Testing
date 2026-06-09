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
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ The condition (s[i+1]<='9') is incorrect; it should check that both characters are digits, i.e., (s[i-1]>='0' && s[i-1]<='9') && (s[i+1]>='0' && s[i+1]<='9'). The current condition allows non-digit characters like 'B' to pass because 'B' <= '9' is true in ASCII.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ The condition (s[i-1]>='a') is incorrect; it should check that s[i-1] is a lowercase letter, i.e., (s[i-1]>='a' && s[i-1]<='z'). The current condition allows characters greater than 'z' to pass.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ The condition (s[i-1]>='A') is incorrect; it should check that s[i-1] is an uppercase letter, i.e., (s[i-1]>='A' && s[i-1]<='Z'). The current condition allows characters greater than 'Z' to pass.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("%s",s1);
    return 0;
}