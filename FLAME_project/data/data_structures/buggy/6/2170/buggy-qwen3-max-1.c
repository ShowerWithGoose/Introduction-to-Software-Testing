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
        getchar(); // @@ [Using %c reads one character at a time, so '1' from input "1 567" is read as '1', but the following space is consumed by getchar(), which is okay. However, the bigger issue is that the input "1 567" has multi-digit number 567, but the logic assumes single-character operations only. Also, the loop condition and input parsing are fundamentally flawed because it treats operation codes as characters instead of integers.]
        if(ch1=='1') {
            scanf("%d",&ch2);
            getchar(); // @@ [This getchar() consumes the newline or space after the integer, but may cause issues if input format varies. However, the critical error is elsewhere.]
            push(STACK,ch2);
        } else if(ch1=='0') {
            printf("%c ",STACK[top]); // @@ [This prints the top element as a character (%c) instead of an integer (%d). For example, 567 is stored as integer, but printing with %c outputs only the least significant byte interpreted as ASCII, which for 567 (0x237) gives 0x37 = '7'. This causes the output "7" instead of "567".]
            pop(STACK);
        }
    }
    return 0;
}