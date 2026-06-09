#include <stdio.h>
#include <string.h>

int main () {
    int a1, a2, a3;
    char b1, b2, b3;
    scanf("%d %c", &a1, &b1);
    while (b1 == '*' || b2 == '/') { // @@ Error: b2 is uninitialized at this point; should be b1 == '/' instead of b2 == '/'
        scanf("%d %c", &a3, &b3);
        if (b1 == '*')
            a1 *= a3;
        else
            a1 /= a3;
        b1 = b3;
    }
    while (b1 == '+' || b1 == '-') {
        scanf("%d %c", &a2, &b2);
        while (b2 == '*' || b2 == '/') {
            scanf("%d %c", &a3, &b3);
            if (b2 == '*')
                a2 *= a3;
            else
                a2 /= a3;
            b2 = b3;
        }
        if (b1 == '+')
            a1 += a2;
        else if (b1 == '-')
            a1 -= a2;
        b1 = b2;
    }
    printf("%d", a1);
    return 0;
}