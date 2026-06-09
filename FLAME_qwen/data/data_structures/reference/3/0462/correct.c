#include<stdio.h>
#include<string.h>

int main()
{
    char a[150],b[150];
    int cnt=0,m,flag,ans,i,be,af=0,j=0;
    scanf("%s",a);
    for(i=0;i<strlen(a);i++)//判断底数部分是整数还是小数
    {
        if(a[i]=='.')
            be=i;
        if(a[i]!='0'&&a[i]!='.'&&cnt==0)
        {
            flag=i;
            m=a[i]-'0';
        }
        if(a[i]!='0'&&a[i]!='.')
            cnt++;
    }
    for(i=flag;i<strlen(a);i++)//底数部分
    {
        if(j==1)
            b[j++]='.';
        if(a[i]!='.')
            b[j++]=a[i];
    }
    if(cnt==1)//底数部分是整数且小于1
    {
        ans=flag-1;
        printf("%de-%d",m,ans);
    }
    else
    {
        for(i=0;i<j;i++)
        {
            printf("%c",b[i]);
        }
        if(a[0]=='0')//小于1
            printf("e-%d",flag-be);
        else
            printf("e%d",be-1);
    }

    return 0;
}



