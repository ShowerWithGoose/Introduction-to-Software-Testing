#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [Using scanf inside push function causes incorrect input parsing; the value to push should be passed as argument, not read inside the function]
    if(j > 99){ // @@ [Condition should be j >= 100 or j == 100 since stack capacity is 100 and index goes from 0 to 99; also, j represents count or top index? Logic inconsistent]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [If j is current top index (0-based), next free slot is j+1, but initial i=0 implies first push goes to a[1], skipping a[0]; should be a[j] = news and then increment]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [Logic assumes j is count of elements, but in push, j starts at 0 and first element stored at a[1]; inconsistency leads to wrong empty check]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [If j is count, last element is at a[j-1], not a[j]; accessing out-of-bound or wrong index]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack size should be 100 to hold max 100 elements, not 99]
    int i = 0;
    while (scanf("%d", &sig)){
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i); // @@ [This handles sig == 0, but also any other non-1, non--1 value as pop, which violates spec; should only pop on 0]
        }
    }
    return 0;
}