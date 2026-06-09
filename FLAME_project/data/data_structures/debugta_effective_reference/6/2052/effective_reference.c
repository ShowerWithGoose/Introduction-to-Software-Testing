#include <stdio.h>
#include <stdlib.h>
#define maxline 100
#define SElemType int
SElemType STACK[maxline];
int top;

//初始化一个堆栈
void INITIALS(int *top)
{
    *top=-1;
}

//测试堆栈是否为空
int EMPTYS(int top)
{
    return top==-1;
}

//测试堆栈是否已满
int FULLS(int top)
{
    return top==maxline-1;
}

//取当前栈顶元素
int GETTOPS(SElemType STACK[],int top,int *item)
{
    if(EMPTYS(top))
        return 0;
    else{
        *item=STACK[top];
        return 1;
    }
}

//插入（进栈）
int PUSH(SElemType STACK[],int *top,SElemType item)
{
    if(FULLS(*top))
        return 0;
    else{
        STACK[++(*top)]=item;
        return 1;
    }
}

//删除（退栈）
int POP(SElemType STACK[],int *top,SElemType *item)
{
    if(EMPTYS(*top))
        return 0;
    else{
        *item=STACK[(*top)--];
        return 1;
    }
}


int main()
{
    int op=0,n=0;
    INITIALS(&top);

    do{
        scanf("%d",&op);
        if(op==1){
            scanf("%d",&n);
            PUSH(STACK,&top,n);
        }
        else if(op==0){
            if(EMPTYS(top)||FULLS(top)){
                printf("error ");
            }
            else{
                printf("%d ",STACK[top]);
                POP(STACK,&top,&n);
            }
        }
    }while(op!=-1);

    return 0;
}

