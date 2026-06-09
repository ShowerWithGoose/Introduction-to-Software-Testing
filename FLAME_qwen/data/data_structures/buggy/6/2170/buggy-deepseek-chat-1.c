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
    char ch1; // @@ [Error: ch1 is declared as char, but the input values (1, 0, -1) are integers, so reading as char will not correctly parse the integer operations]
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ [Error: scanf with %c reads a single character, but the input contains integers separated by spaces, so it will read spaces and newlines incorrectly]
        getchar(); // @@ [Error: getchar() consumes one character, but the input format has spaces between numbers, so this will incorrectly skip the space after the first number, potentially missing the next operation]
        if(ch1=='1') { // @@ [Error: ch1 is a char, comparing to '1' works only if the input is exactly the character '1', but the input is the integer 1, which when read as char becomes the character '1' only if the input is not separated by spaces correctly; however, the main issue is that the input parsing logic is fundamentally flawed]
            scanf("%d",&ch2); // @@ [Error: After reading ch1 as a character, this scanf reads an integer, but the input format has the push value after a space, so this may read the next operation number instead of the push value]
            getchar(); // @@ [Error: Another getchar() to consume newline, but the input may not have newlines, causing incorrect skipping]
            push(STACK,ch2);
        } else if(ch1=='0') { // @@ [Error: Same char vs int issue; also, the pop operation should output the popped value, but here it prints STACK[top] before popping, which is incorrect because it prints the top element before removing it, and also does not handle the case where pop returns the value]
            printf("%c ",STACK[top]); // @@ [Error: STACK[top] is an integer (elemtype is int), but %c prints it as a character, which will produce wrong output; should use %d]
            pop(STACK);
        }
    }
    return 0;
}