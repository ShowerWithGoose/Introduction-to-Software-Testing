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
    s->top++; // @@ [The increment happens even when the stack is full, causing out-of-bounds write and incorrect state]
    s->data[s->top] = e; // @@ [This assignment occurs even after printing "error", leading to invalid memory access and wrong behavior]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [This reads from an invalid index when the stack is empty, leading to undefined behavior]
    printf("%d ", e); // @@ [This prints a garbage value when the stack is empty instead of just "error "]
    s->top--; // @@ [Decrementing top when stack is already empty leads to invalid state (top becomes -2)]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declaring an array of 101 stacks is unnecessary; only one stack is needed. This doesn't cause direct error but indicates confusion]
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