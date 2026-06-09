#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ Trailing space in scanf format string causes it to wait for non-whitespace input, potentially blocking or misreading subsequent inputs.
    if(j > 99){
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ Off-by-one error: j represents the current number of elements, so the new element should be stored at index j, not j+1.
    }
    return j + 1; // @@ Logical error: unconditionally returns j+1 even when the stack is full and push fails, incorrectly incrementing the element count.
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ Off-by-one error: when j is the count of elements, the top element is at index j-1, not j.
    }
    return j - 1; // @@ Logical error: unconditionally returns j-1 even when the stack is empty and pop fails, incorrectly decrementing the element count.
}
int main(){
    int sig;
    int stack[99]; // @@ Array size should be 100 to accommodate the maximum capacity of 100 elements as specified in the problem.
    int i = 0;
    while (scanf("%d", &sig)){
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i);
        }
    }
    return 0;
}