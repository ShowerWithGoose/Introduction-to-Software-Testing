//我学到的 1.fgets会读取并储存回车，因此字符串以'\n\0'结尾，而非只有'\0' 2.if后面不要带分号

#include<stdio.h>
char s[105];
int main()
{
    fgets(s,105,stdin);
    int i=0;
    int position=0;
    int before=0,behind=0;
    int p_first=0;
    int temp=0;
    while(s[i]!='\0')
    {
        if(s[i]=='.')//找到小数点的位置
        {
            position=i;
        }
        else if(!(s[i]=='0') && temp==0)//找到第一个非零数的位置
        {
            temp++;
            p_first=i;
        }
        i++;
    }
    for(i=0;s[i]!='\0';i++)//找到小数点前后的位数
    {
        if(i<position)
            before++;
        if(i>position)
            behind++;
    }

    if(position-p_first>=1)//数字大于等于1
    {
        printf("%c",s[p_first]);
        printf(".");
        for(i=p_first+1;s[i]!='\0';i++)//从第二个非零数开始
        {
            if(s[i]=='\n')
                continue;
            if(s[i]=='.')
                continue;
            else
                printf("%c",s[i]);
        }
        printf("e");
        printf("%d",position-p_first-1);
    }
    else//数字小于一
    {
        printf("%c",s[p_first]);
        if(s[p_first+1]!='\n')//如果不是最后一位
            printf(".");
        for(i=p_first+1;s[i]!='\0';i++)//从第二个非零数开始
        {
            if(s[i]=='\n')
                continue;
            printf("%c",s[i]);
        }
        printf("e");
        printf("%d",position-p_first);
    }
    system("pause");
    return 0;
}
