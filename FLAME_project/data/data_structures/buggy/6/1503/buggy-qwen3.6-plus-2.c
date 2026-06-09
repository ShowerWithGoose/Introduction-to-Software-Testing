#include<stdio.h>
int main() {
    int n;
    while (scanf("%d", &n)==1) { // @@ The program simply reads integers and prints them, ignoring the stack logic (push/pop) described in the problem. It should implement a stack to handle operations 1 (push), 0 (pop), and -1 (end).
        printf("%d ", n); // @@ This line incorrectly outputs every input integer. It should only output values popped from the stack during a '0' operation, or "error" if the stack is empty/full.
    }
    return 0;
}