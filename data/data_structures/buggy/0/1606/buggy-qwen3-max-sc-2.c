#include<stdio.h>
#include<string.h>
char s[10086];
char m[10086];
int main()
{
    gets(s); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    int i,j,k;
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            for(k=0;k<s[i+1]-s[i-1]-1;k++)
            {
                m[j]=m[j-1]+1; // @@ [When expanding, m[j-1] may be uninitialized or refer to a character that is not the previous character in the original sequence (e.g., after a '-' that shouldn't expand). Also, expansion logic doesn't check character types or validity of range.]
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