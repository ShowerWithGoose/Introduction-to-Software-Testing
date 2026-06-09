#include<stdio.h>
#include<string.h>
int main()
{
    char dec[1000]={0};
    int i, j, cnt=0, flag=0;
    gets(dec);
    if(dec[0]=='0')//判断输入小数得第一位是否为零，如果为零，则指数的符号为负
    {
        i=2;//跳过0和小数点从小数点后第一位开始检查
        while(dec[i]=='0') {i++; cnt++;}//从小数点后第一位开始计数，清点0的个数
        for(j=2; j<strlen(dec)-1; j++)
        {
            if(dec[j]!='0') flag=1;
        }
        if(flag==1) //当底数为小数时
        {
            printf("%c.", dec[i]);
            for(j=i+1; dec[j]!='\0'; j++) printf("%c", dec[j]);//打印底数部分的小数部分
        }
        else printf("%c", dec[strlen(dec)-1]);//当底数为正数时
        printf("e-%d", cnt+1);//打印指数部分
    }
    else//指数为正
    {
        i=0;
        while(dec[i]!='.') {i++; cnt++;}//从左向右寻找小数点,并记录指数
        if(strlen(dec)>1)//当底数为小数时
        {
            printf("%c.", dec[0]);//打印底数部分
            for(j=1; j<i; j++) printf("%c", dec[j]);
            for(j=i+1; dec[j]!='\0'; j++) printf("%c", dec[j]);
        }
        else //当底数为正数时
        {
            cnt=1;
            printf("%c", dec[0]);
        }
        printf("e%d", cnt-1);//打印指数部分
    }
    return 0;
}

