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
                j = 0; // @@ [Error: Resetting j to 0 causes an infinite loop when a match is found, as j will always be 0 and the loop continues indefinitely. Additionally, the logic does not correctly track the chain of segments; it should only move to the next segment once, not reset the inner loop.]
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
    if(max_times==1||max_times==8) // @@ [Error: Hardcoded conditions for output adjustment are incorrect and do not generalize to all test cases. The expected output should be max_times+1 (since times[i] counts connections, not total segments), but the arbitrary +2 for other cases is wrong.]
    {
        printf("%d %d %d\n",max_times+1, civ[max_index].a, civ[max_index].b);
    }
    else
    {
        printf("%d %d %d\n",max_times+2, civ[max_index].a, civ[max_index].b); // @@ [Error: Adding 2 to max_times is incorrect; the number of segments should be max_times+1 consistently, as the first segment is not counted in times[i].]
    }
    return 0;
}