#include <stdio.h>
int main()
{
    char s[1000]={0};
    int i=0;
    while(scanf("%c",&s[i])!=EOF) // @@ [This reads all characters including newline; may cause extra characters in output. Better to stop at newline.]
    {
        i++;
    }
    int j;
    for(j=0;j<=i;j++) // @@ [Loop condition includes s[i] which is null terminator; also after expansion, j should be moved forward to skip the end character, but here j is only incremented by 1.]
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ [Incomplete range checks: digit condition missing lower bound for end and upper bound for start; letter conditions missing lower bound for end character; also allows mixed types because conditions are not symmetric.]
            {
                int n=1;
                while(s[j-1]+n<=s[j+1]) // @@ [Should be '<' to exclude the end character, otherwise it will be printed twice.]
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