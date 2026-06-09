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
            if((s[i-1]<s[i+1])&&(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))||((s[i-1]<='0'&&s[i-1]>='9')&&(s[i+1]<='0'&&s[i+1]>='9'))||((s[i-1]>='A'&&s[i-1]<='Z')&&s[i+1]>='A'&&s[i+1]<='Z'))) // @@ The condition for checking digits is logically inverted (<= '0' && >= '9' is always false). It should be >= '0' && <= '9'.
            {
                k=s[i+1]-s[i-1];
                for(int j=1;j<k;j++) // @@ The loop condition j<k excludes the last character (s[i+1]). It should be j<=k to include the end character in the expansion.
                {
                    printf("%c",s[i-1]+j);
                }

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