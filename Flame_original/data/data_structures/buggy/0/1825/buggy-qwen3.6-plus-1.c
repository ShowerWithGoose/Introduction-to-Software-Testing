#include <stdio.h>
int main()
{
    char s[1000]={0};
    int i=0;
    while(scanf("%c",&s[i])!=EOF)
    {
        i++;
    }
    int j;
    for(j=0;j<=i;j++) // @@ Loop condition j<=i processes the null terminator at s[i], which may output an extra null character. It should be j<i.
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ Incomplete range validation. It only checks one bound for each character, failing to ensure both are strictly within the same type range (e.g., missing s[j-1]<='9' and s[j+1]>='0').
            {
                int n=1;
                while(s[j-1]+n<=s[j+1]) // @@ The <= condition includes the end character s[j+1], which will be printed again in the next iteration, causing duplicate output. It should be < to only print intermediate characters.
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