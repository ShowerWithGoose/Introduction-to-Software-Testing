#include <stdio.h>

int num;
int now_data[13] = {0}, use_data[13] = {0};

void cal_data(int x);

int main()
{
    scanf("%d", &num);
    cal_data(1);
    return 0;
}

void cal_data(int x)
{
    int i = 1;
    if (x > num)
    {
        for (i = 1; i <= num; i++)
        {
            printf("%d ", now_data[i]);
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= num; i++)
    {
        if (use_data[i] == 0)
        {
            now_data[x] = i;
            use_data[i] = 1;
            cal_data(x + 1);
            use_data[i] = 0;
        }
    }
}
