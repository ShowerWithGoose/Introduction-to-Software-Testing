#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++) // @@ Loop condition checks for '\n', which may cause out-of-bounds access or infinite loop if input lacks a newline; should check for '\0' or use strlen. Additionally, declaring 'int i' inside the for-loop initializer may cause compilation errors in strict C89 environments.
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1]) // @@ Accessing s[i-1] when i=0 causes out-of-bounds memory access; also s[i+1] may access beyond the string terminator if '-' is at the end.
            {
                if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<= 'z') // @@ Repeated out-of-bounds access to s[i-1] and s[i+1] without boundary checks.
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z') // @@ Same out-of-bounds access issue for s[i-1] and s[i+1].
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9') // @@ Same out-of-bounds access issue for s[i-1] and s[i+1].
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