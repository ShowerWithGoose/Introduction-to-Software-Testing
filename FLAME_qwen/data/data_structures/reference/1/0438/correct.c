#include<stdio.h>
#include<stdlib.h>
int use[15];
int isUse(int num)
{
    return use[num] == 1;
}

int save[15];
void fun(int now, int n)
{
    if (now > n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", save[i]);
        }
        putchar('\n');
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isUse(i))
        {
            use[i] = 1;
            save[now-1] = i;
            fun(now+1, n);
            use[i] = 0;
            save[now-1] = 0;
        }
    }
}

void start(int n)
{
    fun(1, n);
}



int main()
{
    int n;
    scanf("%d", &n);
    start(n);

    // system("pause");
    return 0;
}
