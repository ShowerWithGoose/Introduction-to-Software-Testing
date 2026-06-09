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

nptr f1[10005], f2[10005]; // @@ [f1 and f2 are arrays of pointers, but each element is never allocated memory. Dereferencing them later causes segmentation fault.]

void insert(int x, int y) {
    if (head == NULL)
        head = getnode(x, y);
    // @@ [This function only inserts the very first node. Subsequent calls do nothing because head is no longer NULL. All later products are lost. Should insert in sorted order, or use a general insertion function.]
}

int main() {
    char *in = (char *) malloc(10005 * sizeof(char));
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f1[num_a]->a = num; // @@ [f1[num_a] is an uninitialized pointer. Dereferencing it causes segmentation fault. Should allocate a node before assignment, or use an array of struct node instead of pointers.]
        f1[num_a++]->x = num2; // @@ [Same issue: f1[num_a] (previous index) is uninitialized. Also, the increment happens after dereferencing, but the pointer is still invalid.]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f2[num_b]->a = num; // @@ [Same uninitialized pointer issue for f2.]
        f2[num_b++]->x = num2; // @@ [Same issue.]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ [f1[i] and f2[j] are uninitialized pointers, causing crash earlier. Even if they were valid, insert only works for first term.]
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