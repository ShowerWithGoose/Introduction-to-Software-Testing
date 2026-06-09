#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm); // @@ Incorrect argument type for %s format specifier; should pass `fm` (decays to char*) instead of `&fm` (char(*)[100]).
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ Accessing fm[i-1] when i=0 causes out-of-bounds read; also fm[i+1] may access out-of-bounds if i is the last index. Should verify i>0 && fm[i+1]!='\0'.
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++) // @@ Off-by-one error: loop condition should be j < fm[i+1]-fm[i-1] to avoid printing the end character itself during expansion.
                {
                    printf("%c",'fm[i-1]'+j); // @@ Syntax error: 'fm[i-1]' is an invalid multi-character constant; should be fm[i-1]+j without single quotes.
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