#include<stdio.h>
#include<string.h>
int main()
{
    char m,n,j,len,l,os[105]={0};
    scanf("%s",os);
    l=strlen(os);
    for(int i=0;os[i]!=0;i++)
    {
        if(os[i]=='-')
        {
            m=os[i-1];
            n=os[i+1];
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
            printf("%c",os[i]);
    }
}

