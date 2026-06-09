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
    exit(-1); // @@ [Error: Exits program on error, but problem expects to continue and only output "error" followed by space]
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
    char ch1; // @@ [Error: Should be 'int' to read integer operations (1, 0, -1) correctly]
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ [Error: Should read integer with %d and compare to EOF or break when ch1 == -1]
        getchar(); // @@ [Error: Unnecessary and may consume needed input; should be removed]
        if(ch1=='1') { // @@ [Error: Should compare to integer 1, not character '1']
            scanf("%d",&ch2);
            getchar(); // @@ [Error: Unnecessary; should be removed]
            push(STACK,ch2);
        } else if(ch1=='0') { // @@ [Error: Should compare to integer 0]
            printf("%c ",STACK[top]); // @@ [Error: Should use %d to print integer, not %c]
            pop(STACK);
        }
    }
    return 0;
}