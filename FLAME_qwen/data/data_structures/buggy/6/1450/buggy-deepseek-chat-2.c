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
    s->top++; // @@ This line should be inside an else block to prevent incrementing top when stack is full. Currently, even if the stack is full and "error" is printed, top is still incremented, causing out-of-bounds access.
    s->data[s->top] = e;
}
//出栈
void out(together *s) {
    int e;
    if (s->top == -1) {
        printf("error ");
    }
    e = s->data[s->top]; // @@ This line should be inside an else block to prevent accessing data when stack is empty. Currently, even if the stack is empty and "error" is printed, it still tries to read from s->data[s->top], which is invalid.
    printf("%d ", e);
    s->top--;
}

int main()
{

    int num,e,i;
    together zhan[101]; // @@ This declares an array of 101 stack structures, but only one stack is needed. The code uses `zhan` as a pointer to a single stack, which is incorrect; it should be `together zhan;` and then `origin(&zhan);` and pass `&zhan` to functions.
    origin(zhan); // @@ Passing an array name decays to a pointer to the first element, but the function expects a pointer to a single `together` structure. This will cause incorrect memory access.
    while(1){
        scanf("%d", &num);
//1表示入栈操作，后跟一个整数（不为1、0和-1）为入栈元素
        if (num == 1) {
            scanf("%d",&e);
            push(zhan,e); // @@ Passing the array name instead of a pointer to a single stack structure.
        }
//0表示出栈操作
        else if(num == 0)
            out(zhan); // @@ Same issue as above.
//-1表示操作结束
        else if(num == -1)
            return 0;
    }
    return 0;
    
}