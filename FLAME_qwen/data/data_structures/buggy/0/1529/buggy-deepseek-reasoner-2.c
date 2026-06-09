#include <stdio.h>
#include <string.h>
char s[]={}; // @@ Error: Declaring an empty array of size 0 is invalid in C. This causes undefined behavior and compilation error in some compilers.
int main()
{
    scanf("%s", s); // @@ Error: Using scanf with an empty array leads to buffer overflow and undefined behavior. Should allocate a fixed size array (e.g., char s[1000]).
    int y=strlen(s);
    for(int i=0; i<y; i++)
    {
        if(s[i]!='-')
        {
            printf("%c", s[i]);
        }
        if(s[i]=='-')
        {
            if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]) // @@ Error: Potential out-of-bounds access when i is 0 or i is the last index. Also, missing else clause to print '-' when condition fails.
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++)
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++)
                {
                    printf("%c", s[i-1]+j);
                }
            }
            else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
            {
                for(int j=1; j<(s[i+1]-s[i-1]); j++)
                {
                    printf("%c", s[i-1]+j);
                }
            } // @@ Error: Missing 'else' block to print the '-' character when none of the expansion conditions are met. The program incorrectly omits the hyphen in such cases.
        }
    }
    return 0;    
}