#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data[11] = {0};
int used[11] = {0};
void per(int n, int start);
void show(int* data, int n);
int main()
{
    int n; // @@ The variable 'n' is not declared in main, but it is needed to read input and pass to the permutation function.
    scanf("%d", &n); // @@ The program fails to read the input integer N.
    per(n, 1); // @@ The function 'per' is called with hardcoded arguments (1, 1) instead of using the input N. It should be per(n, 1).
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