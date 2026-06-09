#include<stdio.h>

int main()
{
    char s[10000];
    int k=0;
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if((s[i-1]<s[i+1])&&(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))||((s[i-1]<='0'&&s[i-1]>='9')&&(s[i+1]<='0'&&s[i+1]>='9'))||((s[i-1]>='A'&&s[i-1]<='Z')&&s[i+1]>='A'&&s[i+1]<='Z'))) // @@ The digit range condition is incorrect: `s[i-1]<='0'&&s[i-1]>='9'` is always false; should be `s[i-1]>='0'&&s[i-1]<='9'` (and similarly for s[i+1]).
            {
                k=s[i+1]-s[i-1];
                for(int j=1;j<k;j++) // @@ Loop bound is off by one: should be `j<=k` to print all intermediate characters (e.g., for a-d, prints b,c,d).
                {
                    printf("%c",s[i-1]+j);
                }
                // @@ Missing code: after printing expansion, the next character (s[i+1]) should be skipped. Either add `i++;` before the loop's end or `continue;` after the loop. Without skipping, the next character is printed again in the next iteration.
            }
            else
                printf("%c",s[i]);
        }
        else
        {
            printf("%c",s[i]);
        }
    }
}