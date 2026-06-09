#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm);
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ When i=0, fm[i-1] accesses out-of-bounds memory; also lacks bounds check for i+1
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++) // @@ Loop starts at j=1, missing the first character of the expansion range; should start at j=0
                {
                    printf("%c",'fm[i-1]'+j); // @@ 'fm[i-1]' is a multi-character literal, not the variable value; should be fm[i-1] + j
                }
                continue; // @@ Skips printing '-', but fails to skip printing fm[i+1] in the next iteration, causing duplication of the end character
            }
            else
            {

            }
        }
        printf("%c",fm[i]);
    }
    return 0;
}