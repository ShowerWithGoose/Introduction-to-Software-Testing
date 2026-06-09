#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int n, i, j, input[15], output[15];
int fun()
{
    input[0] = 1;
    int i;
    for (i = 1; i < 10; i++)
        input[i] = i * input[i - 1];
}
void quchong(int secret[])
{
    int j, k, b,cp;
    for (int i = 0; secret[i]; i++)
    {
        for (j = k = i + 1; secret[j]; j++)
        {
            if (secret[j] != secret[i])
                secret[k++] = secret[j];
        }
    } //ШЅжи
}
void print()
{
    int i = 0;
    for (i = 0; i < n - 1; i++)
        printf("%d ", output[i]);
    printf("%d\n", output[i]);
}

void find()
{
    for (i = n - 2; i >= 0; i--)
        if (output[i] < output[i + 1])
            break;
    int a = i, b = i + 1, temp;
    for (i = a + 1; i <= n - 1; i++)
        if (output[i] > output[a] && output[i] < output[b])
            b = i;
    temp = output[a];
    output[a] = output[b];
    output[b] = temp;
    for (i = n - 1, j = a + 1; i > j; i--, j++)
    {
        temp = output[i];
        output[i] = output[j];
        output[j] = temp;
    }
}

int main()
{
    fun();
    scanf("%d", &n);
    int i;
    for (i = 0; i <= n - 1; i++)
        output[i] = i + 1;
    quchong(output);
    for (i = 1; i < input[n]; i++)
        print(), find();
    print();
    return 0;
}


