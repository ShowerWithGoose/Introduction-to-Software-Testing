#include <stdio.h>
int an[11];
int flag[11];
int N;
void generrate(int i)
{
    if (i == N + 1)
    {
        for (int k = 0; k < N; k++)
        {
            printf("%d", an[k]); // @@ The output format is incorrect. Integers should be separated by a space, but here they are printed consecutively without spaces. It should be printf("%d ", an[k]); or similar logic to handle spacing correctly.
        }
        printf("\n");
    }
    else
    {
        for (int j = 1; j <= N; j++)
        {
            if (flag[j] == 0)
            {
                an[i - 1] = j;
                flag[j] = 1;
                generrate(i + 1);
                flag[j] = 0;
            }
        }
    }
}
int main()
{
    int index = 1;
    scanf("%d", &N);
    generrate(index);
    return 0;
}