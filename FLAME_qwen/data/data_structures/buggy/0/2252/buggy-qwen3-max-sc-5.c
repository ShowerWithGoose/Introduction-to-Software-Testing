#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, the compilation error might be due to compiler treating this as an error if strict standards are enforced.]
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check s[i-1] <= '9' AND s[i+1] >= '0' to ensure both are digits. Current logic allows cases like s[i-1]='z' (>= '0') and s[i+1]='0' (<= '9'), which is wrong.]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check s[i-1] <= 'z' AND s[i+1] >= 'a'. Current logic fails to validate that both characters are lowercase letters.]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check s[i-1] <= 'Z' AND s[i+1] >= 'A'. Current logic fails to validate that both characters are uppercase letters.]
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
    printf("%s",s1); // @@ [Unnecessary output of uninitialized array s1, which may print garbage or nothing, but not part of expansion logic. However, not directly causing compilation error.]
    return 0;
}