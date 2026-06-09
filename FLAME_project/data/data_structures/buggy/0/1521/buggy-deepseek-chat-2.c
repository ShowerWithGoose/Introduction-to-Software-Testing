#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm); // @@ [Error: scanf should use fm without &, as fm is already an array name representing the address]
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ [Error: When i=0, fm[i-1] accesses out-of-bounds memory; also, the condition should check that both sides are valid characters before comparison]
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++)
                {
                    printf("%c",'fm[i-1]'+j); // @@ [Error: 'fm[i-1]' is a character literal, not the variable fm[i-1]; should be fm[i-1] + j without quotes]
                }
                continue;
            }
            else
            {

            }
        }
        printf("%c",fm[i]);
    }
    return 0;
}