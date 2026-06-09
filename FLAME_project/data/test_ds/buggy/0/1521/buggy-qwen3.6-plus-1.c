#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm);
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1])
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++) // @@ The loop should start from j=0 to include the starting character fm[i-1] in the expansion.
                {
                    printf("%c",'fm[i-1]'+j); // @@ 'fm[i-1]' is a multi-character literal, not the variable. It should be fm[i-1] + j to correctly compute the character to print.
                }
                continue; // @@ After expansion, the for loop will increment i, causing fm[i+1] (the end character) to be printed again. i should be incremented here to skip it.
            }
            else
            {

            }
        }
        printf("%c",fm[i]);
    }
    return 0;
}