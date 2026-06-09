#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [Using "scanf" inside push/pull breaks synchronization with main input loop; also, format string has trailing space which may cause issues]
    if(j > 99){ // @@ [Condition should be j >= 100 since stack capacity is 100 and index starts at 0]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [Should assign to a[j], not a[j+1]; current logic skips index 0 and writes out of intended bounds]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [Incorrect condition: j represents next available index, so top element is at j-1; but when j==0, stack is empty. However, this function is called with current j, so should check if j <= 0]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [Should print a[j-1], not a[j]; because top of stack is at index j-1 when j elements are in stack]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack size is 99, but problem states maximum capacity is 100; should be at least 100 or 101 to avoid overflow]
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