//
// Created by  on 2022/3/30.
//

#include "stdio.h"
#include "stdlib.h"
typedef int stackElem;//定义某个元素为栈存储的元素
typedef struct stackNode{
    stackElem elem;
    struct stackNode* down;
}stackNode;//stackNode为栈的节点
typedef struct stack{
    stackNode * up;
}stack;//stack为一个栈变量，存储着恒为NULL的base(用于判断栈的底)，以及存储着栈顶的up
stack * initStack();//初始化函数
int emptyStack(stack *p);//判断栈是否为空，空则返回1，非空返回0
int sizeStack(stack *p);//输出栈的大小
stackNode * pushStack(stack *p,stackElem Elem);//将某个元素加入到栈中
stackElem popStack(stack *p);//将某个元素返回并从栈中删除

int operate,num;

int main(){
    stack *a = initStack();
    while(1){
        scanf("%d",&operate);
        if(operate == -1) break;
        else if(operate == 1){
            scanf("%d",&num);
            pushStack(a,num);
        }
        else if(operate == 0){
            int flag = popStack(a);
            if(flag == EOF) printf("error ");
            else printf("%d ",flag);
        }

    }
    return 0;
}


/**********************************************************************************************************************/
stack * initStack(){
    stack *ret = (stack *)malloc(sizeof(stack));
    ret->up=NULL;
    return ret;
}
int emptyStack(stack *p){
    return (p->up==NULL) ? 1 : 0;
}
int sizeStack(stack *p){
    int ret=0;
    stackNode * temp=p->up;
    while(temp){
        temp = temp->down;
        ret++;
    }
    return ret;
}
stackNode * pushStack(stack *p,stackElem Elem){
    stackNode * new = (stackNode *)malloc(sizeof(stackNode));
    new->elem = Elem; new->down = p->up;
    p->up = new;
    return new;
}
stackElem popStack(stack *p) {
    if (p->up == NULL) return EOF;
    stackElem ret = (p->up->elem);
    stackNode *tmp = p->up;
    p->up = p->up->down;
    free(tmp);
    return ret;
}
