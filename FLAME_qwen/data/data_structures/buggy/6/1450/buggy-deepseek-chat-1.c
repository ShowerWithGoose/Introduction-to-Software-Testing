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
    s->top++; // @@ This line should be inside an else block to prevent pushing when stack is full. Currently, it always increments top even after printing "error", causing incorrect behavior.
    s->data[s->top] = e;
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ This line should be inside an else block to prevent accessing data when stack is empty. Currently, it always executes even after printing "error", causing undefined behavior.
    printf("%d ", e);
    s->top--;
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ This declares an array of 101 stack structures, but only one stack is needed. It should be `together zhan;` instead.
    origin(zhan); // @@ This passes the array (pointer to first element) to origin, but origin expects a pointer to a single stack. This is a type mismatch and will cause incorrect initialization.
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ This passes the array (pointer to first element) to push, but push expects a pointer to a single stack. This is a type mismatch.
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ This passes the array (pointer to first element) to out, but out expects a pointer to a single stack. This is a type mismatch.
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}