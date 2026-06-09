#include <stdio.h>

int number[11];

void swap(int *a,int *b);

void digui(int k, int m)
{
    int i;
    if(k == m) {
        for(i = 0; i <= m; i++)
            printf("%d ", number[i]);
        printf("\n");
    }
    else
    {
        for(i = k; i <= m; i++)
        {
            for (int j = i-1; j >= k; j--)
                swap(&number[j], &number[j+1]);
            digui(k + 1, m);
            for (int j = k; j <= i-1; j++)
                swap(&number[j], &number[j+1]);
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
    for (int i = 0; i < n; i++) {
        number[i] = i + 1;
    }
    digui(0, n-1);

    return 0;
}

