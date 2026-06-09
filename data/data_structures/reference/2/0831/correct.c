#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8

int mult(char *a) {
    char tmp[1000], stay[1000];
    int len = strlen(a);
    int mul = 0;
    int k = 0;
    int s[1000] = {0};
    int cou=0;

    strcpy(stay, a);
    for (int i = 0; i < len; i++) {
        if (a[i] == '*' || a[i] == '/') {
            int lent = strlen(tmp);
            for (int j = 0; j < lent; ++j) tmp[j] = '\0';
            strncpy(tmp, a, i);
            a = &a[i + 1];
            len = len - i;
            i = -1;
            for (int j = 0; j < 1; ++j) {
                s[k] = atoi(tmp);
                k++;
            }
            cou++;
            continue;
        }

        else if (strlen(a) == 1)
            s[k] = atoi(a);
    }
    if(cou==0)
    s[0]= atoi(stay);
    s[k]= atoi(a);
    k = 1;
    len = strlen(stay);
    mul = s[0];
    for (int i = 0; i < len; ++i) {
        if (stay[i] == '*') {
            mul = mul * s[k];
            k++;
        }
        if (stay[i] == '/') {
            mul = mul / s[k];
            k++;
        }
    }
    return mul;
}

int main() {
    char in[1000], tmp[1000], tmp2[1000], stay[1000];
    int sum = 0;
    int len = 0;
    int s[1000] = {0};
    int m = 0;
    char *p = in;

    gets(in);
    len = strlen(in);
    for (int i = 0; i < len; ++i) {
        if (in[i] == ' ') {
            int lent = strlen(tmp);
            for (int j = 0; j < lent; ++j) tmp[j] = '\0';
            strcpy(tmp, in + i + 1);
            in[i] = '\0';
            strcat(in, tmp);
            if (in[i] == ' ') i--;
        }
    }
    strcpy(stay, in);
    len = strlen(in);
    for (int i = 0; i < len; ++i) {
        if ((p[i] == '+' || p[i] == '-') || (p[i] == '=')) {
            int lent = strlen(tmp);
            for (int j = 0; j < lent; ++j) tmp[j] = '\0';
            strncpy(tmp, p, i);
            s[m] = mult(tmp);
            m++;
            p = &p[i + 1];
            len -= i;
            i = -1;
        }
    }
    len = strlen(stay);
    sum = s[0];
    int l = 1;
    for (int i = 0; i < len; ++i) {
        if (stay[i] == '+') {
            sum += s[l];
            l++;
        }
        if (stay[i] == '-') {
            sum -= s[l];
            l++;
        }
    }
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (stay[i] == '+' || stay[i] == '-' || stay[i] == '*' || stay[i] == '/')
            count++;
    }
    if (count == 0) {
        stay[len - 1] = '\0';
        printf("%s", stay);
        return 0;
    }
    printf("%d", sum);
    return 0;
}




