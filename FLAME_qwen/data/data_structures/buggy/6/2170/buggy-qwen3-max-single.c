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
    exit(-1);
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
    char ch1;
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) {
        getchar(); // @@ [This getchar() consumes the newline or space after the operation code, but the input format uses space-separated integers, not character-by-character with newlines. This causes misalignment in reading input.]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ [This extra getchar() incorrectly consumes the next character (possibly the next operation), leading to skipped or misread inputs.]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ [Printing STACK[top] as a char (%c) instead of an integer (%d). Also, this prints before popping, and if stack is empty, it would access invalid memory. Moreover, the pop function already handles error, but here we access top without checking emptiness.]
            pop(STACK);
        }
    }
    return 0;
}