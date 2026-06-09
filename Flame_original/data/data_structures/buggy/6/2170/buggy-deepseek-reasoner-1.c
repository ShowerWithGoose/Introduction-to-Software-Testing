#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define M 1000
typedef int elemtype;
elemtype STACK[M];
int top;
void Error(char s[]) {
    printf("%s",s);
    exit(-1); // @@ 错误：使用exit(-1)导致程序终止，而题目要求输出"error "后继续执行后续操作，不应退出。
}
void initial() {
    top=-1;
}
int isempty() {
    return top==-1;
}
int isfull() {
    return top==M-1;
}
void push(elemtype s[],elemtype item) {
    if(isfull()) {
        Error("error ");
    } else {
        s[++top]=item;
    }
}
elemtype pop(elemtype s[]) {
    if(isempty()) {
        Error("error ");
    } else {
        return s[top--];
    }
}
int main() {
    char ch1; // @@ 错误：应使用整数变量读取操作类型，因为输入是整数（如1,0,-1），字符读取会得到ASCII码值，导致逻辑错误。
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ 错误：应使用scanf("%d",&flag)读取整数，并判断flag是否为-1以结束循环；当前字符读取无法正确处理输入。
        getchar(); // @@ 错误：多余的getchar()，会错误地消耗输入中的下一个字符（如空格或数字），破坏读取逻辑。
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ 错误：多余的getchar()，可能导致后续输入丢失。
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ 错误：应使用%d输出整数，并且应在成功pop后输出pop的值，而不是先输出栈顶元素再pop；若栈空，此处会导致未定义行为。
            pop(STACK);
        }
    }
    return 0;
}