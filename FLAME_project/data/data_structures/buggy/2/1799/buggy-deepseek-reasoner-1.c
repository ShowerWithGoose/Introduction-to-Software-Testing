#include<stdio.h>
#include<string.h>
int num[10005];
char cal[10005];
char s[50005];
char s1[50005];
int flag1 = 1;
int main() {
    scanf("%s",s); // @@ 使用scanf("%s")不能读取包含空格的字符串，只能读取到第一个空格前，导致表达式不完整，只读取了"10"。应使用gets(s)或fgets()。
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