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
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) @@ [The condition checks only one side of the range for type validity; e.g., s[j-1] >= '0' but doesn't ensure s[j-1] <= '9', similarly for letters. This allows mixed-type cases like 'a'-'9' to pass incorrectly. Also, when j=0, s[j-1] accesses s[-1], causing undefined behavior.]
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