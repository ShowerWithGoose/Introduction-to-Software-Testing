#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ The trailing space in the format string causes scanf to wait for non-whitespace input, which can lead to incorrect reading or program hanging. It should be "%d".
    if(j > 99){
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ Since j represents the current number of elements (or the index of the next free slot), the new element should be placed at a[j], not a[j+1].
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ When j is the count of elements in the stack, the top element is located at index j-1. It should print a[j-1].
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ The problem specifies a maximum stack capacity of 100, so the array should be declared with size 100 to prevent out-of-bounds access.
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