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
            if((s[i-1]<s[i+1])&&(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))||((s[i-1]<='0'&&s[i-1]>='9')&&(s[i+1]<='0'&&s[i+1]>='9'))||((s[i-1]>='A'&&s[i-1]<='Z')&&s[i+1]>='A'&&s[i+1]<='Z'))) // @@ Error: The condition for digits is reversed; it should be (s[i-1]>='0'&&s[i-1]<='9') and (s[i+1]>='0'&&s[i+1]<='9'). Also, the condition (s[i-1]<='0'&&s[i-1]>='9') is always false because a character cannot be both <= '0' and >= '9'.
            {
                k=s[i+1]-s[i-1];
                for(int j=1;j<k;j++)
                {
                    printf("%c",s[i-1]+j);
                }
                
            }
            else
                printf("%c",s[i]); // @@ Error: When expansion is not performed, the program should output the '-' character itself, but the current code outputs s[i] which is '-', which is correct for this case. However, the logic for handling the case where the characters are not of the same type or the first character is greater than the second is missing; the else branch should output '-' but the condition above incorrectly rejects valid expansions like '0-8' due to the digit range error.
        }
        else
        {
            printf("%c",s[i]);
        }
    }
}