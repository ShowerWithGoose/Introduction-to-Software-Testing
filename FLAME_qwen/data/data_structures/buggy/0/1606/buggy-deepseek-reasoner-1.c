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
        if(s[i]=='-') // @@ Missing validation of type and order: must check that both characters around '-' are of the same character class (lowercase, uppercase, digit) and that s[i-1] < s[i+1]; otherwise '-' should be copied unchanged.
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ Loop condition uses unchecked difference; fails for invalid cases (e.g., different types, left >= right) and does not include copying the final character s[i+1] after the loop.
            {
                m[j]=m[j-1]+1; // @@ Correct in principle but expansion incomplete: the last character s[i+1] is never copied to m, and after the loop the position j is not correctly set for subsequent characters.
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m);
}