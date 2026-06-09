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
    while(scanf("%c",&ch1)!=-1) { @@ [Reading input as character 'ch1' instead of integer causes misinterpretation of operation codes; should read integers directly to match input format.]
        getchar(); @@ [Unconditionally consuming next character with getchar() disrupts input parsing, especially when numbers follow.]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); @@ [Extra getchar() after reading integer may consume next operation digit, leading to skipped or misread operations.]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); @@ [Printing popped value as character '%c' instead of integer '%d' leads to incorrect output format. Also, accessing STACK[top] before pop may cause undefined behavior if stack is empty (though Error exits).]
            pop(STACK);
        }
    }
    return 0;
}