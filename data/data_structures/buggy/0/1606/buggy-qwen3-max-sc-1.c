#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; also, the program does not handle cases where '-' appears at the start or end of string, leading to out-of-bounds access]
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ [This loop assumes expansion is always valid; it doesn't check if both sides of '-' are same type (digit/upper/lower) or if s[i+1] > s[i-1]; also accesses s[i-1] when i=0 causing undefined behavior]
            {
                m[j]=m[j-1]+1; // @@ [When j=0, m[j-1] accesses m[-1], which is invalid memory access]
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