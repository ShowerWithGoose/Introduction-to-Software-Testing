#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define pi acos(-1.0)
#define eps 1e-8
#define MOD 100000007
#define N 1000010
#define ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))
typedef long long ll;
typedef double D;
// int a[N];
struct Nmb
{
    int x_1;
    int y_1;
    int x_2;
    int y_2;
    int line;
};
struct Nmb all[105];
int cmpfunc(const void *a, const void *b)
{
    // return (*(int *)a - *(int *)b);
    struct Nmb *c = (struct Nmb *)a;
    struct Nmb *d = (struct Nmb *)b;
    if (c->line < d->line)
        return 1;
    if (c->line > d->line)
        return -1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a1, b1, a2, b2, cnt = 0;
    scanf("%d%d%d%d", &all[0].x_1, &all[0].y_1, &all[0].x_2, &all[0].y_2);
    all[0].line = 1;
    for (int i = 0; i < n - 1; i++)
    {
        int sign = 0, num_j[2] = {}, k = 0;
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        for (int j = 0; j <= cnt && all[j].line != -1; j++) // @@ The loop condition `all[j].line != -1` may skip valid segments that have been marked as -1 but are still needed for linking; also, the loop should iterate over all segments up to `cnt`, but the condition may cause early termination if a -1 segment is encountered.
        {
            if (a1 == all[j].x_1 && b1 == all[j].y_1)
            {
                all[j].x_1 = a2;
                all[j].y_1 = b2;
                all[j].line++;
                sign++;
                num_j[k] = j;
                k++;
            }
            else if (a1 == all[j].x_2 && b1 == all[j].y_2)
            {
                all[j].x_2 = a2;
                all[j].y_2 = b2;
                all[j].line++;
                sign++;
                num_j[k] = j;
                k++;
            }
            else if (a2 == all[j].x_1 && b2 == all[j].y_1)
            {
                all[j].x_1 = a1;
                all[j].y_1 = b1;
                all[j].line++;
                sign++;
                num_j[k] = j;
                k++;
            }
            else if (a2 == all[j].x_2 && b2 == all[j].y_2)
            {
                all[j].x_2 = a1;
                all[j].y_2 = b1;
                all[j].line++;
                sign++;
                num_j[k] = j;
                k++;
            }
            else
            {
            }
        }
        if (sign == 0)
        {
            cnt++;
            all[cnt].x_1 = a1, all[cnt].x_2 = a2, all[cnt].y_1 = b1, all[cnt].y_2 = b2;
            all[cnt].line = 1;
        }
        if (sign == 2)
        {
            if (all[num_j[0]].x_1 < all[num_j[1]].x_1)
            {
                all[num_j[0]].line+=all[num_j[1]].line;
                all[num_j[1]].line=-1;
            }
            else
            {
                all[num_j[1]].line+=all[num_j[0]].line;
                all[num_j[0]].line=-1;
            }
            
        }
    }
    qsort(all, cnt + 1, sizeof(struct Nmb), cmpfunc); // @@ The qsort sorts only up to index `cnt`, but segments marked as -1 (invalid) are still included in the sort, which may cause incorrect ordering; also, the starting point coordinates may be incorrect after merging because the algorithm does not properly track the original starting point of the continuous line.
    printf("%d %d %d", all[0].line, all[0].x_1, all[0].y_1);

    return 0;
}