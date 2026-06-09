#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[100];

void print(char[], int i) {
    int c = str[i + 1] - str[i - 1];
    for (int k = 1; k < c; k++) {
        printf("%c", str[i - 1] + k * ('1' - '0')); // @@ The calculation for the character increment is incorrect. It uses ('1' - '0') which equals 1, but logically it should just be k to iterate through ASCII values correctly (e.g., 'a' + 1 = 'b'). While mathematically 1*k is k, the intent is usually just +k. More importantly, this function fails to print the start and end characters if called in a context expecting full expansion, or relies on main to print them. However, looking at main, main prints str[i-1] before? No, main skips printing '-' but doesn't explicitly print the start char before calling print. Wait, in main: if str[i]=='-', it calls print. It does NOT print str[i-1]. So print must print from str[i-1] to str[i+1]. The loop starts at k=1, so it prints str[i-1]+1. It misses the first character str[i-1]. Also, the loop condition k < c means it stops before reaching str[i+1] (since c is the difference). If c=2 (e.g., a-c), k=1. Prints 'a'+1='b'. Misses 'a' and 'c'. The logic is fundamentally flawed for "expansion". It should likely print from start to end inclusive.
    }
}

int main() {

    gets(str);
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '-') {
            if (isupper(str[i - 1]) && isupper(str[i + 1])) {
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (islower(str[i - 1]) && islower(str[i + 1])) {
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else if (isdigit(str[i - 1]) && isdigit(str[i + 1])) {
                if (str[i - 1] < str[i + 1]) {
                    print(str, i);
                } else {
                    printf("-");
                }
            } else {
                printf("-");
            }
        } else {
            printf("%c", str[i]);
        }
    }
    return 0;
}