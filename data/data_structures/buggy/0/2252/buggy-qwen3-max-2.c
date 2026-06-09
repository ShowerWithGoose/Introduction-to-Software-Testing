#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, in some environments, this can lead to compilation errors or warnings that halt compilation if strict flags are used.]
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check both ends are digits, i.e., (s[i-1]>='0' && s[i-1]<='9') && (s[i+1]>='0' && s[i+1]<='9'). Current logic allows cases like '-9' where s[i-1] could be non-digit but still >= '0'.]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should ensure both characters are lowercase letters. Current check only ensures s[i-1] >= 'a' and s[i+1] <= 'z', which allows invalid pairs like 'z-a' or '0-z'.]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ [Same issue as above: missing upper bound on s[i-1] and lower bound on s[i+1]; e.g., s[i-1]='z' (>= 'A') and s[i+1]='0' (<= 'Z') would incorrectly pass.]
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
    printf("%s",s1); // @@ [s1 is never assigned any value, so printing it is undefined behavior and outputs garbage. This line is unnecessary and likely a leftover from incomplete implementation.]
    return 0;
}