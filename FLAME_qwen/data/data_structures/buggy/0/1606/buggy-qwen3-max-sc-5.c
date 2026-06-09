#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++)
            {
                m[j]=m[j-1]+1; // @@ [Accesses m[j-1] when j could be 0 (e.g., if string starts with '-'), leading to undefined behavior; also fails to check character types and validity of expansion as per problem requirements]
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