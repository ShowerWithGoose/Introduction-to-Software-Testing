#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [The format string has an unnecessary trailing space which can cause input parsing issues; also, the function should not read input here—it should receive the value to push as an argument.]
    if(j > 99){ // @@ [Stack capacity is 100, so valid indices are 0–99; j represents the next available index, so condition should be j >= 100. Also, current logic uses j as count/index inconsistently.]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [If j is the current top index (0-based), then next free slot is a[j], not a[j+1]. This causes off-by-one error and skips a[0].]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [If j is the number of elements or next index, then top element is at j-1; but condition should check if stack is empty (j <= 0). Current logic may misinterpret empty state.]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [Should print a[j - 1] if j is the count/next index; printing a[j] accesses uninitialized or wrong element.]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack size should be 100 to hold up to 100 integers, not 99.]
    int i = 0;
    while (scanf("%d", &sig)){
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i); // @@ [This handles sig == 0, but also any other non-1, non--1 value as pop, which violates spec (only 0 is pop).]
        }
    }
    return 0;
}