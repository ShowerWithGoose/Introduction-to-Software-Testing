#include<stdio.h>
int main()
{
    char s[100];
    int i,j,k,gang,m;
    gets(s);
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            printf("%c",s[i]);
        }
        else
        {
            if(s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1]||s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1]||s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])
            {
                for(k=1;k<s[i+1]-s[i-1];k++)
                {
                    printf("%c",s[i-1]+k);
                }
            }
            else
            {
                printf("-");
            }
        }
    }
    system("pause");
    return 0;
}

