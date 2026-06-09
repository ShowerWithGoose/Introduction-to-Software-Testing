#include<stdio.h>
#include<string.h>
char in[1000];
int digit(char*);
int main()
{
    gets(in);
    in[strlen(in)]='e';
    in[strlen(in)+1]='\0';
    int wei=digit(in);
    if(wei>=0)printf("%s%d\n",in,wei);
    else if(0>wei)printf("%s%d\n",in-wei+1,wei);
    system("pause");
    return 0;
}

int digit(char *c)
{
    int re=0;
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
        re++;
    }
    if(2==flag)//判断是否为一位整数
    {
        if(0==re)return 0;
        *(c+re+1)='.';
        *(c+re+2)='e';
        *(c+re+3)='\0';
    }
    if(1==flag)//判断是否为纯小数
    {
        if(0==re&&'0'==*c)
        {
            flag=1;
        }
        else
        flag=2;
    }
    if(1==flag)//纯小数
    {
        re--;
        int i;
        for(i=2;*(c+i)=='0';i++)
        {
            re--;
        }
        if(*(c+i+1)=='e')
        {
            return re;
        }
        else
        {
            for(int j=strlen(c);j>=2+i;j--)
            {
                *(c+j)=*(c+j-1);
            }
            *(c+i+1)='.';
            return re;
        }
    }
    if(2==flag)//有正数过10位的部分
    {
        for(int i=re+1;i>=2;i--)
        {
            char temp=*(c+i);
            *(c+i)=*(c+i-1);
            *(c+i-1)=temp;
        }
        return re;
    }
}
