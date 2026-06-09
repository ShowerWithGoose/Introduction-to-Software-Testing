#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s); // @@ gets is removed in C11 standard and may cause compilation errors; also unsafe for buffer overflow.
    int i,j,k; // @@ Declaring variables after a statement violates C89/C90 standard, leading to compilation error.
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++) // @@ Fails to check bounds, character types, or order as required; accessing s[i-1]/s[i+1] may cause out-of-bounds read.
            {
                m[j]=m[j-1]+1; // @@ When j=0, m[j-1] accesses invalid memory; relies on uninitialized m instead of s[i-1], causing undefined behavior.
                j++;
            }
        }
        else
        {
            m[j]=s[i];
            j++;
        }
    }
    puts(m); // @@ Missing explicit null terminator '\0' at the end of m, which may cause puts to print garbage or crash.
}