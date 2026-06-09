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
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1]))
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1]))
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1]))
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else // @@ This else block is missing; when the characters around '-' are of different types or the second character is not greater, the '-' should be printed as-is. Without this, the '-' is silently dropped, causing output like "Be" instead of "B-e".
            {
                printf("%c",s[i]); // @@ This line is missing; it should print the '-' character when expansion conditions are not met.
            }
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("%s",s1); // @@ This line prints an uninitialized string s1, which is never used or assigned, causing undefined behavior and potentially garbage output.
    return 0;
}