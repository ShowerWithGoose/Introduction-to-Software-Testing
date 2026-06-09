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
            if((s[i-1]<s[i+1])&&(((s[i-1]>='a'&&s[i-1]<='z')&&(s[i+1]>='a'&&s[i+1]<='z'))||((s[i-1]<='0'&&s[i-1]>='9')&&(s[i+1]<='0'&&s[i+1]>='9'))||((s[i-1]>='A'&&s[i-1]<='Z')&&s[i+1]>='A'&&s[i+1]<='Z'))) // @@ [Digit range condition is incorrect: used `<= '0' && >= '9'` which is impossible; should be `>= '0' && <= '9'` for both s[i-1] and s[i+1]. This causes the expansion logic for digits to never be true, so for input "0-8", the hyphen is printed instead of digits.]
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