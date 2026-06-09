#include <stdio.h>
//滚动数组 a b c
int main() {
    char a = 0, b, c;
    while ((b = getchar()) != EOF) {
        if (b != '-') {
            a = b;
            printf("%c", a);
        }else{
            c = getchar();
            if (('a'<=a&&c<='z' && a<c)||('A'<=a&&c<='Z' && a<c)||('0'<=a&&c<='9' && a<c)) {
                char i;
                for (i = a+1; i <= c; i++) {
                    printf("%c", i);
                }
            }else{
                printf("%c%c", b, c);
            }
            a = c;
        }
    }
    return 0;
}



