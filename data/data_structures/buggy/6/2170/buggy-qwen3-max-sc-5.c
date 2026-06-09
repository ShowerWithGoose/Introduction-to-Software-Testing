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
    while(scanf("%c",&ch1)!=-1) { @@ [Reading input as character instead of integer causes misinterpretation of operation codes; should read integers directly]
        getchar(); @@ [Unconditionally consuming next character discards part of the input, especially problematic when reading multi-digit numbers or spaces]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); @@ [Consuming extra character after reading integer may skip necessary whitespace or next operation]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); @@ [Printing popped value as character '%c' instead of integer '%d'; also prints before actual pop and without checking emptiness]
            pop(STACK);
        }
    }
    return 0;
}