#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char num[2000];
char shu[2000];

int main()
{
    int len,k,j,i=0,m=0,l;//len是这个数字的长度,k为小数点的位置,j为第一个非零数的位置,l为新数字的长度
    gets(num);//读入小数
    len=strlen(num);//判断字符串的长度
    for(i=0;i<len;i++)//寻找小数点位置
    {
        if(num[i]=='.')
        {
            k=i;
            break;
        }
    }//由于题中描述，输入的一定为小数，不存在输入整数的情况，所以必定能找到小数点的位置
    if(k==1)
    {
        if(num[0]=='0')//说明化为科学记数法，10的n次方的n为负数
        {
            for(i=2;i<len;i++)//寻找第一个非零数的位置
            {
                if(num[i]!='0')
                {
                    j=i;
                    break;
                }
            }
            shu[0]=num[j];//将第一个非零数字存入shu这个数组中
            if(j!=(len-1))//说明num[j]不是num的最后一个数
            {
                shu[1]='.';
                for(i=j+1,m=2;i<len;i++,m++)
                    shu[m]=num[i];//将剩余的数字存入shu这个数组中
            }
            else//说明num[j]是最后一个数字
                m=1;
            for(i=0;i<m;i++)
                printf("%c",shu[i]);//输出科学计数法的小数部分
            printf("e-%d",j-1);//输出10的n次方部分
        }
        else//说明化为科学记数法，10的n次方的n为0
        {
            for(i=0;i<len;i++)
                printf("%c",num[i]);//直接输出num即可
            printf("e0");//输出科学计数法中的10的n次方
        }
    }
    else//说明化为科学记数法，10的n次方的n为正数
    {
        shu[0]=num[0];
        shu[1]='.';
        for(i=1,m=2;i<len;i++)
        {
            if(num[i]!='.')
            {
                shu[m]=num[i];//将num转换为科学记数法要求的小数放入shu中
                m++;
            }
        }
        for(i=0;i<len;i++)
            printf("%c",shu[i]);//输出科学记数法形式的表达式
        printf("e%d",k-1);//输出科学记数法形式的表达式
    }
}


