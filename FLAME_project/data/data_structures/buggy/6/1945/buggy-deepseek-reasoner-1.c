#include<stdio.h>
int a[100]={0};
int main()
{
    int x,i=0;
    scanf("%d",&x);
    while(x!=-1)
    {
        if(x==1)
        {
            scanf("%d",&x);
            if(i==99) // @@ 栈满条件错误：栈容量100，i从0到99有效，当i==99时栈还有空位（a[99]可用），应该是i==100才满。此处导致无法在最后一个位置push。
            {
                printf("error ");
            }
            else
            {
                a[i]=x;
                i++;
            }
        }
        else
        {
            if(i==0)
            {
                printf("error ");
            }
            else
            {
                a[i]=0; // @@ 出栈操作未输出弹出的元素，应该先i--然后printf("%d ", a[i]); 或者printf("%d ", a[i-1]); 再i--。此处只是将栈顶置0，无输出。
                i--;
            }
        }
        scanf("%d",&x);
    }
    return 0;
}