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
    char ch1; // @@ The variable ch1 is declared as char, but stack operations are integers. Reading '1' as a char works for single digits, but reading multi-digit numbers or handling spaces via %c is fragile and incorrect for integer parsing logic described. More critically, the input format uses integers separated by spaces. Using %c reads one character at a time, including spaces or newlines, which breaks the logic. It should be int and use %d.
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ Using scanf with %c reads individual characters, not integers. This will read spaces and newlines as valid inputs, causing logic errors. It should read integers using %d into an int variable.
        getchar(); // @@ This consumes the next character (likely a space or newline), but combined with %c reading, it makes parsing unpredictable and incorrect for integer sequences.
        if(ch1=='1') { // @@ Comparing char '1' instead of integer 1. While this might work if input is strictly formatted with single digits, it fails for the general integer input description.
            scanf("%d",&ch2);
            getchar(); // @@ Unnecessary and potentially harmful consumption of characters after reading the integer.
            push(STACK,ch2);
        } else if(ch1=='0') { // @@ Comparing char '0' instead of integer 0.
            printf("%c ",STACK[top]); // @@ Error 1: Printing STACK[top] before popping is risky if logic changes, but more importantly, it prints using %c (character format) instead of %d (integer format). This causes "567" to be printed incorrectly (likely as a single character corresponding to ASCII value or truncated). It should print the result of pop() or the value using %d.
            pop(STACK);
        }
    }
    return 0;
}