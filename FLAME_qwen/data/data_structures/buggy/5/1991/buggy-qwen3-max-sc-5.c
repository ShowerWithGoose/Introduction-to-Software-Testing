#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node node;
typedef struct node *nptr;

int read() {
    int tem;
    scanf("%d ", &tem);
    return tem;
}

struct node {
    int a;
    int x;
    nptr next;
};

nptr head;

nptr new_node() { return (nptr) malloc(sizeof(node)); } // 为新的节点开辟空间 @@
// 申请一个值域为 x 的新节点
nptr getnode(int a, int x) {
    nptr p = new_node();
    p->a = a;
    p->x = x;
    p->next = NULL;
    return p;
}

nptr f1[10005], f2[10005];

void insert(int x, int y) {
    if (head == NULL)
        head = getnode(x, y);
} // @@ [The insert function only handles the case when head is NULL. It does not insert new terms into an existing list or handle merging of like terms properly.]

int main() {
    char *in = (char *) malloc(10005 * sizeof(char));
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in); // @@ [gets() is unsafe and deprecated; more critically, it may not be available in some environments, leading to compilation errors. Also, 'in' might be NULL if malloc fails, but no check is done.]
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f1[num_a]->a = num; // @@ [f1[num_a] is an uninitialized pointer. Accessing ->a on an uninitialized pointer leads to undefined behavior and likely segmentation fault. Same for f2 below.]
        f1[num_a++]->x = num2;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }
    gets(in); // @@ [Same issue as above: unsafe use of gets(), and potential NULL pointer dereference if malloc failed.]
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f2[num_b]->a = num; // @@ [f2[num_b] is also uninitialized; this causes undefined behavior.]
        f2[num_b++]->x = num2;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ [insert() doesn't actually build a proper polynomial; it only sets head once. Subsequent calls do nothing. Also, f1[i] and f2[j] are invalid due to earlier uninitialized pointers.]
            if(i + j == 0)
                continue;
            nptr p = head;
            int temp = f1[i]->x + f2[j]->x;
            while (p != NULL) {
                nptr q = getnode(f1[i]->a * f2[j]->a, temp);
                if (p->x == temp) {
                    p->a += f1[i]->a * f2[j]->a;
                    break;
                } else if (p->x != temp) {
                    if (p->next != NULL) {
                        if ((p->x) > temp && ((p->next)->x) < temp) {
                            q->next = p->next;
                            p->next = q;
                            break;
                        }
                    }
                    else if ((p->x) > temp && p->next == NULL) {
                        q->next = p->next;
                        p->next = q;
                        break;
                    }
                }
            }
        }
    }
    nptr s = head;
    while (s != NULL) {

       printf("%d %d ", s->a, s->x);
        s = s->next;
    }
    return 0;
}