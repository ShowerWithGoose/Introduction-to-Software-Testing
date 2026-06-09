#include <stdio.h>

int main()
{

    char ch;
    int digits, digits_current, digits_start, digits_end;
    int met_valid, met_decpnt, need_decpnt;

    scanf(" ");
    digits_current = 0;
    met_valid = 0; met_decpnt = 0; need_decpnt = 0;
    while (~scanf("%c", &ch)) {
        if (ch == '.') {
            digits_end = digits_current;
            met_decpnt = 1;
        } else if (ch >= '0' && ch <= '9') {
            if (met_valid) {
                if (need_decpnt)
                {
                    printf(".");
                    need_decpnt = 0;
                }
                printf("%c", ch);
            } else if (ch != '0') {
                met_valid = 1;
                digits_start = digits_current;
                printf("%c", ch);
                need_decpnt = 1;
            }
        } else {
            if (!met_decpnt) {
                digits_end = digits_current;
            }
            break;
        }
        digits_current++;
    }
    if (digits_end < digits_start) {
        printf("e%d", digits_end - digits_start);
    } else {
        printf("e%d", digits_end - digits_start - 1);
    }

    return 0;
}

