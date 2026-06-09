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
    if(max_times==1||max_times==8) // @@ The logic for calculating the total number of segments in the continuous line is incorrect. The variable 'times[i]' counts the number of *subsequent* segments connected to segment 'i'. Therefore, the total length of the chain starting at 'i' is times[i] + 1. The conditional logic here is arbitrary and fails for general cases (like the test case where times[max_index] is 2, so total length is 3). It should simply be printf("%d %d %d\n", max_times + 1, ...).
    {
        printf("%d %d %d\n",max_times+1, civ[max_index].a, civ[max_index].b);
    }
    else
    {
        printf("%d %d %d\n",max_times+2, civ[max_index].a, civ[max_index].b); // @@ This branch is also part of the incorrect logic for determining the chain length. As explained above, the correct output count is always max_times + 1.
    }
    return 0;
}