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
            if ((a[g][0] == a[p][3]) && (a[g][1] == a[p][2])) // @@ [Logical error: Coordinates are swapped. Compares x-start of g with y-end of p, and y-start of g with x-end of p. Should be a[p][2] and a[p][3].]
            {
                a[g][0] = a[p][0], a[g][1] = a[p][1];
                a[g][4]+=a[p][4]; // @@ [Logical error: After merging chain p into g, a[p][4] should be set to 0 to prevent it from being counted again or considered as a separate chain.]
                break;
            }
            else if ((a[g][2] == a[p][0]) && (a[g][3] == a[p][1]))
            {
                a[g][2] = a[p][2], a[g][3] = a[p][3];
                a[g][4] += a[p][4]; // @@ [Logical error: Similarly, a[p][4] should be set to 0 here to mark chain p as merged and prevent double counting.]
                break;
            }
        }
    }
    int j=0, k=0, l = 0;
    while (a[j][4]) // @@ [Potential out-of-bounds access: If all chains are valid, j may exceed array bounds. Should include a bound check like j < p or j < 100.]
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