#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000];
    int flag=0;
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++)
    {
        flag=0;
        if(s[i]=='-' && i!=0 && s[i+1]!='\0')
        {
            if(s[i-1]<s[i+1])
            {
                if((s[i-1]<='Z' && s[i-1]>='A' && s[i+1]<='Z' && s[i+1]>='A' )||(s[i-1]<='z' && s[i-1]>='a' && s[i+1]<='z' && s[i+1]>='a' )||(s[i-1]<='9' && s[i-1]>='0' && s[i+1]<='9' && s[i+1]>='0' ))
                {
                    for(int j=s[i-1]+1;j<s[i+1];j++)
                    {
                        printf("%c",j);
                        flag=1;
                    }
                }
            }
        }
        if(flag==0)
            printf("%c",s[i]);
    }
    return 0;
}
