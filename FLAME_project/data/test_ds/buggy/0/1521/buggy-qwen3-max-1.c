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
                    printf("%c",'fm[i-1]'+j); // @@ [The expression 'fm[i-1]' is enclosed in single quotes, making it a multi-character literal instead of the variable value. It should be fm[i-1] + j without quotes.]
                }
                continue;
            }
            else
            {

            }
        }
        printf("%c",fm[i]); // @@ [When a valid expansion occurs, the code prints the expanded characters but still prints the '-' and surrounding characters later due to the loop structure. Also, after printing expansion, it should skip the next character (fm[i+1]) to avoid duplication, but doesn't adjust the loop index accordingly. Additionally, the original character before '-' (fm[i-1]) was already printed in a previous iteration, so the expansion starts correctly, but the '-' and the next character are not properly skipped.]
    }
    return 0;
}