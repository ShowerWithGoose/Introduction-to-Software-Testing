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
    s->top++;
    s->data[s->top] = e; // @@ [Error: When the stack is full, the code prints "error " but still performs the push operation, which is incorrect. According to the problem, if a push operation is attempted when the stack is full, only "error " should be output, and the element should not be pushed.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [Error: When the stack is empty, the code prints "error " but still attempts to access s->data[s->top] and print a value, which is incorrect. According to the problem, if a pop operation is attempted when the stack is empty, only "error " should be output, and no element should be popped or printed.]
    printf("%d ", e);
    s->top--;
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Error: The stack is declared as an array of 101 structures, but only one stack is needed. This is not a logical error but a waste of memory. The main issue is that the code uses `zhan` (the array name) as a pointer to the stack, which works because the array name decays to a pointer, but it is unconventional and may cause confusion.]
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