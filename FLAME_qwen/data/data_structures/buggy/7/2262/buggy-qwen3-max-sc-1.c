#define _CRT_SECURE_NO_WARNINGS 1; @@ [The semicolon after the #define is invalid and causes a compilation error. Preprocessor directives should not end with a semicolon.]
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
            printf("%d %d ", t->da,cnt); @@ [The output format requires each leaf node on a separate line, but this prints space-separated values on the same line. Also, height tracking is incorrect because cnt is incremented for both children regardless of traversal path.]
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