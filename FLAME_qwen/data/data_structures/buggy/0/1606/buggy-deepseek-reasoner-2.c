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
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ [No bounds check for s[i-1] and s[i+1]; no validation that characters are same type and s[i+1] > s[i-1]; non-expandable dash is ignored]
            {
                m[j]=m[j-1]+1; // @@ [Relies on m[j-1] which may be invalid when j=0 or expansion starts; should use s[i-1]+k+1 instead]
                j++;
            }
        } // @@ [Missing else clause for non-expandable dash; such dashes should be copied verbatim]
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m); // @@ [m is not null-terminated, causing potential undefined behavior]
}