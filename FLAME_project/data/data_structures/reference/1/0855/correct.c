#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void DFS(int a[], int b[], int n, int temp);
int a[1000], b[1000];
int main()
{
    int num;
    scanf("%d", &num);
    DFS(a, b, num, 1);
    return 0;
}
void DFS(int a[], int b[], int num, int temp)
{
    int i;
    if (temp == num + 1)
    {
        for (i = 1; i <= num; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= num; i++)
    {
        if (b[i] == 0)
        {
            b[i] = 1;
            a[temp] = i;
            DFS(a, b, num, temp + 1);
            b[i] = 0;
        }
    }
}



