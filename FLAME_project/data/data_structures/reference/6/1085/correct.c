#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define check(VAR, CONV) printf("check:" #VAR "=%" #CONV "\n", VAR)
typedef long long ll;
typedef double db;
int main(void)
{
    int op, val, ptr = 0, flag = 0;
    int vals[114];
    //
    while (scanf("%d", &op))
    {
        switch (op)
        {
        case 1:
            scanf("%d", &val);
            if (ptr == 100)
                printf("error ");
            else
            {
                vals[ptr] = val;
                ptr++;
            }
            break;
        case 0:
            if (ptr)
            {
                ptr--;
                printf("%d ", vals[ptr]);
            }
            else
                printf("error ");
            break;
        case -1:
            flag = 1;
            break;
        }
        if (flag)
            break;
    }
    return 0;
}
