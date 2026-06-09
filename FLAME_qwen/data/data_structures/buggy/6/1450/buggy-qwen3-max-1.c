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
    s->top++; // @@ [The increment and assignment happen even when the stack is full, leading to buffer overflow. The code should only increment and assign if there's space.]
    s->data[s->top] = e; // @@ [This assignment occurs even after printing "error", which violates the requirement to not perform the push when full.]
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ [This reads from an invalid index when the stack is empty (after printing "error"), causing undefined behavior.]
    printf("%d ", e); // @@ [This prints a garbage value when the stack is empty because the previous read is invalid.]
    s->top--; // @@ [This decrements top below -1 when the stack is already empty, corrupting the stack state.]
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ [Declares an array of 101 stacks instead of a single stack. Should be 'together zhan;' to match usage in function calls.]
    origin(zhan); // @@ [Passes an array of stacks (zhan) to a function expecting a pointer to a single stack, causing type mismatch and undefined behavior.]
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ [Passes an array of stacks instead of a single stack, leading to incorrect memory access.]
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ [Same issue: passes array instead of single stack instance.]
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}