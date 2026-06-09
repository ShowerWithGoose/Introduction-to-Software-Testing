#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c);

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ Error: When i=0, c[i-1] accesses index -1, causing undefined behavior. Also, the condition should check that both sides are of the same type and the right character is greater than the left, but the type check is done separately; however, the order of checks is wrong—the type check should come before the comparison to avoid comparing characters of different types (e.g., 'B' and 'e').
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z')) // @@ Error: Missing parentheses around the OR conditions; due to operator precedence, the condition is evaluated incorrectly. For example, with 'B-e', c[i-1]='B' (uppercase) and c[i+1]='e' (lowercase), the first part (c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9') is false, but then it ORs with (c[i-1]>='a'&&c[i-1]<='z') which is false, then ORs with (c[i+1]>='a'&&c[i+1]<='z') which is true, so the whole condition becomes true incorrectly. The intended logic requires both sides to be of the same type, so parentheses should group each pair: ((...&&...)||(...&&...)||(...&&...)).
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