#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char ch[100000]="";
long long MultiDivi(int a,int b);
int main()
{
    gets(ch);
    char *str=&ch[0];
    int len=strlen(ch);
    int flag=0;
    int i;
    int last=0;
    int mark[100000]={0};
    long long result=0;
    int pp=1;
    for(int i=0;i<len;i++)
    {
        if(ch[i]=='-')
        {
            mark[pp]=-i;
            pp++;
        }
        else if(ch[i]=='+')
        {
            mark[pp]=i;
            pp++;
        }
    }

    if(pp==1)
        result=MultiDivi(0,len-1);
    else
    {
        for(int q=0;q<=pp-1;q++)
        {
            if(mark[q]>=0&&q!=pp-1)
            {
                result=result+MultiDivi(abs(mark[q]),abs(mark[q+1]));
            }
            else if(mark[q]<0&&q!=pp-1)
            {
                 result=result-MultiDivi(abs(mark[q]),abs(mark[q+1]));
            }
            else if(q==pp-1)
            {
                if(mark[q]>0)
                {
                    result=result+MultiDivi(abs(mark[q]),abs(len-1));

                }
                else
                    result=result-MultiDivi(abs(mark[q]),len-1);
            }
        }
    }
    printf("%lld",result);
    return 0;
}
long long MultiDivi(int a,int b)
{
    long long re=0;
    int mark=0;  //如果遇到*则为1，如果遇到/则为-1，如果前面没有号则为0
    int point=a;;
    while(point<=b)
    {
        if(ch[point]>='0'&&ch[point]<='9')
        {
            long long num=0;
            int j;
            for(j=point;ch[j]>='0'&&ch[j]<='9';j++)//得到处理的数字
            {
                num=num*10+(ch[j]-'0');
            }

            if(mark==0)
                re=num;
            else if(mark==1)
                re=re*num;
            else
                re=re/num;
            point=j;

        }
        else if(ch[point]=='*')
        {
            mark=1;
            point++;
        }
        else if(ch[point]=='/')
        {
            mark=-1;
            point++;
        }

        else
            point++;
    }
    return re;
}

