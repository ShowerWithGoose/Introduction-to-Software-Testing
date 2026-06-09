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
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++)
            {
                m[j]=m[j-1]+1; // @@ [This line assumes the previous character in m is the starting point for expansion, but it may not be s[i-1] if prior expansions or characters were processed differently. Also, no validation is done to check if s[i-1] and s[i+1] are of the same type (digit, uppercase, lowercase) or if s[i+1] > s[i-1]. Thus, invalid ranges like 'B-e' are incorrectly expanded.]
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m); // @@ [The output string m is not null-terminated, which can cause undefined behavior or garbage output when using puts(). Additionally, even if null-terminated, the logic fails to handle cases where expansion should not occur (e.g., mixed types like 'B-e'), leading to wrong answer.]
}