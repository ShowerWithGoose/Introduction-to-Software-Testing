#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char s[1000],s1[1000];
int main()
{
    char c,a,b;
    int i=0,count,j=0;
    gets(s); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers; use fgets() instead.
    for(i=0,j=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]>='0')&&(s[i+1]<='9')&&(s[i-1]<s[i+1])) // @@ Incomplete range validation; fails to check s[i-1]<='9' and s[i+1]>='0', allowing non-digit characters to pass.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++) // @@ Declaring a loop variable inside the for() statement is invalid in C89/C90, causing a compilation error.
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='a')&&(s[i+1]<='z')&&(s[i-1]<s[i+1])) // @@ Incomplete range validation; fails to check s[i-1]<='z' and s[i+1]>='a'.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++) // @@ Declaring a loop variable inside the for() statement is invalid in C89/C90, causing a compilation error.
                {
                    printf("%c",s[i-1]+n);
                }
            }
            else if((s[i-1]>='A')&&(s[i+1]<='Z')&&(s[i-1]<s[i+1])) // @@ Incomplete range validation; fails to check s[i-1]<='Z' and s[i+1]>='A'.
            {
                count=s[i+1]-s[i-1];
                for(int n=1;n<count;n++) // @@ Declaring a loop variable inside the for() statement is invalid in C89/C90, causing a compilation error.
                {
                    printf("%c",s[i-1]+n);
                }
            }
        }
        else
        {
            printf("%c",s[i]);
        }
    }
    printf("%s",s1); // @@ s1 is uninitialized and never populated, printing it causes undefined behavior and garbage output.
    return 0;
}