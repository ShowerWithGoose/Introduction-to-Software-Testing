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
        printf("%d %d %d\n",max_times+1, civ[max_index].a, civ[max_index].b);
    }
    else
    {
        printf("%d %d %d\n",max_times+2, civ[max_index].a, civ[max_index].b); // @@ [The logic for computing the number of segments is incorrect. The count `times[i]` already represents the number of connections made from segment i, so the total number of segments in the chain should be `times[i] + 1`, not `times[i] + 1` or `times[i] + 2` based on arbitrary conditions like `max_times==1||max_times==8`. This hardcoded condition leads to wrong output for general cases.]
    }
    return 0;
}