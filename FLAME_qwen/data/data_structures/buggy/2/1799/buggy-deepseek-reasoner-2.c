#include<stdio.h>
#include<string.h>
int num[10005];
char cal[10005];
char s[50005];
char s1[50005];
int flag1 = 1;
int main() {
    scanf("%s",s); // @@ scanf("%s") stops at spaces, failing to read the entire expression if it contains spaces. Use fgets or gets to read the whole line.
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            s1[j++] = s[i];
        }

    }
    int len = strlen(s1); // @@ s1 is not null-terminated after the loop, so strlen(s1) may read garbage beyond the assigned characters, causing undefined behavior. Add s1[j] = '\0'; before this line.
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
        if (flag1 == 1) {
            *p2 = s1[i];
            flag1 = 0;
            i++;
        } else {
            if ((s1[i] == '*' || s1[i] == '/') && (*p2 == '+' || *p2 == '-') ) {
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
    printf("%d", *(p1 - 1));
    return 0;
}