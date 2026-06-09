#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news);
    if(j > 99){ @@ // The condition should be j >= 100 or j == 100 because stack capacity is 100 (indices 0-99). Also, the stack index logic is flawed: 'j' represents count of elements, so valid indices are 0 to j-1. Pushing at a[j] is correct, but checking j > 99 allows j=100 which writes to a[100] (out of bounds).
        printf("error ");
    }
    else{
        a[j + 1] = news; @@ // Should be a[j] = news; because 'j' is the current number of elements (next available index). Using j+1 skips index 0 and causes out-of-bounds when j=99 (writes to a[100]).
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ @@ // Condition should be j <= 0 because 'j' is the count of elements. If j==0, stack is empty. j-1<0 is equivalent to j<=0, but the logic for accessing element is wrong.
        printf("error ");
    }
    else{
        printf("%d ", a[j]); @@ // Should be a[j - 1] because the top element is at index j-1 when there are j elements. Accessing a[j] reads uninitialized memory or out-of-bounds.
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; @@ // Stack size should be 100 to hold max 100 elements (indices 0-99). Declaring as 99 limits capacity to 99, causing premature "error" on 100th push.
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