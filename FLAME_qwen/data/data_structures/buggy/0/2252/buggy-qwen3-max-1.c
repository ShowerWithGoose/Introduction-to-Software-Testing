#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; may cause buffer overflow. Also, the compilation error in the test environment suggests missing compiler, but logically this is a runtime safety issue. However, per problem context, the actual logical errors are below.]
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ [Condition is incorrect: it checks s[i-1] >= '0' but s[i+1] <= '9', which allows cases like s[i-1]='z' and s[i+1]='0' to pass the first part falsely. Should check both ends are digits: (s[i-1]>='0' && s[i-1]<='9' && s[i+1]>='0' && s[i+1]<='9')]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ [Same issue: should ensure both s[i-1] and s[i+1] are in 'a'-'z'. Current condition allows s[i-1]='A' and s[i+1]='z' to pass if 'A'>='a' is false, but logic is broken. Actually, s[i-1]>='a' is okay for lower bound, but missing upper bound on s[i-1] and lower bound on s[i+1].]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ [Same issue: missing bounds check on both characters. Should be (s[i-1]>='A' && s[i-1]<='Z' && s[i+1]>='A' && s[i+1]<='Z')]
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
    printf("%s",s1); // @@ [s1 is never assigned or modified, so printing it is useless and may output garbage. This line should be removed.]
    return 0;
}