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
    s->top++; // @@ [The increment happens even when the stack is full, leading to buffer overflow. The assignment should only occur if not full.]
    s->data[s->top] = e; // @@ [This writes beyond the array bounds when stack is full because s->top was already incremented after the full check.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [This reads from an invalid index when the stack is empty (s->top == -1), causing undefined behavior.]
    printf("%d ", e);
    s->top--;
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declares an array of 101 stacks instead of a single stack. Should be 'together zhan;' or 'together zhan = {0};']
    origin(zhan); // @@ [Passes an array of stacks (zhan[101]) to a function expecting a pointer to a single stack, causing type mismatch and undefined behavior.]
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ [Passes array of stacks instead of a single stack instance.]
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ [Same issue: passes array instead of single stack.]
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}