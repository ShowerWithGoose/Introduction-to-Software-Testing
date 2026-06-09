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
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ Missing validation: must check if s[i-1] and s[i+1] are of the same type and s[i-1] < s[i+1] before expanding, otherwise invalid cases like 'B-e' are incorrectly expanded.
            {
                m[j]=m[j-1]+1;
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m); // @@ The character array m is not null-terminated, causing puts to print garbage characters beyond the intended string.
}