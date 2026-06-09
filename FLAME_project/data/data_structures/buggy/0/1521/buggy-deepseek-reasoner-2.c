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
                for(j=1;j<=fm[i+1]-fm[i-1];j++)
                {
                    printf("%c",'fm[i-1]'+j); // @@ [Error: 'fm[i-1]' is a multicharacter literal; should be fm[i-1] + j without single quotes]
                }
                continue; // @@ [Error: after expansion, the next character (fm[i+1]) should be skipped to avoid duplication. The continue only skips the current '-', but the loop will still print the character after the '-' in the next iteration.]
            }
            else
            {

            }
        }
        printf("%c",fm[i]);
    }
    return 0;
}