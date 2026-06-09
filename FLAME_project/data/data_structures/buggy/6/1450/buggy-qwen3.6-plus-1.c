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
    } // @@ The function continues to execute the push logic (incrementing top and assigning data) even when the stack is full, which causes incorrect state and potential buffer overflow. It should return after printing "error ".
    s->top++;
    s->data[s->top] = e;
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    } // @@ The function continues to execute the pop logic (accessing data and decrementing top) even when the stack is empty, which causes accessing invalid memory and incorrect output. It should return after printing "error ".
    e = s->data[s->top];
    printf("%d ", e);
    s->top--;
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ Although only one stack is needed, declaring an array doesn't inherently cause the logic error, but 'origin(zhan)' initializes the first element. The main logical errors are in push/out not stopping on error.
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