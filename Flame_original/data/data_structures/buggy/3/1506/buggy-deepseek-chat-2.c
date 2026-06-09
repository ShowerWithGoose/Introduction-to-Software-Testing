#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX 100
 

int main(void) {
    char num[MAX] = { '\0' };
    gets(num); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow and is not standard C. Use fgets() instead.]
    int cnt = 0;
    if (num[0] == '0') {
        int i = 1;
        while (num[++i] == '0') // @@ [This loop increments i before checking, which skips the first character after the decimal point. It also does not check for the decimal point '.' character, so it may incorrectly count zeros before the decimal point.]
            ++cnt;
        ++cnt; // @@ [This increments cnt by 1, but the logic for counting the exponent is incorrect. The exponent should be the number of zeros after the decimal point before the first non-zero digit, not including the decimal point itself.]
        if(i == strlen(num) - 1) // @@ [This condition checks if i is at the last character, but i may have been incremented past the end of the string due to the while loop, causing undefined behavior or incorrect comparison.]
            printf("%ce-%d", num[i], cnt);
        else {
            printf("%c.", num[i]); // @@ [num[i] may be out of bounds or not the first non-zero digit due to incorrect loop logic.]
            for (; i < strlen(num); i++) { // @@ [The loop condition uses strlen(num) which is inefficient and may change if num is modified; also, i may be out of bounds.]
                printf("%c", num[i]);
            }
            printf("e-%d", cnt);
        }

        
    }
    else {
        int i = 1;
        while (num[i++] != '.') // @@ [This loop increments i after checking, so it counts characters including the decimal point, leading to an incorrect exponent value.]
            ++cnt;
        if (cnt == 0) { // @@ [cnt is incremented for each character before the decimal point, but the condition cnt==0 only handles the case where there is no decimal point, which is not possible for valid input.]
            printf("%s", num);
            printf("e%d", cnt);
        }
        else {
            printf("%c.", num[0]);
            for (i = 1; i < strlen(num); i++) { // @@ [The loop includes the decimal point in the output, which should be excluded. Also, the exponent calculation is off by one.]
                if (num[i] != '.')
                    printf("%c", num[i]);
            }
            printf("e%d", cnt); // @@ [The exponent cnt is incorrect because it includes the decimal point in the count.]
        }
    }
    
    return 0;
}