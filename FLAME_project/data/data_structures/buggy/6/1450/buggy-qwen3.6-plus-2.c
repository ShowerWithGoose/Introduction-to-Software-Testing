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
    else { // @@ The original code performs the push operation regardless of whether the stack is full. It should only push if the stack is not full, otherwise it just prints error and returns.
        s->top++;
        s->data[s->top] = e;
    }
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    else { // @@ The original code performs the pop operation and prints the element regardless of whether the stack is empty. It should only pop and print if the stack is not empty.
        e = s->data[s->top];
        printf("%d ", e);
        s->top--;
    }
}

int main()
{

    int num,e,i;
    together zhan; // @@ The original code declares an array 'zhan[101]' but uses it as a single stack instance. This is logically incorrect though it might compile, it should be a single struct instance.
    origin(&zhan); // @@ Corresponding change to pass address of single struct.
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(&zhan,e); // @@ Pass address of the single struct.
        }
//0表示出栈操作
        else if(num == 0)
            out(&zhan); // @@ Pass address of the single struct.
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}