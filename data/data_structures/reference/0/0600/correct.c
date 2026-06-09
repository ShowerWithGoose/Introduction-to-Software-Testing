#include<stdio.h>
#include<string.h>
int main()
{
    char m,n,j,len,l,s[105]={0};
    scanf("%s",s);
    l=strlen(s);
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]=='-')
        {
            m=s[i-1];
            n=s[i+1];
            if(((m>='a' && n<='z') || (m>='A' && n<='Z') || (m>='0' && n<='9'))&&n>m)
            {
            len=n-m-1;
            for(j=1;j<=len;j++)
                printf("%c",++m);
            }
            else
                printf("-");
        }
        else
            printf("%c",s[i]);
    }
}

