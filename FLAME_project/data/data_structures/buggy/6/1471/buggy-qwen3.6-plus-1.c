#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news);
    if(j > 99){ @@ The condition for stack full check is incorrect. The stack array size is 99 (indices 0-98), so max capacity is 99. If j represents the count of elements, valid indices are 0 to j-1. Pushing when j==99 means the next index is 99, which is out of bounds for int stack[99]. Also, the problem states max capacity is 100. The array declaration int stack[99] only allows 99 elements. It should be at least 100. And the check should be if j >= 100 (if array was size 100+) or j >= 99 here. But primarily, the array size is too small for the problem requirement of 100.
        printf("error ");
    }
    else{
        a[j + 1] = news; @@ Incorrect index calculation. If j is the number of elements currently in the stack, the next element should be placed at index j, not j+1. For example, if stack is empty (j=0), first element goes to a[0]. Here it goes to a[1], leaving a[0] unused/garbage. This shifts all elements by one index.
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ @@ The condition checks if j < 1. If j is the count of elements, j=0 means empty. So j-1 < 0 is equivalent to j < 1. This part is logically okay for checking emptiness if j is count. However, combined with the push error, j might not represent what we think.
        printf("error ");
    }
    else{
        printf("%d ", a[j]); @@ Incorrect index for popping. If j is the count of elements, the top element is at index j-1. Here it accesses a[j], which is out of bounds for the current logical stack size (valid indices 0 to j-1). Due to the push error storing at j+1, this might accidentally access the right memory location if push stored at j+1 and we read at j? No. Push stored at j+1. If j was 0, push stored at 1. j becomes 1. Pull accesses a[1]. That matches. But if j was 1, push stores at 2. j becomes 2. Pull accesses a[2]. That matches. So the indexing is consistently off by one relative to standard 0-based stack implementation, BUT the main issue is the array bounds. If we push 100 items, j goes from 0 to 100. The last push stores at a[100]. int stack[99] has indices 0..98. Accessing a[100] is buffer overflow.
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; @@ The stack array size is 99, but the problem requires a maximum capacity of 100. This will cause buffer overflow when pushing 100 elements. It should be at least 100, e.g., int stack[100] or int stack[105].
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