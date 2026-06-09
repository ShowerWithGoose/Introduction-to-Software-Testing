#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [The format string "%d " consumes trailing whitespace, which may interfere with subsequent input reads; also, the push logic uses 1-based indexing incorrectly]
    if(j > 99){ // @@ [Stack capacity is 100, valid indices are 0-99; condition should be j >= 100 or j == 100, but j represents count/top index incorrectly]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [Incorrect indexing: if j is the current top index (0-based), next element should be at a[j], not a[j+1]; this skips a[0] and writes beyond bounds when j=99]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [Logic error: j appears to represent the next available index (like 'top'), so current top element is at j-1; but condition checks j-1 < 0 instead of j <= 0]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [Should print a[j - 1] since top element is at index j-1 if j is the count/next index; printing a[j] accesses uninitialized or out-of-bound memory]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack size should be 100 to hold max 100 elements; declaring as 99 limits capacity to 99, causing premature "error" on 100th push]
    int i = 0;
    while (scanf("%d", &sig)){ // @@ [Loop condition does not handle EOF or input failure properly; though acceptable in many cases, it may cause infinite loop if input ends without -1]
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i); // @@ [This handles sig == 0, but also any other value (e.g., 2, -2); problem states only 1, 0, -1 are valid, but program doesn't validate]
        }
    }
    return 0;
}