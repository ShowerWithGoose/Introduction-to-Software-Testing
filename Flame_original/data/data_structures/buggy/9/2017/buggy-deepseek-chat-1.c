#include <stdio.h>
#include <string.h>

struct S {
    int a;
    int b;
};

struct S civ[101];
struct S div[101];

int main() {
    int times[101] = {0};
    int n = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &civ[i].a, &civ[i].b, &div[i].a, &div[i].b);
    }

    for (int i = 0; i < n; i++) {
        int p = i;
        for (int j = 0; j < n; j++) {
            int q = j;
            if (civ[q].a == div[p].a && civ[q].b == div[p].b) {
                times[i]++;
                p = q;
                j = 0;
                continue;
            }
        }
    }


    int max_times = 0;
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        if (times[i] > max_times) {
            max_times = times[i];
            max_index = i;
        }
    }
    if(max_times==1||max_times==8)
    {
        printf("%d %d %d\n",max_times+1, civ[max_index].a, civ[max_index].b); // @@ Error: The logic for computing the number of segments is incorrect. The program adds arbitrary constants (1 or 2) to max_times instead of correctly counting the number of segments in the continuous line. Additionally, the starting point may be incorrect because the algorithm does not properly track the chain of connected segments.
    }
    else
    {
        printf("%d %d %d\n",max_times+2, civ[max_index].a, civ[max_index].b); // @@ Error: Same as above - incorrect computation of segment count and starting point. The algorithm fails to correctly identify the longest continuous line segment as described in the problem.
    }
    return 0;
}