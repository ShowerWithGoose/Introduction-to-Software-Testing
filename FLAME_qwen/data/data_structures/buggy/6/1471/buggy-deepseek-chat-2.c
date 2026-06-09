#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ The format string includes a trailing space, which may cause issues with input parsing; it should be "%d" without the space.
    if(j > 99){
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ The element should be stored at index j, not j+1, because j represents the current top index (next empty position). This causes the stack to skip index 0 and misalign.
    }
    return j + 1; // @@ The return value should be j+1 only when push succeeds, but it always returns j+1 even on error, which corrupts the stack index.
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ Should print a[j-1] because j is the next empty index, so the top element is at j-1.
    }
    return j - 1; // @@ The return value should be j-1 only when pop succeeds, but it always returns j-1 even on error, which corrupts the stack index.
}
int main(){
    int sig;
    int stack[99]; // @@ The stack size is 99, but the problem specifies a maximum capacity of 100. It should be int stack[100];.
    int i = 0;
    while (scanf("%d", &sig)){ // @@ The loop condition should check for EOF or break on -1 properly; scanf returns 1 on success, but this loop will continue indefinitely if input ends without -1.
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