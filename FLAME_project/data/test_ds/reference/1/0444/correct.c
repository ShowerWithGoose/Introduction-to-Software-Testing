#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000000];
    scanf("%s",s);
    for(int i=0;i<=strlen(s);i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
        printf("%c",s[i]);
        else if(s[i]>='0'&&s[i]<='9')
            printf("%c",s[i]);
        else
        {
            if((s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])||(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]))
               {
                   for(int j=1;s[i-1]+j!=s[i+1];j++)
                    printf("%c",s[i-1]+j);
               }
                    else if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
                    {
                        for(int j=1;s[i-1]+j!=s[i+1];j++)
                        printf("%c",s[i-1]+j);
                    }
                         else printf("%c",s[i]);
        }
    }
        return 0;
}



