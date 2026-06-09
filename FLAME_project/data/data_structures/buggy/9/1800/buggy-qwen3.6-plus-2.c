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
                if ((a[i][0] == b1) && (a[i][1] == b2)) // @@ The condition checks if the new segment's end (b1, b2) matches the existing segment's start (a[i][0], a[i][1]). If so, it prepends the new segment. However, it updates a[i][0] and a[i][1] to the new start (a1, a2), which is correct for prepending. But the logic fails to handle the case where the new segment connects to the END of the existing segment correctly in all scenarios, specifically when merging chains. More critically, the subsequent merging loop is flawed.
                {
                    a[i][0] = a1, a[i][1] = a2;
                    a[i][4]++;
                    break;
                }
                else if ((a[i][2] == a1) && (a[i][3] == a2)) // @@ This condition checks if the new segment's start (a1, a2) matches the existing segment's end (a[i][2], a[i][3]). If so, it appends the new segment. It updates a[i][2] and a[i][3] to the new end (b1, b2). This logic is locally correct for simple appending but interacts poorly with the global merging strategy.
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
    
    while (p--) // @@ The variable p is used as an index here, but p was incremented for each segment added. After the first loop, p equals the total number of segments. The loop decrements p, so it iterates from n-1 down to 0. However, the array 'a' might have gaps or the indices might not correspond to valid active segments if segments were merged into earlier indices. More importantly, the inner loop logic is incorrect for finding the longest chain because it only performs one pass of merging and doesn't propagate changes correctly across all segments. It assumes that merging p into g is sufficient, but g itself might need to be merged into another segment later. This greedy one-pass merge fails to construct the full continuous line.
    {
        int g = p;
        while (g--)
        {
            if (!a[g][4])
                continue;
            if ((a[g][0] == a[p][3]) && (a[g][1] == a[p][2])) // @@ This condition checks if segment g's start matches segment p's end. If so, it merges p into g by updating g's start to p's start. This is logically reversed or incomplete. If g starts where p ends, the combined segment starts at p's start and ends at g's end. The code updates a[g][0] and a[g][1] to a[p][0] and a[p][1], which is correct for the new start. However, it does NOT update a[g][2] and a[g][3] (the end coordinates), which should remain a[g][2] and a[g][3]. Wait, if g starts where p ends, the new segment is p->g. Start is p.start, End is g.end. The code updates g's start to p's start. It leaves g's end as is. This seems correct for this specific direction. BUT, it adds the counts: a[g][4]+=a[p][4]. And then breaks. This means p is effectively merged into g. But p is not marked as inactive. In the next iterations, p might still be considered or other segments might try to merge with p. Also, the loop structure `while(p--)` processes segments in reverse order of insertion, which doesn't guarantee topological order for merging chains.
            {
                a[g][0] = a[p][0], a[g][1] = a[p][1];
                a[g][4]+=a[p][4];
                break;
            }
            else if ((a[g][2] == a[p][0]) && (a[g][3] == a[p][1])) // @@ This condition checks if segment g's end matches segment p's start. If so, it merges p into g by updating g's end to p's end. The combined segment is g->p. Start is g.start, End is p.end. The code updates a[g][2] and a[g][3] to a[p][2] and a[p][3]. This is correct for the new end. It adds counts. Again, p is not marked inactive.
            {
                a[g][2] = a[p][2], a[g][3] = a[p][3];
                a[g][4] += a[p][4];
                break;
            }
        }
    }
    int j=0, k=0, l = 0;
    while (a[j][4]) // @@ This loop assumes that active segments are contiguous from index 0 upwards. However, due to the merging logic, some segments might have been merged into others but their count a[j][4] was not zeroed out, or the indices are not compacted. Specifically, when a segment p is merged into g, a[p][4] remains non-zero. This means the final search for the maximum will consider invalid/merged segments as potential candidates, leading to incorrect results. The segments that were merged into others should have their count set to 0 or be otherwise marked as inactive.
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