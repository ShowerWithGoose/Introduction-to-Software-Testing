#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int data[11] = {0};
int used[11] = {0};
void per(int n, int start);
void show(int* data, int n);
int main()
{
    int n; // @@ The variable 'n' is not declared in main, and scanf is missing to read input.
    scanf("%d", &n); // @@ The program fails to read the input integer N.
    per(n, 1); // @@ The function 'per' is called with hardcoded arguments instead of using the input 'n'.
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