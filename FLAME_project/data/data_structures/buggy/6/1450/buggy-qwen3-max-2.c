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
    s->top++; // @@ [The increment happens even when the stack is full, leading to buffer overflow and incorrect behavior. The push should be skipped entirely on error.]
    s->data[s->top] = e; // @@ [This assignment occurs even after printing "error ", which is wrong. When stack is full, no modification should happen.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [This reads from invalid memory when stack is empty (after printing "error "). Should only execute if stack is not empty.]
    printf("%d ", e); // @@ [Prints popped value even when stack was empty, which is incorrect. Should only print when pop is valid.]
    s->top--; // @@ [Decrements top even when stack was empty, causing underflow (top becomes -2, etc.). Should only decrement on valid pop.]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declares an array of 101 stacks instead of a single stack. This is likely a typo; should be 'together zhan;' or 'together zhan;' not an array.]
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