#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k;
    char s[100];
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='-'&&s[i-1]<='9'&&s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<s[i+1])
        {
            for(j=0;j<=s[i+1]-s[i-1]-1;j++)
            {
                printf("%c",s[i-1]+j+1);
            }
            i++;
        }
        else if(s[i]=='-'&&s[i-1]<='Z'&&s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>='A'&&s[i-1]<s[i+1])
        {
            for(j=0;j<=s[i+1]-s[i-1]-1;j++)
            {
                printf("%c",s[i-1]+j+1);
            }

            i++;
        }
        else if(s[i]=='-'&&s[i-1]<='z'&&s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<s[i+1])
        {
            for(j=0;j<=s[i+1]-s[i-1]-1;j++)
            {
                printf("%c",s[i-1]+j+1);
            }

            i++;
        }

        else
            printf("%c",s[i]);
    }

    return 0;

}


