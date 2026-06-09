#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define M 1000 // @@ The problem specifies a maximum capacity of 100, so M should be 100.
typedef int elemtype;
elemtype STACK[M];
int top;
void Error(char s[]) {
    printf("%s",s);
    exit(-1); // @@ exit(-1) terminates the program immediately, but the problem requires continuing to process subsequent operations after printing "error ".
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
    char ch1; // @@ Should be declared as int to correctly read integer operation codes.
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ Using %c reads whitespace and does not correctly parse integer operation codes; should use %d and check for -1 to terminate.
        getchar(); // @@ Unnecessary and disrupts input parsing by consuming valid characters.
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ Unnecessary and disrupts input parsing by consuming valid characters.
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ STACK stores integers, so %d should be used instead of %c to print the value correctly.
            pop(STACK);
        }
    }
    return 0;
}