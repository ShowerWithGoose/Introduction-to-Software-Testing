#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news);
    if(j > 99){ // @@ Condition wrong: should be `j >= 99` because array size is 99 (indices 0..98) and push uses index j+1; j=98 is full.
        printf("error ");
    }
    else{
        a[j + 1] = news;
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){ // @@ Empty check wrong: should be `j < 0` since j is the top index; when j=0, stack has one element, but condition treats it as empty.
        printf("error ");
    }
    else{
        printf("%d ", a[j]);
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ Array size should be 100 to hold up to 100 elements (indices 0..99); size 99 causes overflow.
    int i = 0; // @@ Initial top index should be -1 (empty stack), not 0.
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