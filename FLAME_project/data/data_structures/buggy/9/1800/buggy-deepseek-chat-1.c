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
            if ((a[g][0] == a[p][3]) && (a[g][1] == a[p][2])) // @@ Error: The condition checks if the start of chain g matches the end of chain p, but the coordinates are compared incorrectly. It should check if a[g][0] == a[p][2] and a[g][1] == a[p][3] (i.e., the start of g equals the end of p), or the reverse. The current comparison uses a[g][0] with a[p][3] and a[g][1] with a[p][2], which mixes x and y coordinates incorrectly.
            {
                a[g][0] = a[p][0], a[g][1] = a[p][1];
                a[g][4]+=a[p][4];
                break;
            }
            else if ((a[g][2] == a[p][0]) && (a[g][3] == a[p][1])) // @@ Error: Similarly, this condition checks if the end of chain g matches the start of chain p, but uses a[g][2] with a[p][0] and a[g][3] with a[p][1], which is correct for x and y respectively. However, the logic is flawed because the first condition already incorrectly handles the matching, and the overall merging strategy does not correctly handle the ordering of segments (x-coordinates must be increasing). The algorithm fails to properly connect segments in the correct order.
            {
                a[g][2] = a[p][2], a[g][3] = a[p][3];
                a[g][4] += a[p][4];
                break;
            }
        }
    }
    int j=0, k=0, l = 0;
    while (a[j][4])
    {
        if (k > a[j][4])
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