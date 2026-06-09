#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c);

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ [Error: When i=0, c[i-1] accesses index -1, which is out of bounds. Also, the condition should check that both sides are valid characters before comparing, and the expansion should only occur when the character after '-' is greater than the one before it, but this condition is placed before the type check, causing potential out-of-bounds access and incorrect logic for cases where types don't match.]
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z'))

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