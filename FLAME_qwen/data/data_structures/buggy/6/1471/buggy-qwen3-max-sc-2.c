#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [The format string "%d " consumes trailing whitespace, which may interfere with subsequent input reads; also, input validation for the pushed value (not being 1, 0, or -1) is missing per problem description]
    if(j > 99){ // @@ [Stack capacity is 100, so valid indices are 0-99; condition should be j >= 100 or j == 100, not j > 99. Also, j represents current count, so max allowed before push is 100, but here it allows j=100 to pass]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [Incorrect indexing: if j is the current number of elements (or top index + 1), then new element should go at a[j], not a[j+1]. This causes off-by-one error and skips a[0]]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [If j is the count of elements, then stack is empty when j == 0; condition should be j <= 0. Also, accessing a[j] below assumes j is the next available index, but logic is inconsistent with push]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [Should print a[j - 1] if j is the count of elements; current code accesses one past the top or incorrect location due to indexing mismatch]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack size should be 100 to hold up to 100 integers, but only 99 elements allocated (indices 0-98)]
    int i = 0;
    while (scanf("%d", &sig)){
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i); // @@ [This handles sig == 0, but also any other non-1, non--1 value as pop, which violates spec (only 0 is pop)]
        }
    }
    return 0;
}