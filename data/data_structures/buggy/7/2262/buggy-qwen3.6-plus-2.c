#define _CRT_SECURE_NO_WARNINGS 1; // @@ The semicolon at the end of a #define directive is syntactically incorrect and can cause compilation errors or unexpected macro expansion.
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
        if (t->a == NULL && t->b == NULL) // @@ The current pre-order check does not guarantee left-to-right output order; an in-order traversal (recursively visit left, check/print leaf, recursively visit right) is required.
            printf("%d %d ", t->da,cnt); // @@ The output format requires each leaf node's value and height to be on a separate line, so a newline character '\n' should be used instead of a trailing space.
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