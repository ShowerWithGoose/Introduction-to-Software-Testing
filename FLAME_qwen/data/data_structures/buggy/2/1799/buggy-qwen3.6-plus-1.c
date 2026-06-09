#include<stdio.h>
#include<string.h>
int num[10005];
char cal[10005];
char s[50005];
char s1[50005];
int flag1 = 1;
int main() {
    scanf("%s",s); // @@ scanf with %s stops reading at whitespace, but the problem states the expression may contain spaces. Use gets(s) or fgets() instead.
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            s1[j++] = s[i];
        }

    }
    int len = strlen(s1);
    int *p1 = num;
    char*p2 = cal;
    for (int i = 0; i < len; ) { // @@ The loop processes the entire string including '=', which is not an operator to be evaluated. It should stop at '=' or ignore it.
        int k = 0;


        if (s1[i] <= '9' && s1[i] >= '0') {
            while (s1[i] <= '9' && s1[i] >= '0') {
                k = k * 10 + s1[i] - '0';
                i++;
            }
            *p1 = k;
            p1++;
        }
        if (flag1 == 1) { // @@ The operator handling logic is fundamentally flawed. It incorrectly manages precedence and evaluation order, causing wrong results for mixed operators.
            *p2 = s1[i];
            flag1 = 0;
            i++;
        } else {
            if ((s1[i] == '*' || s1[i] == '/') && (*p2 == '+' || *p2 == '-') ) { // @@ This precedence check is incorrect. It pushes '*' or '/' without evaluating the pending '+' or '-', violating operator precedence rules.
                p2++;
                *p2 = s1[i];
                i++;

            } else {
                if (*p2 == '+') {
                    *(p1 - 2) = *(p1 - 2) + *(p1 - 1);
                    p1--;
                    if (p2 == cal) {
                        flag1 = 1;
                    } else
                        p2--;
                }
                if (*p2 == '-') {
                    *(p1 - 2) = *(p1 - 2) - *(p1 - 1);
                    p1--;
                    if (p2 == cal) {
                        flag1 = 1;
                    } else
                        p2--;
                }
                if (*p2 == '*') {
                    *(p1 - 2) = *(p1 - 2) * (*(p1 - 1)) ;
                    p1--;
                    if (p2 == cal) {
                        flag1 = 1;
                    } else
                        p2--;
                }
                if (*p2 == '/') {
                    *(p1 - 2) = *(p1 - 2) / *(p1 - 1);
                    p1--;
                    if (p2 == cal) {
                        flag1 = 1;
                    } else
                        p2--;
                }

            }
        }
    }
    printf("%d", *(p1 - 1)); // @@ Due to incorrect pointer manipulation during evaluation, p1 may not point to the correct final result. The result is typically stored in num[0].
    return 0;
}