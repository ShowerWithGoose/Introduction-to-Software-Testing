#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int stack[110];
int main()
{
    int top=0;
    int op,num;
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(top==99) // @@ 错误：满栈条件应为 top==100（栈容量为100）或 top>=100，此处错误地使用了 top==99
            printf("error ");
            else
            {
                stack[top]=num;
                top++;
            }
        }
        else if(op==0)
        {
            if(top==0)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ 错误：栈顶元素应为 stack[top-1]，因为 top 指向下一个空闲位置，而非当前栈顶
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}