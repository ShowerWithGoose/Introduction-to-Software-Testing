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
    char ch1; // @@ The variable ch1 is declared as char, but stack operations are integers. Reading '1' as a char works for single digits, but reading multi-digit numbers or handling spaces/newlines with %c is fragile and incorrect for integer input parsing. It should be an int.
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ Using scanf with %c reads characters one by one, including spaces and newlines. This makes parsing integer operations like "1 567" extremely difficult and error-prone because it doesn't skip whitespace automatically like %d does, and it splits multi-digit numbers into individual characters. It should use %d to read integers.
        getchar(); // @@ This consumes the next character (likely a space or newline), which disrupts the parsing logic further when combined with %c. If switching to %d for ch1, this is unnecessary and harmful.
        if(ch1=='1') { // @@ Comparing a char '1' instead of integer 1. While this might work if input is strictly single chars, it fails for robust integer parsing. Should compare with integer 1 if ch1 is int.
            scanf("%d",&ch2);
            getchar(); // @@ Consumes trailing whitespace/newline. Unnecessary if using proper integer scanning loop.
            push(STACK,ch2);
        } else if(ch1=='0') { // @@ Comparing char '0' instead of integer 0.
            printf("%c ",STACK[top]); // @@ Error 1: Printing STACK[top] directly accesses the array without popping properly via the function (though pop is called next). Error 2: Using %c format specifier prints the integer value as a character (ASCII), not the number itself. For 567, it prints garbage or truncated data. It should print the result of pop() or STACK[top] using %d.
            pop(STACK);
        }
    }
    return 0;
}