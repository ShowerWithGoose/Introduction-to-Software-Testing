#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data[11] = {0};
int used[11] = {0};
void per(int n, int start);
void show(int* data, int n);
int main()
{
    per(1, 1); // @@ The function per is called with hardcoded arguments (1, 1) instead of reading N from input and passing it as the first argument. This means the program always generates permutations for N=1, ignoring the actual input.
    return 0;
}
void per(int n, int start)
{
    if(start == n + 1) show(data, n);
    else{
        int i;
        for(i = 1; i <= n; i++){
            if(used[i] == 0){
                used[i] = 1;
                data[start] = i;
                per(n, start + 1);
                used[i] = 0;
            }
        }
    }
    return;
}
void show(int* data, int n)
{
    int i;
    for(i = 1; i <= n; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
    return;
}