#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm);
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ [Error: Potential out-of-bounds access when i=0 (fm[-1]) or i=strlen(fm)-1 (fm[i+1] = '\0' or beyond). This causes undefined behavior and wrong condition evaluation.]
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9')) // @@ [Error: Same out-of-bounds issue as above. Also the condition should check that both sides are of the same type, but the bounds issue makes it unreliable.]
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++)
                {
                    printf("%c",'fm[i-1]'+j); // @@ [Error: 'fm[i-1]' is a multicharacter constant, not the character at fm[i-1]. Should be fm[i-1]+j. This produces incorrect characters.]
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