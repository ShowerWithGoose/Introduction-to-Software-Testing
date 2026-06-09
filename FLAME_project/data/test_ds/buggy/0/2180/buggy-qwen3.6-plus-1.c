#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++) // @@ The loop condition only checks for '\n', but should also check for '\0' to prevent out-of-bounds access when the input lacks a newline. Furthermore, accessing s[i-1] and s[i+1] without bounds checking causes a runtime error if '-' is at the start or end of the string.
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1]) // @@ Accessing s[i-1] when i=0 or s[i+1] when i is at the end of the string causes out-of-bounds memory access, leading to a runtime error. Bounds checking (i > 0 && s[i+1] != '\0') is required.
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
            }
            else
            printf("%c",s[i]);
        }
        else
        printf("%c",s[i]);
    }
    printf("\n");
    return 0;
}