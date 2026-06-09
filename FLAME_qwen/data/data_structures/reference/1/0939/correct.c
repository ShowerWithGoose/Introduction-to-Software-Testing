#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
void Permutation(int m, int n, int arr[], int temp[]);
int main()
{
    int arr[15], temp[15], n;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
        temp[i] = 0;
    Permutation(0, n, arr, temp);
    return 0;
}
void Permutation(int m, int n, int arr[], int temp[])
{
    int i;
    if(m >= n)
    {
        for (i = 0; i < n-1; i++)
            printf("%d ", arr[i]);
        printf("%d\n", arr[i]);
    }
    else
    {
        for(i = 0; i < n; i++)
        {
            if (temp[i] == 0)
            {
                temp[i] = 1;
                arr[m] = i + 1;
                Permutation(m + 1, n, arr, temp);
                temp[i] = 0;
            }
        }
    }
}




