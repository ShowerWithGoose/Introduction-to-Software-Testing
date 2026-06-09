#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ The space after %d may cause input parsing issues; it expects a space after the number, which can lead to incorrect reading of subsequent inputs.
    if(j > 99){ // @@ The condition should be j >= 100 to check if the stack is full (since j is the current top index, and stack size is 99, valid indices are 0-98, so j=99 means full).
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ The new element should be stored at index j, not j+1, because j is the current top index (next available position). This causes the stack to skip index 0 and misalign elements.
    }
    return j + 1; // @@ This always increments j, even when the stack is full and an error occurs, which incorrectly updates the stack pointer.
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ The condition should be j <= 0 to check if the stack is empty (since j is the top index, j=0 means no elements, j-1 < 0 is equivalent but less clear).
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ Should print a[j-1] because j is the top index (next available position), so the top element is at index j-1.
    }
    return j - 1; // @@ This always decrements j, even when the stack is empty and an error occurs, which incorrectly updates the stack pointer.
}
int main(){
    int sig;
    int stack[99]; // @@ The stack size is 99, but the problem specifies a maximum capacity of 100, so it should be stack[100] to accommodate up to 100 elements.
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