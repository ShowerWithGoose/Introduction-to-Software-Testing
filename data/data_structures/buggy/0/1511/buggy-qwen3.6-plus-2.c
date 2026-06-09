#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c); // @@ gets is deprecated and removed in C11 standard, causing compilation errors in modern environments; use fgets instead.

    for(int i=0;i<=strlen(c)-1;i++) // @@ strlen(c)-1 causes unsigned integer underflow when the string is empty, leading to out-of-bounds access and potential infinite loops.
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ Accessing c[i-1] when i=0 and c[i+1] when i is the last index causes out-of-bounds memory access; also, checking '<' before verifying character types violates the problem requirement.
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z')) // @@ Missing an else branch to print '-' when the surrounding characters are of different types, causing the '-' to be omitted from the output.

            {
                for(int j=1;j<(c[i+1]-c[i-1]);j++)
                {
                    printf("%c",c[i-1]+j);
                }
            }

        }

        else
        {
            printf("%c",c[i]);
        }
    }

    return 0;
}