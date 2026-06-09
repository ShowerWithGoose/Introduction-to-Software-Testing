#include<stdio.h>
int main()
{
    int a;
    while(scanf("%d",&a)!=EOF) // @@ 错误：未读取n控制循环，且将n也作为数据读入处理
    {
        printf("%d ",a); // @@ 错误：输出格式和内容错误，应输出叶子节点的值和高度
    }
    return 0;
}