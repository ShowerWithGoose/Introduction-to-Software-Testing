#include<stdio.h>
#include<string.h>
#include<ctype.h>
int calculate(char a[])
{
    int ans=0,num=0,number[1000],sym=0,chengchu[1000],flag[1000],flag1=0,flag2=0,flag3=0;//num为数字数目，number数组存数字，sym为符号数目，symbol为符号数组，chengchu计算乘除部分结果,flag标记乘除位置
    memset(number,0,sizeof(number));
    memset(flag,0,sizeof(flag));
    for(int i=1;i<=1000;i++)
    {
        chengchu[i]=1;
    }
    char b[1000]={'0'},symbol[1000];
    int l=strlen(a);
    for(int i=0,j=0;i<l;i++)
    {
        if(a[i]!=' ')
        {
            b[j++]=a[i];
        }
    }
    int l1=strlen(b);
    int i=0,j=0;
    while(i<l1)
    {
        if(!isdigit(b[i]))
        {
            i++;
            continue;
        }
        num++;
        j=i;
        while(isdigit(b[j]))
        {
            number[num]*=10;
            number[num]+=b[j]-'0';
            j++;
        }
        i=j;
    }
    for(int i=0;i<l1;i++)
    {
        if(!isdigit(b[i]))
        {
            sym++;
            symbol[sym]=b[i];
        }
    }
    int mark=0,mark1;
    if(symbol[1]=='=')
    return number[1];
    for(int i=1;i<=sym;i++)
    {
        if((symbol[i]=='*')||(symbol[i]=='/'))
        {
            mark=i;
            flag[mark]=1;
            mark1=i;
            for(;mark1<=sym;mark1++)
            {
                if(symbol[mark1]=='*')
                {
                    if(chengchu[mark]==1&&flag2==0)
                    {
                        chengchu[mark]*=number[mark1];
                        flag2=1;
                    } 
                    chengchu[mark]*=number[mark1+1];    
                }
                else if(symbol[mark1]=='/')
                {
                    if(chengchu[mark]==1&&flag2==0)
                    {
                        chengchu[mark]*=number[mark1];
                        flag2=1;
                    }
                    chengchu[mark]/=number[mark1+1];    
                }
                else break;
            }
            i=mark1;
        }
        flag2=0;
    }
    int k;
    for(k=1;k<sym;k++)
    {
        if((symbol[k]=='+')||(symbol[k]=='-'))
        {
           flag1=1;
           if(symbol[k]=='+')
            {
                if(ans==0)
                {
                    if(flag[1])
                    {
                        ans+=chengchu[1];
                    }
                    else ans+=number[1];
                }
                if(flag[k+1])
                {
                    ans+=chengchu[k+1];
                }
                else
                ans+=number[k+1];
            }
            else if(symbol[k]=='-')
            {
                if(ans==0)
                {
                    if(flag[1])
                    {
                        ans+=chengchu[1];
                    }
                    else ans+=number[1];
                }
                if(flag[k+1])
                {
                    ans-=chengchu[k+1];
                }
                else
                ans-=number[k+1];
            }
        }
    }
    if(ans==0&&flag1==0)
    ans=chengchu[1];
    return ans;
}
int main()
{
    char s[1000];
    gets(s);
    printf("%d",calculate(s));
    return 0;
}
