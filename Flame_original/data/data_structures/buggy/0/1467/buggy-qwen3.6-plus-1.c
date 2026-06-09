#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str); // @@ [gets is removed in the C11 standard and causes a compilation error in modern compilers; use fgets(str, sizeof(str), stdin) instead]
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ [Logical error: incomplete range validation; fails to check if str[i-1] <= 'z' and str[i+1] >= 'a', causing incorrect type matching]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++) // @@ [Declaring variables inside the for-loop initialization is a C99 feature; may cause a compilation error in C89/ANSI C mode]
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ [Logical error: incomplete range validation; fails to check if str[i-1] <= '9' and str[i+1] >= '0']
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++) // @@ [Same C99 declaration issue as above; may cause compilation error in strict C89 environments]
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ [Logical error: incomplete range validation; fails to check if str[i-1] <= 'Z' and str[i+1] >= 'A']
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++) // @@ [Same C99 declaration issue as above; may cause compilation error in strict C89 environments]
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
        }

    }
    return 0;
}