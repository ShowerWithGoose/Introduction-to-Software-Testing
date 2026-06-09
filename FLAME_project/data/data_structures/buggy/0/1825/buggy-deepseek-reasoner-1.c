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
    for(j=0;j<=i;j++) // @@ Loop condition should be j<i, because s[i] is out of bounds (e.g., null terminator) and will be printed incorrectly.
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ Condition does not fully validate both characters are in the same valid range; e.g., it does not check that s[j-1] is ≤ the upper bound or s[j+1] is ≥ the lower bound, causing potential false matches.
            {
                int n=1;
                while(s[j-1]+n<=s[j+1]) // @@ This loop prints the ending character (s[j+1]), but the next iteration of the outer loop will print it again, causing duplication; also, no j increment is performed to skip the processed hyphen and ending character.
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