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
            if ((a[g][0] == a[p][3]) && (a[g][1] == a[p][2])) // @@ [Error: Incorrect condition for connecting segments. Should check if a[g][2] equals a[p][0] and a[g][3] equals a[p][1] for forward connection, or a[g][0] equals a[p][2] and a[g][1] equals a[p][3] for backward connection. The current condition uses a[g][0] and a[g][1] (start point) compared to a[p][3] and a[p][2] (which are y2 and x2 of p), which is logically inconsistent with the problem's ordering requirement.]
            {
                a[g][0] = a[p][0], a[g][1] = a[p][1];
                a[g][4]+=a[p][4];
                break;
            }
            else if ((a[g][2] == a[p][0]) && (a[g][3] == a[p][1])) // @@ [Error: Incorrect condition for connecting segments. Should check if a[g][0] equals a[p][2] and a[g][1] equals a[p][3] for forward connection, or a[g][2] equals a[p][0] and a[g][3] equals a[p][1] for backward connection. The current condition uses a[g][2] and a[g][3] (end point) compared to a[p][0] and a[p][1] (start point of p), which is the reverse of what is needed for proper ordering.]
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