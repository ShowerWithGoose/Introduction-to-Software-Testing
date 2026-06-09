#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ Error: trailing space in format string may cause extra input consumption; should be "%d".
    if(j > 99){ // @@ Error: condition should be j >= 99 because full when j equals array capacity (99). Current condition allows j=99, leading to out-of-bounds access.
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ Error: should store at a[j] (0-indexed) or adjust logic; storing at j+1 wastes index 0 and misaligns top pointer.
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]);
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ Error: array size should be 100 to match maximum capacity of 100 elements; currently only supports up to 98 elements due to 1-indexed storage.
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