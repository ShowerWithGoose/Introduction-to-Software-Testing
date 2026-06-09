#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++) // @@ [Loop condition assumes newline is present; if input does not contain newline (e.g., from gets), loop may run past the string. Also, when i=0, s[i-1] is out of bounds, causing undefined behavior.]
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1]) // @@ [This check uses s[i-1] which is invalid when i=0. Additionally, when left < right but types do not match, the dash is not printed, violating the requirement to output unchanged characters.]
            {
                if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<= 'z')
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z')
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
            } // @@ [Missing else clause: if s[i+1] > s[i-1] but types don't match, the dash should be printed; currently it is skipped.]
            else
            printf("%c",s[i]);
        }
        else
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}