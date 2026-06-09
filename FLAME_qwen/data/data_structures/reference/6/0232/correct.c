//两种输出情况：出栈以及error（直接在函数内部输出！）
#include<stdio.h>

int stack[105];//不必循环队列！哈哈
int isempty(int top){
    if(top<0){
        printf("error ");
        return 0;
    }
    return 1;
}
int isfull(int top){//总共是0到99
    if(top>99){
        printf("error ");
        return 0;
    }
    return 1;
}
int main()
{
    int op,top=-1,input;
    scanf("%d",&op);
    while(op!=-1){
        if(op==1){//满栈还是会有元素在后面么！
            scanf("%d",&input);
            if(isfull(top)){
                stack[++top]=input;
            }
        }else if(op==0){
            if(isempty(top)){
                printf("%d ",stack[top--]);
            }
        }
        scanf("%d",&op);
    }
    return 0;
}

