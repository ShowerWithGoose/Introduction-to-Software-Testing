#include<stdio.h>
int main() {
    int n;
    while (scanf("%d", &n)==1) { // @@ The program simply reads and prints all input integers, ignoring the stack logic (push/pop/end) described in the problem. It should implement a stack to handle operations 1 (push), 0 (pop), and -1 (end).
        printf("%d ", n); // @@ This line incorrectly outputs every input number. It should only output popped elements or "error" based on stack operations.
    }
    return 0;
}