#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [The format string has an unnecessary trailing space which can cause input parsing issues, especially when next input is read immediately. Also, the function should not read input here—it should receive the value to push as a parameter, like in the reference program.]
    if(j > 99){ // @@ [Stack index j represents current top index or count? Condition should be j >= 100 for full stack (capacity 100), but array size is only 99 (see main), so this logic is inconsistent and incorrect.]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [If j is the current count of elements (0-based count), then the next available index is j, not j+1. This writes beyond intended position and skips index 0. Also, array size is 99, so max valid index is 98, but code may write to a[99] or beyond.]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [If j is the number of elements, then top element is at index j-1. But condition should check if j <= 0 (empty stack). However, due to incorrect push logic, j may not represent actual element count correctly.]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [Should print a[j - 1] if j is the count of elements. Currently prints one past the top or uninitialized memory.]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack capacity should be 100 as per problem, but array is only size 99, leading to potential overflow or under-allocation.]
    int i = 0;
    while (scanf("%d", &sig)){
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i); // @@ [This handles both pop (sig == 0) and any other non-1, non--1 input as pop, which is wrong. Only sig == 0 should trigger pop. For example, if input is 2, it will incorrectly call pull().]
        }
    }
    return 0;
}