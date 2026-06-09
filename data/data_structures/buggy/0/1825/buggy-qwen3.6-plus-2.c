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
    for(j=0;j<=i;j++) @@ [Loop bound error: should be j < i to avoid accessing the null terminator at s[i]]
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) @@ [Incomplete range validation: missing upper bound check for s[j-1] and lower bound check for s[j+1], which fails to strictly enforce that both characters are within the same specified range]
            {
                int n=1;
                while(s[j-1]+n<=s[j+1]) @@ [Logical error: condition <= causes the end character s[j+1] to be printed twice; should use < since s[j+1] will be printed in the next iteration]
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