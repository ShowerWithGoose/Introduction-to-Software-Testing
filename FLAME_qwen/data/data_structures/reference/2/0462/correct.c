#include<stdio.h>
#include<string.h>
char s[100050];
char c[100050];
char flag[100050];
int ce[100050];
int hold=0,ans;
int i=0,j=0,k=0,l=0,cnt=0;

int cal(int a,char m,int b)
{
    switch(m)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    }
}

int main()
{
    gets(s);
    for(i=0;i<strlen(s);i++)//去除空格
    {
        if(s[i]!=' ')
            c[j++]=s[i];
    }
    for(i=0;i<j;i++)//提取等式的第一个数
    {
        if(c[i]>='0'&&c[i]<='9')
            cnt=cnt*10+c[i]-'0';
        else
            break;
    }
    ans=cnt;
    cnt=0;
    for(i=0;i<j;i++)//
    {
        if(c[i]>='0'&&c[i]<='9')
            cnt=cnt*10+c[i]-'0';
        if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'||c[i]=='=')
        {
            flag[++k]=c[i];//储存符号
            ce[l++]=cnt;//储存数字
            cnt=0;
        }
    }
    for(i=0;i<k;i++)
    {
        if(flag[i]=='=')
            break;
        if(flag[i]=='+'||flag[i]=='-')
        {
            cnt=ce[i];
            hold=1;
            if(i!=k-1)
            {
                for(l=i+1;flag[l]=='*'||flag[l]=='/';l++)//计算乘除法
                cnt = cal(cnt,flag[l],ce[l]);
                ce[i]=cnt;
            }
            ans = cal(ans,flag[i],ce[i]);//计算加减法
        }
        if((flag[i]=='*'||flag[i]=='/')&&hold==0)//计算第一个数
            ans = cal(ans,flag[i],ce[i]);
    }
    printf("%d",ans);

    return 0;
}

