#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#define ll long long
int Arrange[1000]; //储存全排列信息
int Isused[1000];  // Isused[i]用来记录数组i是否已经在Arrange[]里，即是否已经使用了

int n;

void A(int Position)
{
    if (Position == 1 + n)
    {
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", Arrange[i]);
        }
        puts("");
    }
    for (int i = 1; i <= n; i++) // n == 10     A10
    {
        if (Isused[i] == 0)
        {
            Isused[i] = 1;
            Arrange[Position] = i;
            A(Position + 1);
            Isused[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    A(1); //给第一个地方安排

    return 0;
}


