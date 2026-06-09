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
                    printf("%c",'fm[i-1]'+j); // @@ The character literal 'fm[i-1]' is incorrect; it treats the text as a multi-character constant or string instead of evaluating the variable fm[i-1]. It should be fm[i-1]+j. Also, the loop starts from 1, which skips the start character if the intention is to print the full range including start, but typically expansion a-d means abcd. The reference logic usually prints start to end. Here j=1 adds to start char. If start is 'a', j=1 gives 'b'. It misses 'a'. The loop should likely start from 0 or handle the start char separately. However, the primary syntax error is the quotes around the variable.
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