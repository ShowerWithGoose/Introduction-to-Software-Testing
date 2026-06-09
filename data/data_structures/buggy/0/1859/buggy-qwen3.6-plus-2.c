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
            if((s[i-1]<s[i+1])&&(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))||((s[i-1]<='0'&&s[i-1]>='9')&&(s[i+1]<='0'&&s[i+1]>='9'))||((s[i-1]>='A'&&s[i-1]<='Z')&&s[i+1]>='A'&&s[i+1]<='Z'))) // @@ The condition for digits is logically impossible: (s[i-1]<='0'&&s[i-1]>='9') should be (s[i-1]>='0'&&s[i-1]<='9'). Same for s[i+1].
            {
                k=s[i+1]-s[i-1];
                for(int j=1;j<k;j++) // @@ The loop condition j<k misses the last character of the expansion. It should be j<=k to include s[i+1].
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