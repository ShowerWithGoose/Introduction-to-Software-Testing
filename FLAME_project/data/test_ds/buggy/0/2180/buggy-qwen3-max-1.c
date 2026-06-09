#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10086];
int main()
{
    fgets(s,10086,stdin);
    for(int i=0;s[i]!='\n';i++)
    {
        if(s[i]=='-')
        {
            if(s[i+1]>s[i-1]) // @@ [This condition accesses s[i-1] and s[i+1] without checking if i is at the start or end of the string, which can cause out-of-bounds access when i=0 or i points to the last character before '\n'.]
            {
                if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<= 'z') // @@ [Relies on unchecked s[i-1] and s[i+1]; also, the condition order may lead to reading invalid memory if i=0.]
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z') // @@ [Same issue: unsafe access to s[i-1] when i=0.]
                {
                    for(char c=s[i-1]+1;c<s[i+1];c++)
                    printf("%c",c);
                }
                else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9') // @@ [Same issue: unsafe access to s[i-1] when i=0.]
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