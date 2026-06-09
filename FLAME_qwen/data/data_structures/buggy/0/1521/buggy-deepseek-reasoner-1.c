#include<stdio.h>
#include<string.h>
int main()
{
    char fm[100];


    scanf("%s",&fm);
    int i,j;
    for(i=0;i<strlen(fm);i++) // @@ [inefficient but not error; however, i+1 access later may be out-of-bound]
    {

        if(fm[i]=='-'&&fm[i-1]<fm[i+1]) // @@ [out-of-bounds when i==0 (fm[-1]) or i==len-1 (fm[i+1] may be '\0')]
        {
            if(('a'<=fm[i-1]&&fm[i-1]<='z'&&'a'<=fm[i+1]&&fm[i+1]<='z')||('A'<=fm[i-1]&&fm[i-1]<='Z'&&'A'<=fm[i+1]&&fm[i+1]<='Z')||('0'<=fm[i-1]&&fm[i-1]<='9'&&'0'<=fm[i+1]&&fm[i+1]<='9'))
            {
                for(j=1;j<=fm[i+1]-fm[i-1];j++) // @@ [loop condition should be j < fm[i+1]-fm[i-1] to avoid printing last character twice]
                {
                    printf("%c",'fm[i-1]'+j); // @@ [syntax error: 'fm[i-1]' is a multi-character literal, should be fm[i-1]]
                }
                continue;
            }
            else
            {

            }
        }
        printf("%c",fm[i]); // @@ [logical error: prints character that may have already been printed during expansion]
    }
    return 0;
}