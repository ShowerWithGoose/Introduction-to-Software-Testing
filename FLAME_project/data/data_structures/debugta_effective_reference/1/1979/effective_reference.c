#include <stdio.h>

int a[11];

void swap(int *a,int *b);

void digui(int i, int n)
{
    int k;
    if(i == n) {
        for(k = 0; k <= n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }
    else
    {
        for(k = i; k <= n; k++)
        {
            for (int j = k-1; j >= i; j--)
                swap(&a[j], &a[j+1]);
            digui(i + 1, n);
            for (int j = i; j <= k-1; j++)
                swap(&a[j], &a[j+1]);
        }
    }
}


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int k = 0; k < n; k++) {
        a[k] = k + 1;
    }
    digui(0, n-1);

    return 0;
}

