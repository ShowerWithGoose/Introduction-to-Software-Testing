#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check both ends are digits, but only checks s[i-1] >= '0' and s[i+1] <= '9', allowing invalid ranges like '-9' or '0-']
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check both are lowercase letters, but only checks s[i-1] >= 'a' and s[i+1] <= 'z', allowing invalid like '-z' or 'a-']
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check both are uppercase letters, but only checks s[i-1] >= 'A' and s[i+1] <= 'Z', allowing invalid like '-Z' or 'A-']
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
    printf("%s",s1); // @@ [Unnecessary print of uninitialized array s1 which is never modified, leading to undefined behavior or garbage output]
    return 0;
}