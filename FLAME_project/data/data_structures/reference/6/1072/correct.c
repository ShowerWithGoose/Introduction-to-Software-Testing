#include <stdio.h>   //不用我多说了
#include <math.h>    //数学公式
#include <stdlib.h>  //快排和malloc
#include <ctype.h>   //字符处理函数
#include <string.h>  //字符串函数
#include <time.h>    //找时间
#define ll long long //纯粹是为了快~
#define eps 1e-6     //别被浮点数相等判断卡掉
#define MAX 1000005  //看好数据范围，多开5个空间
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define NumberOf(a) (sizeof(a) / sizeof(a[0]))
#define MAXN 10
#define MAXK 1e7
#define swap(x, y)          \
    {                       \
        typeof(x) temp = x; \
        x = y;              \
        y = temp;           \
    }
clock_t start, stop;
int main()
{
    int s[105];
    int top = -1, i;
    int num, op;
    scanf("%d", &op);
    while (op != -1)
    {
        if (op == 1)
        {
            // printf("%d", top);
            if (top >= 100)
                printf("error ");
            else
            {
                scanf("%d", &num);
                s[++top] = num;
            }
        }
        if (op == 0)
        {
            if (top < 0)
                printf("error ");
            else
                printf("%d ", s[top--]);
        }
        scanf("%d", &op);
    }
    return 0;
}
/*
1 3 1 5 1 7 0 0 1 8 0 1 12 1 13 0 0 0 0 1 90 1 89 0 -1
*/

