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
        Error("error "); // @@ [Error: The pop function calls Error() which prints "error " and then exits the program. According to the problem, after printing "error ", the program should continue processing subsequent operations, not terminate. This causes the program to stop on the first error instead of continuing.]
    } else {
        return s[top--];
    }
}
int main() {
    char ch1; // @@ [Error: ch1 is declared as char, but the input values for operations are integers (1, 0, -1). Reading as char will not correctly interpret multi-digit numbers or negative numbers, and will cause incorrect parsing of the input.]
    int ch2;
    initial();
    while(scanf("%c",&ch1)!=-1) { // @@ [Error: Using scanf with %c reads a single character, but the input contains integers separated by spaces. This will not correctly parse the operation codes (1, 0, -1) and will also read spaces as characters, leading to incorrect behavior.]
        getchar(); // @@ [Error: This getchar() is intended to consume the space after the operation code, but it may consume the next integer's first digit or other characters, causing the input to be misread.]
        if(ch1=='1') { // @@ [Error: Comparing a char to the integer 1 is incorrect because ch1 is a character. It should be compared to '1' as a character, but the input is an integer, so this comparison will fail for multi-digit numbers or when the integer is read incorrectly.]
            scanf("%d",&ch2);
            getchar(); // @@ [Error: This getchar() may consume the space after the pushed integer, but if the next input is a newline or end-of-file, it can cause issues. Also, the input format uses spaces, so this may skip necessary characters.]
            push(STACK,ch2);
        } else if(ch1=='0') { // @@ [Error: Similar to above, comparing char to integer 0 is incorrect. Also, the operation code -1 is not handled, so the program will never terminate properly.]
            printf("%c ",STACK[top]); // @@ [Error: This prints the top element as a character using %c, but the stack stores integers (elemtype is int). This will output the ASCII character corresponding to the integer value, not the integer itself. It should use %d.]
            pop(STACK);
        }
    }
    return 0;
}