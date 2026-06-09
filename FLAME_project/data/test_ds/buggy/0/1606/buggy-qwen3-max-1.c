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
                m[j]=m[j-1]+1; // @@ [This assumes the previous character in m is the left bound of the range, but it may not be if '-' appears at the start or after non-expanded content. Also, no validation is done to check if both sides of '-' are same type (digit/upper/lower) and valid for expansion.]
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m); // @@ [The output string m is not null-terminated, which leads to undefined behavior when using puts(). Additionally, invalid expansions like 'B-e' are incorrectly expanded because the code lacks checks for same character type and ordering.]
}