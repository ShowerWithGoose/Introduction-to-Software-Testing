#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ The space after %d may cause input parsing issues; it expects a space after the number, which can skip or misread subsequent input.
    if(j > 99){
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ The element should be stored at index j, not j+1, because j is the current top index (number of elements). This causes the stack to be off by one.
    }
    return j + 1; // @@ Returning j+1 always increments the index even if the push failed due to stack full, which corrupts the stack state.
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ Should print a[j-1] because j is the number of elements (top index + 1), not the index of the top element.
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ Stack size is 99, but problem says maximum capacity is 100. Should be stack[100] or stack[105] to handle up to 100 elements.
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