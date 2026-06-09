#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 110

int main()
{
    char in_put[MAX];
    gets(in_put);
    int i = 0, j = 0;
    if (in_put[0] == '0') {
        for (i = 0; i < strlen(in_put); i++) {
            if (in_put[i] == '0')
                j--;
            else if (in_put[i] == '.')
                continue;
            else
                break;
        }
        printf("%c", in_put[i]);
        i++;
        if (strlen(in_put) + j - 1 != 1)
            printf(".");
        while (i < strlen(in_put)) {
            printf("%c", in_put[i]);
            i++;
        }
        printf("e%d", j);
    }
    else{
        for (i = 0; i < strlen(in_put) && in_put[i] != '.'; i++, j++)
            ;
        i = 0;
        printf("%c", in_put[i]);
        i++;
        while (i < strlen(in_put)) {
            if (i == 1)
                printf(".");
            if (in_put[i] == '.') {
                i++;
                continue;
            }
            printf("%c", in_put[i]);
            i++;
        }
        printf("e%d", j-1);
    }
    return 0;
}
