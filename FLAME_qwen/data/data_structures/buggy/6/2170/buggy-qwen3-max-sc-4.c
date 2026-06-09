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
        getchar(); @@ [Using getchar() after reading a character with scanf("%c") consumes the next character (often a space or newline), which may be part of the input data, leading to incorrect parsing.]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); @@ [Similarly, this getchar() incorrectly consumes the next character after reading an integer, which may interfere with subsequent operations.]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); @@ [Printing STACK[top] as a character (%c) instead of an integer (%d) leads to wrong output format; also, accessing STACK[top] before checking if stack is empty can cause undefined behavior.]
            pop(STACK);
        }
    }
    return 0;
}