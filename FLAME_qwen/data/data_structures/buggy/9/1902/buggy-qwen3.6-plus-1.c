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
        int sign = 0, num_j[2] = {}, k = 0; // @@ Non-standard empty brace initialization for array; causes compilation error in standard C (C89/C99/C11). Use {0} instead.
        scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
        for (int j = 0; j <= cnt && all[j].line != -1; j++)
        {
            if (a1 == all[j].x_1 && b1 == all[j].y_1)
            {
                all[j].x_1 = a2; // @@ Overwrites x1 without ensuring it remains the starting point (smaller x), violating the problem's increasing x-coordinate constraint.
                all[j].y_1 = b2;
                all[j].line++;
                sign++;
                num_j[k] = j;
                k++;
            }
            else if (a1 == all[j].x_2 && b1 == all[j].y_2)
            {
                all[j].x_2 = a2; // @@ Overwrites x2 without maintaining the x1 < x2 invariant or correctly tracking the chain's endpoint.
                all[j].y_2 = b2;
                all[j].line++;
                sign++;
                num_j[k] = j;
                k++;
            }
            else if (a2 == all[j].x_1 && b2 == all[j].y_1)
            {
                all[j].x_1 = a1; // @@ Same issue: updates coordinate without verifying it is the correct start/end point relative to x-order.
                all[j].y_1 = b1;
                all[j].line++;
                sign++;
                num_j[k] = j;
                k++;
            }
            else if (a2 == all[j].x_2 && b2 == all[j].y_2)
            {
                all[j].x_2 = a1; // @@ Same issue: updates coordinate without verifying it is the correct start/end point relative to x-order.
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
            if (all[num_j[0]].x_1 < all[num_j[1]].x_1) // @@ x1 may not represent the true starting point due to previous unvalidated updates; also fails to update the merged chain's endpoints.
            {
                all[num_j[0]].line+=all[num_j[1]].line; // @@ Merges segment counts but does not update the chain's start and end coordinates to form the correct continuous segment.
                all[num_j[1]].line=-1; // @@ Invalidates the chain but leaves its coordinates intact, potentially causing incorrect sorting or output.
            }
            else
            {
                all[num_j[1]].line+=all[num_j[0]].line; // @@ Same issue: merges counts without updating endpoints to reflect the new continuous line.
                all[num_j[0]].line=-1; // @@ Same issue: invalidates chain without clearing or adjusting coordinates.
            }
            
        }
    }
    qsort(all, cnt + 1, sizeof(struct Nmb), cmpfunc);
    printf("%d %d %d", all[0].line, all[0].x_1, all[0].y_1);

    return 0;
}