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
    int sum = 0, innersum = 0, inner = 0;
    int num;
    char opr, outeropr = '+', lastopr;
    //
    while (scanf(" %d %c", &num, &opr) == 2)
    {
        if (inner == 0)
            innersum = num;
        else if (inner == 1)
        {
            if (lastopr == '*')
                innersum *= num;
            if (lastopr == '/')
                innersum /= num;
        }
        if (opr == '+' || opr == '-' || opr == '=')
        {
            inner = 0;
            if (outeropr == '+')
                sum += innersum;
            else if (outeropr == '-')
                sum -= innersum;
            outeropr = opr;
        }
        else if (opr == '*' || opr == '/')
            inner = 1;
        lastopr = opr;
        if (opr == '=')
            break;
    }
    printf("%d", sum);
    return 0;
}


