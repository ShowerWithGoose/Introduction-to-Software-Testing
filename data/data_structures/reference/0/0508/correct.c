#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define eps 1e-10
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define arraynum(x) (sizeof(x)/sizeof(x[0]))

int main()
{
    char start[1000],end[1000];
    int i,j=0,k;
    int judge=0;
    gets(start);//输入一行字符

    for(i=0;i<strlen(start);i++)//从第一个开始挨个看
    {
        if(start[i]!='-') {end[j]=start[i];j++;}//如果不是-，直接付给新数组
        else//如果是-，开始判断
        {
            judge+=((isupper(start[i-1])!=0)&&(isupper(start[i+1])!=0)&&(start[i-1]<start[i+1]));//同为大写，且后大于前
            judge+=((islower(start[i-1])!=0)&&(islower(start[i+1])!=0)&&(start[i-1]<start[i+1]));//同为小写，且后大于前
            judge+=((isdigit(start[i-1])!=0)&&(isdigit(start[i+1])!=0)&&(start[i-1]<start[i+1]));//同为数字，且后大于前
            if(judge!=1)//表示不符合其中任何一条要求，还是原样付给新数组
            {
                 end[j]=start[i];
                 j++;
            }
            else//满足要求
            {
                for(k=(start[i+1]-start[i-1]);k>1;k--)//将中间字符付给新数组
                {
                    start[i-1]+=1;
                    end[j]=start[i-1];
                    j++;
                }
            }
        judge=0;
        }
    }
    end[j]='\0';//添加结尾

    puts(end);//输出新数组
    return 0;
}




