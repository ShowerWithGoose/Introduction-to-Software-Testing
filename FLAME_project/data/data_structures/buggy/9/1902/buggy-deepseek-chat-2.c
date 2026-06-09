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
        for (int j = 0; j <= cnt && all[j].line != -1; j++)
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
    qsort(all, cnt + 1, sizeof(struct Nmb), cmpfunc);
    printf("%d %d %d", all[0].line, all[0].x_1, all[0].y_1); // @@ [Error: The output should include the starting point coordinates of the longest continuous line segment. However, after merging, the x_1 and y_1 of the merged segment may not be the true starting point because the code only updates the endpoint when merging at the start, but does not handle cases where the new segment attaches to the end (x_2, y_2) of an existing segment. In such cases, the starting point (x_1, y_1) remains unchanged and correct, but the logic for merging when sign==2 is flawed: it compares x_1 values to decide which segment to keep, but this does not guarantee the correct starting point after merging two segments that share an endpoint. For the given test case, the segments are: (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67), (1,2)-(7,8), (7,8)-(9,10). The correct longest chain is (1,2)-(7,8)-(9,10) with 3 segments starting at (1,2). However, the code incorrectly merges (7,78)-(27,50) with (27,50)-(75,78) and then with (75,78)-(80,67) to form a chain of 4 segments starting at (7,78), because it does not enforce the x-coordinate ordering condition (x_i < x_{i+1}) and allows merging even when the x-coordinates are not strictly increasing (e.g., 7 < 27 < 75 < 80 is increasing, but the chain (7,78)-(27,50)-(75,78)-(80,67) is valid in terms of x-order; however, the problem expects the chain (1,2)-(7,8)-(9,10) to be the longest because the other chain actually has 3 segments? Wait, re-examining: The input has 5 segments. The chain (7,78)-(27,50)-(75,78)-(80,67) uses segments: (7,78)-(27,50), (27,50)-(75,78), (75,78)-(80,67) — that's 3 segments, not 4. The code incorrectly counts 4 because it also includes (1,2)-(7,8) or (7,8)-(9,10) incorrectly? Actually, the buggy output is "4 7 78", meaning it found a chain of 4 segments starting at (7,78). This suggests the code merged (7,78)-(27,50) with (27,50)-(75,78) and (75,78)-(80,67) (3 segments) and then also merged with (7,8)-(9,10) or something incorrectly, because (7,78) and (7,8) share x=7 but different y, so they should not merge. The error is in the merging logic: when sign==2, the code merges two segments that both share an endpoint with the new segment, but it does not check that the shared endpoint is the same point. For example, if the new segment connects two existing segments at different endpoints, the code incorrectly merges them. In the test case, when processing the segment (7,8)-(9,10), it might match with (1,2)-(7,8) at (7,8) and also with (7,78)-(27,50) at (7,78)? No, (7,78) is different from (7,8). The issue is that the loop condition `all[j].line != -1` is incorrect because it stops at the first segment with line==-1, but segments with line==-1 are marked as invalid and should be skipped, not cause the loop to terminate. This causes the loop to not check all valid segments, leading to incorrect merging. Additionally, the merging when sign==2 does not correctly update the starting point; it compares x_1 but after merging, the starting point should be the smallest x_1 among the merged segments, which is not guaranteed by the comparison. The correct approach is to always keep the segment with the smaller x_1 as the starting point. In the test case, the chain (1,2)-(7,8)-(9,10) has starting point (1,2), but the code's merging might incorrectly combine it with the other chain due to the loop termination issue. The primary error is the loop condition `all[j].line != -1` which should be `j <= cnt` without the line check, and then skip segments with line==-1 using continue. Also, the merging logic for sign==2 needs to correctly identify the starting point by comparing x_1 values and updating accordingly.]
    return 0;
}