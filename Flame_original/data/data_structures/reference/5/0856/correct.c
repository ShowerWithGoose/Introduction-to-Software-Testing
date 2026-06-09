#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mul {
    int a;
    int n;
    struct mul *next;
};
struct mul *first1 = NULL, *first2 = NULL, *first3 = NULL, *p1, *p2, *p3, *q,
           *r, *r0;

int n1, n2;

void getNum(char temp[], int *a, int *b) {
    int i, j;
    sscanf(temp, "%d %d", &i, &j);
    *a = i;
    *b = j;
}

void getMul() {
    int i, j, k, l, flag = 0;
    char m[10000], temp[100];
    gets(m);
    for (i = 0; m[i] != '\0'; i += j) {
        flag = 0;
        for (j = 0; flag < 2; j++) {
            temp[j] = m[i + j];
            if (m[i + j] == ' ' || m[i + j] == '\0') flag++;
        }
        getNum(temp, &k, &l);
        q = (struct mul *)malloc(sizeof(struct mul));
        q->a = k;
        q->n = l;
        q->next = NULL;
        if (first1 == NULL)
            first1 = p1 = q;
        else {
            p1->next = q;
            p1 = p1->next;
        }
    }
    memset(m, 0, sizeof(m));
    gets(m);
    for (i = 0; m[i] != '\0'; i += j) {
        flag = 0;
        for (j = 0; flag < 2; j++) {
            temp[j] = m[i + j];
            if (m[i + j] == ' ' || m[i + j] == '\0') flag++;
        }
        getNum(temp, &k, &l);
        q = (struct mul *)malloc(sizeof(struct mul));
        q->a = k;
        q->n = l;
        q->next = NULL;
        if (first2 == NULL)
            first2 = p2 = q;
        else {
            p2->next = q;
            p2 = p2->next;
        }
    }
    return;
}

void count() {
    int a, n, flag = 0;
    for (p1 = first1; p1 != NULL; p1 = p1->next)
        for (p2 = first2; p2 != NULL; p2 = p2->next) {
            a = p1->a * p2->a;
            n = p1->n + p2->n;
            for (r = first3; r != NULL; r = r->next) {
                if (n == r->n) {
                    r->a += a;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                q = (struct mul *)malloc(sizeof(struct mul));
                q->a = a;
                q->n = n;
                q->next = NULL;
                if (first3 == NULL) {
                    first3 = p3 = q;
                } else {
                    for (r = first3; r != NULL; r0 = r, r = r->next) {
                        if (q->n > r->n) {
                            if (r == first3) {
                                q->next = first3;
                                first3 = q;
                                break;
                            } else {
                                q->next = r;
                                r0->next = q;
                                break;
                            }
                        }
                    }
                    if (r == NULL) r0->next = q;
                }
            }
            flag = 0;
        }
    return;
}

int main() {
    getMul();
    count();
    for (p3 = first3; p3 != NULL; p3 = p3->next) printf("%d %d ", p3->a, p3->n);
    return 0;
}
