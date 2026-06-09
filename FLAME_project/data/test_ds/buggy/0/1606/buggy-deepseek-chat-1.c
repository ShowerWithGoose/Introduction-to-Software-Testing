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
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ Error: The condition does not check if characters are of the same type (lowercase, uppercase, digit) or if s[i-1] < s[i+1]; it also doesn't handle cases where expansion should not occur (e.g., B-e), leading to incorrect expansion.
            {
                m[j]=m[j-1]+1; // @@ Error: When j=0, m[j-1] accesses m[-1], which is out-of-bounds and undefined behavior. Also, this logic assumes m[j-1] is the previous character, but it should start from s[i-1]+1.
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