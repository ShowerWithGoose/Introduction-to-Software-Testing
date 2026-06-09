#include<stdio.h>
#include<string.h>
char kz(char s[]) // @@ [Function return type should be void, not char, because it does not return a value.]
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
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'1')) // @@ [Condition for digit expansion incorrectly uses '<'1'' instead of '<='9''; also lower/upper case conditions exclude the end characters 'z' and 'Z' due to '<' condition. Correct conditions should check both characters are within same range and s[i-1] < s[i+1].]
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]); // @@ [Unconditional print of first expansion character; should only print if s[i-1]+1 <= s[i+1]-1, i.e., when there is at least one character to expand.]
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