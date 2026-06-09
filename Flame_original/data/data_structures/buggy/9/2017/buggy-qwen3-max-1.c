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
                j = 0; // @@ [Resetting loop variable j inside the loop causes infinite loop or incorrect traversal; it breaks normal iteration logic and may reprocess already checked segments repeatedly]
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
        printf("%d %d %d\n",max_times+1, civ[max_index].a, civ[max_index].b); // @@ [Arbitrary condition "max_times==8" has no basis in problem logic; output adjustment (adding 1 or 2) is incorrect—should directly output max_times + 1 since times[i] counts connections, not segments]
    }
    else
    {
        printf("%d %d %d\n",max_times+2, civ[max_index].a, civ[max_index].b); // @@ [Same as above: adding 2 is unjustified; the count of segments in chain starting at i is times[i] + 1, not times[i] + 2]
    }
    return 0;
}