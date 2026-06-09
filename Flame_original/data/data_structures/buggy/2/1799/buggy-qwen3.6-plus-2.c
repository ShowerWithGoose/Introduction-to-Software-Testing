#include<stdio.h>
#include<string.h>
int num[10005];
char cal[10005];
char s[50005];
char s1[50005];
int flag1 = 1;
int main() {
    scanf("%s",s); // @@ scanf with %s stops reading at the first whitespace, but the problem states the expression may contain spaces. Should use gets(s) or fgets().
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            s1[j++] = s[i];
        }

    }
    int len = strlen(s1);
    int *p1 = num;
    char*p2 = cal;
    for (int i = 0; i < len; ) {
        int k = 0;


        if (s1[i] <= '9' && s1[i] >= '0') {
            while (s1[i] <= '9' && s1[i] >= '0') {
                k = k * 10 + s1[i] - '0';
                i++;
            }
            *p1 = k;
            p1++;
        }
        if (flag1 == 1) { // @@ Logic error: flag1 is only used for the first operator. The code fails to properly manage operator storage for subsequent operations, leading to incorrect parsing.
            *p2 = s1[i];
            flag1 = 0;
            i++;
        } else {
            if ((s1[i] == '*' || s1[i] == '/') && (*p2 == '+' || *p2 == '-') ) { // @@ Precedence handling is flawed. When the else branch executes, it evaluates the previous operator but never stores the current operator s1[i] into *p2 or increments i, causing infinite loops or skipped operations.
                p2++;
                *p2 = s1[i];
                i++;

            } else {
                if (*p2 == '+') { // @@ Out-of-bounds risk: *(p1-2) may access invalid memory. Also, after evaluation, the current operator s1[i] is not stored and i is not incremented, breaking the parsing flow.
                    *(p1 - 2) = *(p1 - 2) + *(p1 - 1);
                    p1--;
                    if (p2 == cal) {
                        flag1 = 1;
                    } else
                        p2--;
                }
                if (*p2 == '-') { // @@ Same issue: fails to store the current operator and increment i after evaluation, causing logical errors and potential infinite loops.
                    *(p1 - 2) = *(p1 - 2) - *(p1 - 1);
                    p1--;
                    if (p2 == cal) {
                        flag1 = 1;
                    } else
                        p2--;
                }
                if (*p2 == '*') { // @@ Same issue: evaluation logic does not properly handle the current operator s1[i], leading to incorrect results or program hangs.
                    *(p1 - 2) = *(p1 - 2) * (*(p1 - 1)) ;
                    p1--;
                    if (p2 == cal) {
                        flag1 = 1;
                    } else
                        p2--;
                }
                if (*p2 == '/') { // @@ Same issue: missing assignment of s1[i] to *p2 and i++ after evaluation breaks the parsing sequence and causes incorrect calculations.
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
    printf("%d", *(p1 - 1)); // @@ May output incorrect result or garbage due to flawed parsing/evaluation logic that doesn't correctly reduce the expression to a single value.
    return 0;
}