#include<stdio.h>
#include<string.h>
char kz(char s[]) // @@ Function is declared to return char but has no return statement; should be void.
{
    char c[100];
    int j=0; 
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'1')) // @@ Upper bound checks incorrectly use '<' instead of '<=', and the digit condition '<'1'' is logically impossible (should be '<='9''), preventing digit expansion.
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]-1) // @@ Loop condition causes duplicate output for adjacent characters (e.g., "a-b" outputs "abb") and fails to correctly iterate through the full expansion range.
            {
                j++;
                c[j]=c[j-1]+1;
                printf("%c",c[j]);
            }
            j++;
        }
        else
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
    }
}
int main()
{
    char s[100];
    gets(s); // @@ gets() is removed in the C11 standard and causes compilation errors in modern environments; use fgets() or scanf() instead.
    kz(s);
    return 0;
}