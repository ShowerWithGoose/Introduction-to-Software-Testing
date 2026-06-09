#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ 变量i未初始化，导致循环条件不可控。
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ 索引i错误，ch0尚未填充该位置，应使用变量j。
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ 逻辑错误：num计数方式与表达式计算无关，不满足题目要求。
    {
        for(int k=0;k<strlen(ch0)-1;k++)
            printf("%c",ch0[k]);
    }
    
    return 0;
}