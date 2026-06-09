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

nptr new_node() { return (nptr) malloc(sizeof(node)); } // 为新的节点开辟空间
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
} // @@ [This function only handles the case when head is NULL. It does not handle insertion or merging for existing terms with same exponent, nor does it maintain sorted order.]

int main() {
    char *in = (char *) malloc(10005 * sizeof(char));
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in); // @@ [Using gets() is unsafe and may cause buffer overflow; also, in is allocated but f1/f2 elements are never initialized to point to valid nodes before dereferencing.]
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f1[num_a]->a = num; // @@ [f1[num_a] is an uninitialized pointer; writing to ->a causes undefined behavior (likely segmentation fault).]
        f1[num_a++]->x = num2; // @@ [Same as above: f1[num_a] was never allocated memory via getnode() or malloc().]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }
    gets(in); // @@ [Same issue: reusing 'in' without ensuring safety; also, second polynomial parsing has same pointer initialization bug.]
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f2[num_b]->a = num; // @@ [f2[num_b] is uninitialized; dereferencing leads to runtime error.]
        f2[num_b++]->x = num2; // @@ [Same: f2[num_b] not allocated.]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ [Even if f1/f2 were valid, insert() doesn't merge like terms or sort properly beyond first term.]
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
                p = p->next; // @@ [Missing p = p->next in loop body causes infinite loop if none of the break conditions are met.]
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