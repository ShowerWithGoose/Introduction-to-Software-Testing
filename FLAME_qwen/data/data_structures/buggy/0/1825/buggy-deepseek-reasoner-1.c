#include <stdio.h>
int main()
{
    char s[1000]={0};
    int i=0;
    while(scanf("%c",&s[i])!=EOF) // @@ [Reads newline character as part of string, may cause extra output and incorrect processing]
    {
        i++;
    }
    int j;
    for(j=0;j<=i;j++) // @@ [Off-by-one: j should be < i, because s[i] is uninitialized and not part of input; also causes out-of-bounds access]
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ [Range checks incomplete: only checks one bound for each side, allowing non‑digit/non‑letter characters to be considered valid; also no bounds check for j-1 and j+1]
            {
                int n=1;
                while(s[j-1]+n<=s[j+1]) // @@ [Condition should be < to avoid printing the ending character, which will be printed again later, causing duplication]
                {
                    printf("%c",s[j-1]+n);
                    n++;
                }
            }
            else
            printf("%c",s[j]);
        }
    }
    return 0;
}