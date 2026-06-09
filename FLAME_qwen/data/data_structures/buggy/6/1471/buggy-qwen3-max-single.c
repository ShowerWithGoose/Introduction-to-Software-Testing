#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ [Using scanf inside push function causes double reading of input; input should be read in main and passed in]
    if(j > 99){ // @@ [Condition should be j >= 100 or j == 100 since stack size is 100 (indices 0-99); also, j represents count, so max allowed before push is 99]
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [Incorrect indexing: should assign to a[j], not a[j+1]; j is current count/top index after last element]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ [Incorrect condition: j is the count of elements, so if j == 0, stack is empty; should check j <= 0]
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [Incorrect indexing: if j is count, top element is at a[j-1], not a[j]]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack size should be 100 to hold up to 100 elements, not 99]
    int i = 0;
    while (scanf("%d", &sig)){
        if (sig == -1) break;
        if (sig == 1){
            i = push(stack, i);
        }
        else{
            i = pull(stack, i); // @@ [This handles both pop (sig==0) and invalid operations; but problem says only 1, 0, -1 are valid, so else assumes sig==0, which is okay, but logic inside pull is flawed]
        }
    }
    return 0;
}