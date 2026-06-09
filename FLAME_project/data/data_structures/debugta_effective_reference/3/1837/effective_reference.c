#include<stdio.h>
#include<string.h>
char in[1000];
int digit(char*);
int main()
{
    gets(in);
    in[strlen(in)]='e';
    in[strlen(in)+1]='\0';
    int whe=digit(in);
    if(whe>=0)printf("%s%d\n",in,whe);
    else if(0>whe)printf("%s%d\n",in-whe+1,whe);
    system("pause");
    return 0;
}

int digit(char *c)
{
    int cnt=0;
    int flag=0;
    for(int i=1;0==flag;i++)//判断有无小数点
    {
        if('.'==*(c+i))
        {
            flag=1;
            break;
        }
        if('e'==*(c+i))
        {
            flag=2;
            break;
        }
        cnt++;
    }
    if(2==flag)//判断是否为一位整数
    {
        if(0==cnt)return 0;
        *(c+cnt+1)='.';
        *(c+cnt+2)='e';
        *(c+cnt+3)='\0';
    }
    if(1==flag)//判断是否为纯小数
    {
        if(0==cnt&&'0'==*c)
        {
            flag=1;
        }
        else
        flag=2;
    }
    if(1==flag)//纯小数
    {
        cnt--;
        int i;
        for(i=2;*(c+i)=='0';i++)
        {
            cnt--;
        }
        if(*(c+i+1)=='e')
        {
            return cnt;
        }
        else
        {
            for(int j=strlen(c);j>=2+i;j--)
            {
                *(c+j)=*(c+j-1);
            }
            *(c+i+1)='.';
            return cnt;
        }
    }
    if(2==flag)//有正数过10位的部分
    {
        for(int i=cnt+1;i>=2;i--)
        {
            char temp=*(c+i);
            *(c+i)=*(c+i-1);
            *(c+i-1)=temp;
        }
        return cnt;
    }
}
