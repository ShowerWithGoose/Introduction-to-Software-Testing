#include <stdio.h>
#include <stdlib.h>

int num[20], n;
int cnt = 1;

void my_swap(int* t, int* h)
{
    int tmp = *t;
    *t = *h;
    *h = tmp;
}

void print_num()
{
    for(int i = 0; i < n; i++)
        printf("%d ", num[i]);
    printf("\n");
}

int main()
{
#ifdef VSCODE
    freopen("1.data.in", "r", stdin);
#endif
    scanf("%d", &n);
    int tmp;
    for(int i = 0; i < n; i++)
    {
        num[i] = i + 1;
        cnt *= i + 1;
    }
    print_num();
    for(int i = 1; i < cnt; i++)
    {
        int j = n - 2;
        while(num[j] > num[j+1]) j--;
        int k = j + 1;
        while(num[j] < num[k]) k++;
        k--;
        // my_swap(&num[j], &num[k]);
        tmp = num[j];
        num[j] = num[k];
        num[k] = tmp;
        for(int p = j + 1, q = n - 1; p < q; p++, q--)
        {
            // my_swap(&num[p], &num[q]);
            tmp = num[p];
            num[p] = num[q];
            num[q] = tmp;
        }
        print_num();
    }
    return 0;
}
