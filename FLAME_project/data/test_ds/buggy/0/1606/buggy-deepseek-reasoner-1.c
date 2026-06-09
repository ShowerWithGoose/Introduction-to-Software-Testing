#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s);
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-') // @@ Missing validation: must check that both characters around '-' are of the same type (lowercase, uppercase, or digit) and that s[i+1] > s[i-1]. Also, when expansion is not valid, the '-' should be output unchanged.
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ This loop should only execute if expansion is valid; the condition s[i+1]-s[i-1]-1 can be negative or zero, and it does not consider type mismatch (e.g., 'B' and 'e' produce a positive count but should not be expanded).
            {
                m[j]=m[j-1]+1; // @@ This line assumes m[j-1] exists and is the correct starting character, but it does not handle invalid expansions (where the '-' should be output) and relies on the previous character being set correctly.
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m); // @@ m is not null-terminated after the loop; puts may print garbage beyond the intended string, causing "Buggy output too long".
    return 0;
}