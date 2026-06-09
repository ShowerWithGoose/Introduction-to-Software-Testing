#include <stdio.h>
int an[11];
int flag[11];
int N;
void generrate(int i) // @@ [Function name is misspelled as 'generrate' instead of 'generate'; while not a compilation error by itself, it's inconsistent but acceptable. However, the real issue is missing space in output formatting.]
{
    if (i == N + 1)
    {
        for (int k = 0; k < N; k++)
        {
            printf("%d", an[k]); // @@ [Missing space after each number; output format requires space-separated integers, but this prints digits without spaces, causing incorrect output format.]
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