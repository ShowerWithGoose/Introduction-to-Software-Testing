#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef struct zhan{
    int  data[100];
    int top;
}together;

//建栈(初始化栈顶指针)
void origin(together * s){
    s->top = -1;
}
//判断栈是否为空
//bool empty(zhan s){
//    if (s.top == -1)return true;//1
//    else return false;//0
//}
//进栈
void push(together *s, int e) {
    if (s->top == 100 - 1) {
        printf("error ");
    }
    s->top++; // @@ [错误：当栈满时，即使打印了"error "，仍然执行了s->top++和赋值操作，导致数据被写入越界位置，且后续操作逻辑混乱。应该在打印错误后直接返回，不执行入栈操作]
    s->data[s->top] = e;
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [错误：当栈空时，即使打印了"error "，仍然执行了读取和打印操作，导致输出错误数据。应该在打印错误后直接返回，不执行出栈操作]
    printf("%d ", e);
    s->top--;
}

int main()
{

    int num,e,i;
    together zhan[101];
    origin(zhan);
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e);
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan);
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}