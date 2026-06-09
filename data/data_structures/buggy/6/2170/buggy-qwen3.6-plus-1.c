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
    exit(-1); // @@ exit(-1) terminates the program immediately upon error, but the problem requires continuing to process subsequent operations after printing "error ".
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
    char ch1; // @@ ch1 should be int to correctly store integer operation codes (1, 0, -1) read from input.
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ Using %c reads whitespace characters (spaces/newlines) as input, causing incorrect parsing. Should use %d to read integers.
        getchar(); // @@ Unnecessary getchar() consumes valid input or whitespace, disrupting the input stream when reading integers.
        if(ch1=='1') { // @@ Compares with character '1' instead of integer 1. Should be ch1 == 1 after fixing scanf to %d.
            scanf("%d",&ch2);
            getchar(); // @@ Unnecessary getchar() disrupts input parsing.
            push(STACK,ch2);
        } else if(ch1=='0') { // @@ Compares with character '0' instead of integer 0. Should be ch1 == 0 after fixing scanf to %d.
            printf("%c ",STACK[top]); // @@ %c prints the integer value as a character. Should be %d to print the integer correctly.
            pop(STACK);
        }
    }
    return 0;
}