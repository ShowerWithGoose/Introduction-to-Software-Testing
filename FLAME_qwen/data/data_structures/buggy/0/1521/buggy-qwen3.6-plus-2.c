#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm); // @@ Incorrect argument type for scanf; should be 'fm' instead of '&fm'
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ Accessing fm[i-1] when i=0 causes out-of-bounds array access
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++) // @@ Loop condition should be j < fm[i+1]-fm[i-1] to avoid printing the end character twice
                {
                    printf("%c",'fm[i-1]'+j); // @@ Single quotes around 'fm[i-1]' cause a compilation error; should be 'fm[i-1] + j'
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