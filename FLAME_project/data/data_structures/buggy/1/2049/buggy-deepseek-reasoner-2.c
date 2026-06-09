#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data[11] = {0};
int used[11] = {0};
void per(int n, int start);
void show(int* data, int n);
int main()
{
    per(1, 1); // @@ [The program does not read the input N; it hardcodes N=1, so for N=2 it only generates permutations for N=1. It should read N using scanf and then call per(N,1).]
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