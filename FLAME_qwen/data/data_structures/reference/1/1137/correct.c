

#include <stdio.h>
#include<string.h>
#define MAXSIZE 10
void swap2(int o[], int n, int i)
{
    int temp = o[i];
    for (int j = i; j > n; j--)
    {
        o[j] = o[j - 1];
    }
    o[n] = temp;
}
void swap3(int o[], int n, int i)
{
    int temp = o[n];
    for (int j = n; j < i; j++)
    {
        o[j] = o[j + 1];
    }
    o[i] = temp;
}
void print(int o[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", o[i]);
    printf("\n");
}
void backtrack(int o[], int n, int len)
{
    if (n == len)
    {
        print(o , len);
        return;
    }
    for (int i = n; i < len; i++)
    {
        swap2(o, n, i);
        backtrack(o, n + 1, len);
        swap3(o, n, i);
    }
}
void permute(int arr[], int N)
{
    backtrack(arr, 0, N);
}

int main(int argc, char *argv[])
{
    int N;
    scanf("%d", &N);
    int arr[MAXSIZE];
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;
    permute(arr, N);
}
