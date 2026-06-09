#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news);
    if(j > 99){ @@ The condition for stack full check is incorrect. The stack array size is 99 (indices 0-98), so max capacity is 99. If j represents the count of elements, valid indices are 0 to j-1. Pushing when j==99 means the next index would be 99, which is out of bounds for int stack[99]. Also, the problem states max capacity 100. The declaration int stack[99] only allows 99 elements. It should be at least 100. And the check should be if j >= 100 (if array size is >=100) or j >= 99 (if array size is 99). Given the problem says max capacity 100, the array should be size 100 or more, and check j >= 100. Here, array is size 99, so max index is 98. If j is the number of elements, next push goes to index j. So if j==99, index 99 is out of bounds. So check should be j >= 99. But problem says capacity 100. Let's assume array should be size 100. 
        printf("error ");
    }
    else{
        a[j + 1] = news; @@ Incorrect index calculation. If j is the current number of elements in the stack, the next element should be placed at index j (0-based indexing). Placing it at j+1 skips an index and will cause out-of-bounds access eventually. For example, if j=0 (empty), first element goes to a[1], leaving a[0] unused. This shifts all elements by 1.
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]); @@ Incorrect index for popping. If j is the number of elements, the top element is at index j-1. Accessing a[j] reads one position past the last valid element, which is uninitialized or garbage value.
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; @@ The stack size is 99, but the problem specifies a maximum capacity of 100. This array can only hold 99 integers, leading to potential out-of-bounds errors or inability to store 100 elements as required. It should be at least size 100.
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