#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
 

int main(void) {
    char num[MAX] = { '\0' };
    gets(num);
    int cnt = 0;
    if (num[0] == '0') {
        int i = 1;
        while (num[++i] == '0') @@ // The loop starts by incrementing i to 2 before checking num[2], skipping num[1] which is '.' in inputs like "0.000...", causing incorrect digit counting.
            ++cnt;
        ++cnt; @@ // This overcounts the exponent because the initial skip of the decimal point and first zero(s) is mishandled.
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]);
            for (; i < strlen(num); i++) { @@ // This loop prints from the first non-zero digit onward, but includes the current digit twice: once in "%c." and again as the first iteration of the loop.
                printf("%c", num[i]);
            }
            printf("e-%d", cnt);
        }

        
    }
    else {
        int i = 1;
        while (num[i++] != '.') @@ // This loop increments i after checking, so when '.' is found, i points one past it. But cnt counts the digits before '.', which is correct only if logic aligns; however, for numbers like "123.45", this gives cnt=3, which is correct, but the later printing may be okay. However, this part isn't triggered in the failing test case.
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