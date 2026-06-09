#define _CRT_SECURE_NO_WARNINGS 1;
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct stu {
    int da;
    struct stu* a, * b;
};
struct stu* root = NULL;
struct stu* insert(struct stu* p, int a) {
    if (p == NULL) {
        p = (struct stu*)malloc(sizeof(struct stu));
        p->da = a;
        p->a = p->b = NULL;
    }
    else if (a < p->da)
        p->a = insert(p->a, a);
    else if (a >= p->da)
        p->b = insert(p->b, a);
    return p;
}
void search(struct stu *t,int cnt) {
    if (t != NULL) {
        if (t->a == NULL && t->b == NULL)
            printf("%d %d ", t->da,cnt); // @@ The output format is incorrect: it prints a space after the second value instead of a newline, and does not print a newline after each leaf node. According to the expected output, each leaf node should be printed on a separate line with a space between value and height, followed by a newline.
        else {
            search(t->a,cnt+1);
            search(t->b,cnt+1);
        }
    }
}
int main()
{
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        root=insert(root, a);
    }
    search(root,1);
    return 0;
}