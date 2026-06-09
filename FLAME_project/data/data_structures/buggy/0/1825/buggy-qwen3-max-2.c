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
    for(j=0;j<=i;j++) // @@ [Loop runs one past the last valid character; should be j < i because s[i] is '\0' or EOF marker, and accessing s[j+1] when j == i leads to out-of-bound read]
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ [Incorrect range checks: e.g., 's[j-1] >= '0'' but 's[j+1] <= '9'' doesn't ensure s[j-1] is a digit; same for letters. Should check both ends belong to same category. Also, when j=0, s[j-1] accesses s[-1], causing undefined behavior.]
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