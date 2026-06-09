#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; also, the program does not check if '-' is between valid same-type characters before expanding]
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ [This loop runs unconditionally whenever a '-' is encountered, without verifying that both surrounding characters are of the same type (e.g., both digits, both lowercase, etc.) and that s[i+1] > s[i-1]. This leads to incorrect expansions or undefined behavior (e.g., negative loop bounds or accessing m[-1])]
            {
                m[j]=m[j-1]+1; // @@ [If j is 0 (e.g., string starts with '-'), m[j-1] accesses m[-1], which is out-of-bounds and causes undefined behavior]
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