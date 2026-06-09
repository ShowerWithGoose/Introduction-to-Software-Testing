#include<stdio.h>
#include<string.h>
char s[1000],sig[1000];
int num[1000];

int str_to_num(char *start)
{
    int j=0,times=1;
    int number=0;
    while(*(start+j)<='9' && *(start+j)>='0') j++;
    for(j-=1;j>=0;j--)
    {
        number+=(*(start+j)-'0')*times;
        times*=10;
    }
    return number;
}

int main()
{
    int j=0,i=0,k=0,h=0;
    gets(s);

    for(i=j=0;s[i]!='\0';i++) //去除数组内的空格
        if(s[i]!=' ')
            s[j++]=s[i];
    s[j]='\0';

    num[0]=str_to_num(s);
    for(int x=0;s[x]!='=';x++) //将数字和符号拆分开分别放在两个数组中
    {
        if (!(s[x]<='9' && s[x]>='0'))
        {
            sig[k++]=s[x];
            num[k]=str_to_num(s+x+1);
        }
    }

    for (int x = 0; x < k; x++) //先算乘除，结果放置于后一位，前一位用-1替换
    {
        if(sig[x]=='*')
        {
            num[x+1]=num[x]*num[x+1];
            num[x]=-1;
        }
        else if(sig[x]=='/')
        {
            num[x+1]=num[x]/num[x+1];
            num[x]=-1;
        }
    }

    for(i=j=0; i<k+1 ;i++) //去除数组内的-1
        if(num[i]!=-1)
            num[j++]=num[i];

    h=0;
    for(int x=0;x<k;x++) //后算加减，去除-1，加减计算结果保留在后一位
    {
        if(sig[x]=='+')
        {
            // for(h=x+1;num[h]==-1;h++); //跳过-1
            num[h+1]=num[h]+num[h+1];
            h++;
        }
        else if(sig[x]=='-')
        {
            // for(h=x+1;num[h]==-1;h++);
            num[h+1]=num[h]-num[h+1];
            h++;
        }
    }
    printf("%d",num[h]);
    getchar();
    return 0;
}
