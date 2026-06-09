#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news);
    if(j > 99){
        printf("error ");
    }
    else{
        a[j + 1] = news;
    }
    return j + 1; // @@ [Error: When a push operation fails due to stack overflow, the function still returns j+1, incorrectly incrementing the stack pointer. Should return j instead to keep the stack state unchanged on error.]
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]);
    }
    return j - 1; // @@ [Error: When a pop operation is attempted on an empty stack (j=0), the function still returns j-1, which becomes -1, corrupting the stack pointer. Should return j (the current value) to leave the stack state unchanged on error.]
}
int main(){
    int sig;
    int stack[99];
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