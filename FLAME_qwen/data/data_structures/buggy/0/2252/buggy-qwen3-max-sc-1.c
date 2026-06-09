#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. More critically, the logic fails to handle boundary conditions (e.g., '-' at start/end) and has incorrect range checks like (s[i-1]>='0')&&(s[i+1]<='9') which doesn't ensure both are digits.]
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ [Incorrect condition: should check both s[i-1] and s[i+1] are between '0'-'9'. Current logic allows cases like s[i-1]='A' (>= '0') and s[i+1]='5' (<= '9'), which is invalid.]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ [Same issue: should ensure both are lowercase letters. Current condition allows s[i-1]='A' (>= 'a' is false but logic flawed in general) and s[i+1]='m' (<= 'z'), but actually s[i-1] might not be a lowercase letter.]
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++)
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ [Same issue: must ensure both characters are uppercase letters. Current condition does not verify s[i+1] >= 'A' or s[i-1] <= 'Z'.]
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
    printf("%s",s1); // @@ [s1 is never assigned any value, so printing it is useless and may output garbage. Also, the program prints characters as it goes but doesn't skip the '-' properly when expansion occurs, leading to duplicated or missing characters.]
    return 0;
}