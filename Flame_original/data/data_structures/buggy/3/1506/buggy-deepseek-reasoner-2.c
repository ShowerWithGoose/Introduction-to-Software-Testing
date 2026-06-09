#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
 

int main(void) {
    char num[MAX] = { '\0' };
    gets(num); // @@ Compilation error: 'gets' is unsafe and removed from C11 standard; use scanf instead.
    int cnt = 0;
    if (num[0] == '0') {
        int i = 1;
        while (num[++i] == '0') // @@ Logical error: loop does not count leading zeros; cnt should be incremented inside loop.
            ++cnt; // @@ Logical error: increments cnt once, but should count number of leading zeros.
        ++cnt; // @@ Logical error: this extra increment is incorrect; exponent should be i-1.
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt); // @@ Logical error: exponent should be i-1, not cnt.
        else {
            printf("%c.", num[i]);
            for (; i < strlen(num); i++) { // @@ Logical error: loop should start at i+1 to avoid duplicating the first digit.
                printf("%c", num[i]);
            }
            printf("e-%d", cnt); // @@ Logical error: exponent should be i-1, not cnt.
        }

        
    }
    else {
        int i = 1;
        while (num[i++] != '.')
            ++cnt;
        if (cnt == 0) {
            printf("%s", num);
            printf("e%d", cnt);
        }
        else {
            printf("%c.", num[0]);
            for (i = 1; i < strlen(num); i++) {
                if (num[i] != '.')
                    printf("%c", num[i]);
            }
            printf("e%d", cnt);
        }
    }
    
    return 0;
}