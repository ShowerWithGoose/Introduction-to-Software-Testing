#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm);
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ [When i=0, fm[i-1] accesses index -1, leading to out-of-bounds. Also, the condition should not be evaluated for i=0.]
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++) // @@ [Loop bound includes the second character, causing it to be printed twice. Should be j <= fm[i+1]-fm[i-1]-1.]
                {
                    printf("%c",'fm[i-1]'+j); // @@ [Single quotes around fm[i-1] create a multi-character constant, not the variable's value. Should be fm[i-1] + j.]
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