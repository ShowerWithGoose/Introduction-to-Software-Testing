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
    for(j=0;j<=i;j++)
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ [Incorrect boundary checks: conditions like `s[j-1]>='0' && s[j+1]<='9'` do not ensure both characters are digits; should also check `s[j-1]<='9' && s[j+1]>='0'` (and similarly for letters). Also, accessing s[j-1] or s[j+1] when j=0 or j=i may cause out-of-bounds access.]
            {
                int n=1;
                while(s[j-1]+n<=s[j+1])
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