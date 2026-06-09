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
        getchar(); // @@ [This getchar() consumes the next character unconditionally, which may remove part of the input (e.g., the space or digit after '1'), leading to incorrect parsing.]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ [This extra getchar() after reading an integer may consume the next operation character (like '0', '1', or '-1'), causing the loop to skip it and break input parsing.]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ [Using %c to print an integer value (STACK[top]) is incorrect; it should be %d. This will output garbage characters instead of numbers. Also, this prints before popping, so if pop fails (though it won't due to Error()), it's logically wrong. But more critically, it accesses STACK[top] even if stack might be empty—but in this code, pop() would have already called Error() on empty, so maybe not reached. Still, printing before pop is odd. However, the real issue is %c vs %d.]
            pop(STACK);
        }
    }
    return 0;
}