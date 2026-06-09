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
            if((s[i-1]<s[i+1])&&(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))||((s[i-1]<='0'&&s[i-1]>='9')&&(s[i+1]<='0'&&s[i+1]>='9'))||((s[i-1]>='A'&&s[i-1]<='Z')&&s[i+1]>='A'&&s[i+1]<='Z'))) // @@ Error: The condition for digits is reversed. It should be (s[i-1]>='0'&&s[i-1]<='9') and (s[i+1]>='0'&&s[i+1]<='9'), not using <= and >= incorrectly. Also, the condition (s[i-1]<='0'&&s[i-1]>='9') is logically impossible because a character cannot be both <= '0' and >= '9' simultaneously.
            {
                k=s[i+1]-s[i-1];
                for(int j=1;j<k;j++)
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