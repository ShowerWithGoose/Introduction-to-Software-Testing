#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
 

int main(void) {
    char num[MAX] = { '\0' };
    gets(num); // @@ gets is removed in the C11 standard and causes a compilation error in modern compilers; fgets should be used instead.
    int cnt = 0;
    if (num[0] == '0') {
        int i = 1;
        while (num[++i] == '0')
            ++cnt;
        ++cnt;
        if(i == strlen(num) - 1)
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]);
            for (; i < strlen(num); i++) {
                printf("%c", num[i]);
            }
            printf("e-%d", cnt);
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