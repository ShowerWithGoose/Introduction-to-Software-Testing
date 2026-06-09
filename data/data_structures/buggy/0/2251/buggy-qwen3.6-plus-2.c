#include <stdio.h>
#include <string.h> 

char s[10000000];
int i,len,j,lenth;

int main()
{
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Incorrect range validation; fails to check upper bound for s[i-1] and lower bound for s[i+1], allowing non-digit characters to pass.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Loop starts at 0, causing the character before '-' to be printed again; should start at 1.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Incorrect range validation; fails to check upper bound for s[i-1] and lower bound for s[i+1].
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Loop starts at 0, causing the character before '-' to be printed again; should start at 1.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Incorrect range validation; fails to check upper bound for s[i-1] and lower bound for s[i+1].
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Loop starts at 0, causing the character before '-' to be printed again; should start at 1.
                    printf("%c",s[i-1]+j);
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}