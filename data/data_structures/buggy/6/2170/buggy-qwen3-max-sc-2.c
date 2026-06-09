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
        getchar(); // @@ [This getchar() consumes the newline or space after the operation code, but the input format uses space-separated integers, not character-by-character with newlines. Using %c reads a single char including spaces, and then getchar() incorrectly skips the next character (which may be part of the next number).]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ [This extra getchar() after reading an integer will consume the next character (likely a space or newline), which interferes with the next operation read by %c, causing misalignment in input parsing.]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ [Printing STACK[top] as a char (%c) instead of an integer (%d). Also, this prints before popping, and if the stack is empty, it would have already crashed due to the Error() call in pop(), but here it accesses STACK[top] even when possibly invalid. Moreover, the pop() function is called after printing, so if the stack is empty, Error() is triggered inside pop(), but the print already accessed invalid memory.]
            pop(STACK);
        }
    }
    return 0;
}