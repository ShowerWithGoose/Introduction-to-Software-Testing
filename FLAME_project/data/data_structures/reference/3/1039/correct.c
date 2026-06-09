#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char in[105];
    int i, num, loc = 0;

    scanf("%s", in);
    int len = strlen(in);
    while (in[loc] != '.')
        loc++;

    if (loc > 1) {  //整数部分≥10
        printf("%c.", in[0]);
        for (i = 1; i < len; i++) {
            if (i == loc)
                continue;
            else
                printf("%c", in[i]);
        }
        printf("e%d", loc - 1);
    }

    else if (loc == 1) {
        if (in[0] == '0') {  //整数部分=0
            for (i = 2, num = -1; in[i] == '0'; i++, num--)
                ;
            if (i + 1 == len)
                printf("%c", in[i]);
            else {
                printf("%c.", in[i]);
                for (i++; i < len; i++)
                    printf("%c", in[i]);
            }
            printf("e%d", num);
        }

        else {
            for (i = 0; i < len; i++) {
                printf("%c", in[i]);
            }
            printf("e0");
        }
    }

    return 0;
}



