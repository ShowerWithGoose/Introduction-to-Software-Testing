#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [The format string has an unnecessary trailing space which can cause input parsing issues, especially when next input is read immediately. Also, the function should not read input here—it should receive the value to push as an argument.]
    if(j > 99){ // @@ [Stack index j represents current top index or count? Condition should be j >= 100 for full stack (max capacity 100), but array size is only 99 (see main). Also, logic of indexing is inconsistent.]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [If j is the current count of elements (0-based count), then valid indices are 0 to j-1. Pushing at j+1 skips index j and may write beyond allocated array if j=98 -> index 99, but array is size 99 (indices 0-98).]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [If j is the number of elements, then top element is at index j-1. But condition checks j-1 < 0 → j < 1, which is correct for empty stack. However, in push, we stored at j+1, so indexing logic is inconsistent.]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [Should print a[j - 1] if j is count of elements. But due to incorrect push storing at j+1, this accesses wrong/uninitialized memory.]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack capacity should be 100 as per problem, but array is only size 99 → max 99 elements, violating spec. Also, indexing errors compound this.]
    int i = 0;
    while (scanf("%d", &sig)){
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i); // @@ [This handles sig == 0, but also any other non-1, non--1 value (e.g., 2, 3...) as pop, which violates input spec. Should only treat 0 as pop.]
        }
    }
    return 0;
}