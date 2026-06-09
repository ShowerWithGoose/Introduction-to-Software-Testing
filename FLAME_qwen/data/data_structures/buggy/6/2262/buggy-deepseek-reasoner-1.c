#include<stdio.h>


int main()
{
    int a;
    while(~scanf("%d",&a)) // @@ 循环条件错误：没有按题目要求处理栈操作并以-1作为结束标志，而是持续读入直到EOF
    printf("%d ",a); // @@ 输出错误：应该输出弹出的元素序列和可能的"error"，而非简单打印每次读入的整数
    return 0;
}