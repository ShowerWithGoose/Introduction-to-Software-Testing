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
    s->top++; // @@ [The increment happens even when the stack is full, leading to buffer overflow. The assignment should only occur if there's space.]
    s->data[s->top] = e; // @@ [This line executes even after printing "error", causing undefined behavior when stack is full.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [This line executes even when the stack is empty, leading to reading from invalid memory.]
    printf("%d ", e); // @@ [Prints a value even when stack is empty, instead of only printing "error ".]
    s->top--; // @@ [Decrementing top when stack is empty leads to underflow (top becomes -2).]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declares an array of 101 stacks, but only one is needed. Should be 'together zhan;' or 'together zhan = {0};'.]
    origin(zhan); // @@ [Passes array 'zhan' (decays to pointer to first element) to function expecting pointer to single 'together', which works by accident but is logically wrong due to prior declaration.]
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