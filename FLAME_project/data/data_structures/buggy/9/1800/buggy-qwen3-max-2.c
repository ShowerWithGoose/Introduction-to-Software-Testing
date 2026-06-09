#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int n = 0, a[100][5] = { 0 },p=0;
    scanf("%d", &n);
    while (n--)
    {
        int a1=0, a2=0, b1=0, b2 = 0, i = 0;
        scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
        while (1)
        {
            if (!a[i][4])
            {
                a[i][0] = a1, a[i][1] = a2, a[i][2] = b1, a[i][3] = b2, a[i][4] = 1;
                p++;
                break;
            }
            else
            {
                if ((a[i][0] == b1) && (a[i][1] == b2))
                {
                    a[i][0] = a1, a[i][1] = a2;
                    a[i][4]++;
                    break;
                }
                else if ((a[i][2] == a1) && (a[i][3] == a2))
                {
                    a[i][2] = b1, a[i][3] = b2;
                    a[i][4]++;
                    break;
                }
                else
                {
                    i++;
                }
            }
        }
    }
    
    while (p--)
    {
        int g = p;
        while (g--)
        {
            if (!a[g][4])
                continue;
            if ((a[g][0] == a[p][2]) && (a[g][1] == a[p][3])) // @@ [The condition incorrectly compares a[g][0] with a[p][3] and a[g][1] with a[p][2]; it should compare a[g][0] with a[p][2] and a[g][1] with a[p][3] to check if the start of segment g matches the end of segment p. However, even this fix is insufficient because the merging logic does not correctly handle chaining in both directions and may merge segments multiple times or miss valid chains.]
            {
                a[g][0] = a[p][0], a[g][1] = a[p][1];
                a[g][4]+=a[p][4];
                a[p][4] = 0; // @@ [Missing: after merging segment p into g, segment p should be marked as used (e.g., a[p][4] = 0) to prevent reuse. Without this, the same segment might be merged multiple times, leading to incorrect counts.]
                break;
            }
            else if ((a[g][2] == a[p][0]) && (a[g][3] == a[p][1]))
            {
                a[g][2] = a[p][2], a[g][3] = a[p][3];
                a[g][4] += a[p][4];
                a[p][4] = 0; // @@ [Same issue: missing deactivation of merged segment p.]
                break;
            }
        }
    }
    int j=0, k=0, l = 0;
    while (a[j][4])
    {
        if (k > a[j][4]) // @@ [Logic error: this condition skips updating when a[j][4] is equal to or less than current max, but initialization of k=0 means first non-zero entry will always update. However, more critically, the loop stops at the first zero-length entry, which may not cover all stored segments if there are gaps (though unlikely due to insertion logic). The real issue is that due to incorrect merging and lack of deactivation, the counts are wrong.]
        {
            j++;
        }
        else
        {
            k = a[j][4];
            l = j;
            j++;
        }
    }
    printf("%d %d %d", k, a[l][0], a[l][1]);
    return 0; 
}