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
    while(scanf("%c",&ch1)!=-1) { // @@ [Reading input as character instead of integer causes misinterpretation of multi-digit operation codes; '1' is read correctly but subsequent digits like '5' from '567' are treated as separate operations]
        getchar(); // @@ [Unconditionally consuming next character discards part of the input, especially problematic when reading multi-digit numbers or operation sequences]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ [Consuming an extra character after reading integer may skip necessary whitespace or next operation token]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ [Printing popped value as character '%c' instead of integer '%d' leads to incorrect output (e.g., 567 printed as ASCII character for 567 mod 256)]
            pop(STACK);
        }
    }
    return 0;
}