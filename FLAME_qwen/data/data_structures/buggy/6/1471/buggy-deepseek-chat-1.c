#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ The format string includes a trailing space, which may cause issues with input parsing. It should be "%d" without the space.
    if(j > 99){
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ The element should be stored at index j, not j+1, because j is the current top index (number of elements). This causes the stack to skip index 0 and misalign.
    }
    return j + 1; // @@ The return value should be j+1 only when a push is successful, but it always returns j+1 even if the stack is full (error case), incorrectly updating the top index.
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ The element to pop should be at index j-1 (the top element), not j, because j is the number of elements (next free index). This prints an uninitialized or wrong value.
    }
    return j - 1; // @@ The return value should be j-1 only when a pop is successful, but it always returns j-1 even if the stack is empty (error case), incorrectly updating the top index.
}
int main(){
    int sig;
    int stack[99]; // @@ The stack size is 99, but the problem specifies a maximum capacity of 100. It should be int stack[100]; to match the requirement.
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