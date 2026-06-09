#include <stdio.h>

int number[11];

void swap(int *a,int *b);

void digui(int A, int B)
{
    int i;
    if(A == B) {
        for(i = 0; i <= B; i++)
            printf("%d ", number[i]);
        printf("\n");
    }
    else
    {
        for(i = A; i <= B; i++)
        {
            for (int j = i-1; j >= A; j--)
                swap(&number[j], &number[j+1]);
            digui(A + 1, B);
            for (int j = A; j <= i-1; j++)
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

