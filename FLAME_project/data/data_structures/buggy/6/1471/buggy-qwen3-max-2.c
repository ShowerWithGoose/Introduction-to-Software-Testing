#include <stdio.h>
int push(int a[], int j){
    int news;
    scanf("%d ", &news);
    if(j > 99){
        printf("error ");
    }
    else{
        a[j + 1] = news; // @@ [The element should be stored at index j, not j+1, because j represents the current top index (0-based count of elements). Storing at j+1 skips index 0 and causes misalignment.]
    }
    return j + 1;
}
int pull(int a[], int j){
    if(j - 1 < 0){
        printf("error ");
    }
    else{
        printf("%d ", a[j]); // @@ [When popping, the top element is at index j-1, not j, because j represents the number of elements (or next available index), so valid indices are 0 to j-1.]
    }
    return j - 1;
}
int main(){
    int sig;
    int stack[99]; // @@ [Stack size should be at least 100 to hold up to 100 elements, but this declares only 99 elements (indices 0-98), leading to potential out-of-bounds access when pushing 100 elements.]
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