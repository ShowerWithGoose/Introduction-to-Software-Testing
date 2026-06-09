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
    exit(-1); // @@ [exiting terminates program, but problem expects to continue after printing error]
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
        Error("error "); // @@ [Error function exits, should not exit; instead print and return]
    } else {
        s[++top]=item;
    }
}
elemtype pop(elemtype s[]) {
    if(isempty()) {
        Error("error "); // @@ [Error function exits, should not exit; instead print and return]
    } else {
        return s[top--];
    }
}
int main() {
    char ch1; // @@ [should be int to read integer operations]
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ [using %c to read integer operations; should use %d]
        getchar(); // @@ [unnecessary and may skip essential characters like parts of -1]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ [unnecessary and may cause issues]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ [should use %d for integer; also does not check for empty stack]
            pop(STACK);
        }
    }
    return 0;
}