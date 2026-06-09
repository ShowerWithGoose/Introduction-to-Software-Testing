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
        if(s[i]=='-') // @@ Missing validation that s[i-1] and s[i+1] are of the same type (both digits, uppercase, or lowercase) and s[i+1] > s[i-1]. Also fails to copy '-' to m when expansion conditions are not met.
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ Unconditionally performs expansion without type checking, causing mismatched types like 'B-e' to be incorrectly expanded.
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
    puts(m); // @@ Array m is not null-terminated with '\0', which may cause puts to print garbage characters after the valid output.
}