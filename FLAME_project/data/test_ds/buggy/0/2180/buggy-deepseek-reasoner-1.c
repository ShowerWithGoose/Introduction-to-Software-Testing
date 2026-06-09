#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++) // @@ This loop condition assumes a newline exists; if not, it may read out-of-bounds, causing undefined behavior. Also, it should use i < strlen(s) to be safe.
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1]) // @@ Accesses s[i-1] and s[i+1] without checking if i is at the beginning or end of the string. For a hyphen at position 0 or last valid index, these memory accesses are out-of-bounds, causing a potential runtime error.
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
                // Missing else: if s[i+1] > s[i-1] but characters are of different types, the hyphen is silently omitted, which is incorrect. The hyphen should be printed in that case.
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