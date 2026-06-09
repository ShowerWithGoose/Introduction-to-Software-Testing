#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c);

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ Error: When i=0, c[i-1] accesses out-of-bounds memory. Also, the condition does not check that both characters are of the same type (e.g., 'B' and 'e' are different types but still satisfy c[i-1] < c[i+1]).
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z')) // @@ Error: Missing parentheses around the OR conditions, causing incorrect operator precedence. For example, with 'B-e', the first part (c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9') is false, but then it ORs with (c[i-1]>='a'&&c[i-1]<='z') which is false, then ORs with (c[i+1]>='a'&&c[i+1]<='z') which is true, so the condition incorrectly passes for 'B-e' where types differ.
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