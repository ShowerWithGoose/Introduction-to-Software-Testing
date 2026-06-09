#include<stdio.h>
typedef struct haha
{
    int x;
    int y[1000];
}haha;
int main()
{
    haha s;
    int q=0;
    int a;
    while(scanf("%d",&a)!=EOF)
    {
        if(a==1)
        {
            printf("%d",&s.y[q]); // @@ 错误：此处在push时应使用scanf读入要入栈的整数并存入s.y[q]，而不是printf；同时缺少栈满检查，应在入栈前判断q是否已达到最大容量100，若满则输出"error "并跳过入栈。
            q++; // @@ 错误：缺少栈满检查，在增加栈顶指针前应检查q是否等于100（最大容量），若满则不应执行该语句并输出"error "。
        }
        else if(a==0)
        {
            if(q==0)
            {
                printf("error"); // @@ 错误：输出缺少空格，应改为 printf("error ");
            }
            else
            {
                printf("%d ",s.y[--q]);
            }
            
        }
        else if(a==-1)
            {
                break;
            }
    }
    return 0;
}