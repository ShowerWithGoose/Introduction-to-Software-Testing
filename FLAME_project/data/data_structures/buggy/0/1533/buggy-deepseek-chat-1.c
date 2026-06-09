#include<stdio.h>
#include<string.h>
char kz(char s[])
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
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'1')) // @@ The condition for digits is incorrect: '0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'1' only allows expansion when the ending digit is less than '1', which is never true for valid expansions like '0-9'. It should be s[i+1]<='9' instead of s[i+1]<'1'. Also, the condition s[i-1]<s[i+1] is redundant with the while loop condition and does not check that both characters are of the same type (e.g., lowercase, uppercase, or digit) correctly; it should use explicit range checks like (s[i-1]>='a' && s[i+1]<='z') etc.
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]-1)
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
    gets(s);
    kz(s);
    return 0;
}