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
                j = 0; // @@ Error: Setting j=0 then continuing causes the loop's increment (j++) to execute next, making j=1 instead of 0. This skips the first element after a match, breaking chain counting.
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
    if(max_times==1||max_times==8) // @@ Error: Arbitrary condition based on hardcoded values; the chain length should be max_times+1 regardless, but the counting loop itself is flawed.
    {
        printf("%d %d %d\n",max_times+1, civ[max_index].a, civ[max_index].b); // @@ Error: Adding 1 is inconsistent and may produce wrong output for correct chains.
    }
    else
    {
        printf("%d %d %d\n",max_times+2, civ[max_index].a, civ[max_index].b); // @@ Error: Should be max_times+1, not +2.
    }
    return 0;
}