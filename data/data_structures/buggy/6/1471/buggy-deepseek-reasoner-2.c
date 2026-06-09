#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news); // @@ trailing space in format string may cause unexpected waiting for whitespace; should be "%d"
    if(j > 99){ // @@ condition allows j==99 to proceed, but array size is only 99, leading to out-of-bounds access when j+1 is used; should check j >= 100 (or adjust array size)
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ index j+1 can exceed array bounds (e.g., j=99 gives index 100, but array size is 99); also array is 1-indexed but insufficient size
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
    int stack[99]; // @@ array size insufficient for capacity 100 with 1-based indexing; should be at least stack[101] (indices 1-100) or stack[100] with 0-based indexing
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