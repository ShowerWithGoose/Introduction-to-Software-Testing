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
    s->top++; // @@ [The increment happens even when the stack is full, leading to buffer overflow. The push operation should only proceed if the stack is not full.]
    s->data[s->top] = e; // @@ [This assignment occurs even after printing "error ", which is incorrect behavior. It should only assign if there's space.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [This reads from the stack even when it's empty (after printing "error "), which leads to undefined behavior.]
    printf("%d ", e); // @@ [This prints the value even when the stack was empty, which is wrong. Only print if pop is valid.]
    s->top--; // @@ [This decrements top even when the stack was empty, causing top to go below -1 and leading to further errors.]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declaring an array of 101 stacks is unnecessary and incorrect; only one stack is needed. Should be 'together zhan;' or 'together zhan_instance;'.]
    origin(zhan); // @@ [Passing an array of stacks to a function expecting a pointer to a single stack causes type mismatch and undefined behavior.]
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ [Passing an array of stacks instead of a single stack instance leads to incorrect memory access.]
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ [Same issue: passing array instead of single stack instance.]
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}