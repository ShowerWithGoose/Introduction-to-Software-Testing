#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[105], a[105];

int dot(char s[]) { //返回小数点位置，从0开始
    int i = 0;
    while (s[i] != '.') i++;
    return i;
}

int notzero(char s[]) {
    int i = 0;
    while (s[i] == '0' || s[i] == '.') i++;
    return i;
}

int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    scanf("%s", s);
    int len = strlen(s) - 1;
    int dotPos = (dot(s));
    if (dotPos == 1) { //"x.xx"
        if (s[0] == '0') { //"0.xx"
            int n = notzero(s);
            int b = dotPos - n; //e后面的数字
            if (n == len) { //"0.02"
                printf("%ce%d", s[len], b);
            } else { //"0.023"
                printf("%c.", s[n]);
                for (int i = n + 1; i <= len; i++) printf("%c", s[i]);
                printf("e%d", b);
            }
        } else { //"2.34"
            printf("%se0", s);
        }
    } else { //"23.45"
        int b = dotPos - 1;
        printf("%c.",s[0]);
        for (int i = 1; i <= len; i++) {
            if (i == dotPos) continue;
            else printf("%c", s[i]);
        }
        printf("e%d",dotPos-1);
    }
    return 0;
}
