#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm); // @@ [Error: Should be scanf("%s", fm); &fm is a type mismatch and may cause undefined behavior.]
    int i,j;
    for(i=0;i<strlen(fm);i++)
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ [Error: No bounds check; when i==0, fm[i-1] is out of bounds. Also need to ensure i+1 is within string length.]
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++)
                {
                    printf("%c",'fm[i-1]'+j); // @@ [Error: 'fm[i-1]' is a multi-character literal, not the character. Should be fm[i-1] + j. Also, algorithm prints right character twice (once here and later at its own index), causing duplicate.]
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