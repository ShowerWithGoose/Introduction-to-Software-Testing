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
    exit(-1); // @@ Error: should not terminate the program; continue after printing "error "
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
    char ch1; // @@ Error: should be int to read integer operation codes (1, 0, -1)
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ Error: reading character instead of integer; also condition should check for EOF; should read integer and break on -1
        getchar(); // @@ Error: unnecessary and disrupts input parsing
        if(ch1=='1') { // @@ Error: comparing char with '1'; should compare int with 1
            scanf("%d",&ch2);
            getchar(); // @@ Error: unnecessary
            push(STACK,ch2);
        } else if(ch1=='0') { // @@ Error: comparing char with '0'; should compare int with 0
            printf("%c ",STACK[top]); // @@ Error: should use %d to print integer; also if stack is empty, STACK[-1] is invalid
            pop(STACK);
        }
    }
    return 0;
}