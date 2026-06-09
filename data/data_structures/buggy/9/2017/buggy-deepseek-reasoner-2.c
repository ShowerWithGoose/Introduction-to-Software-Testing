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
                j = 0; // @@ This reset does not re‑scan from index 0 because the for‑loop increment will make j start at 1 in the next iteration. As a result, a valid next segment at index 0 may be missed. Should set j = -1 to restart properly.
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
    if(max_times==1||max_times==8) // @@ The condition is arbitrary and does not correctly map times to segment count. The correct number of segments is max_times+1 (since times counts connections after the first segment).
    {
        printf("%d %d %d\n",max_times+1, civ[max_index].a, civ[max_index].b); // @@ The segment count should be max_times+1 always; the conditional +1 or +2 is incorrect.
    }
    else
    {
        printf("%d %d %d\n",max_times+2, civ[max_index].a, civ[max_index].b); // @@ Same reason: the added constant should be +1, not +2.
    }
    return 0;
}