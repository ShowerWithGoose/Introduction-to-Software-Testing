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

nptr f1[10005], f2[10005]; // @@ [Array elements f1[i] and f2[i] are never allocated memory; they are uninitialized pointers.]

void insert(int x, int y) {
    if (head == NULL)
        head = getnode(x, y); // @@ [Only inserts when head is NULL; subsequent calls do nothing, causing only the first product term to be stored.]
}

int main() {
    char *in = (char *) malloc(10005 * sizeof(char));
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ [sscanf returns the number of items read, not EOF; should check if return value == 2.]
        f1[num_a]->a = num; // @@ [Dereferencing uninitialized pointer f1[num_a].]
        f1[num_a++]->x = num2; // @@ [Same as above. Also increments num_a after using the pointer.]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1; // @@ [Modifying 'in' pointer loses the original allocated memory, causing memory leak and incorrect parsing.]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1; // @@ [Same issue; also logic assumes exactly two spaces per term, which is fragile.]
        else
            break;
    }
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ [Same EOF misuse.]
        f2[num_b]->a = num; // @@ [Dereferencing uninitialized pointer f2[num_b].]
        f2[num_b++]->x = num2; // @@ [Same issue.]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1; // @@ [Same pointer modification problem.]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ [f1[i] and f2[j] are uninitialized; core dump likely.]
            if(i + j == 0)
                continue;
            nptr p = head;
            int temp = f1[i]->x + f2[j]->x; // @@ [Same uninitialized pointer issue.]
            while (p != NULL) {
                nptr q = getnode(f1[i]->a * f2[j]->a, temp); // @@ [Memory allocated but not always used, leading to leaks.]
                if (p->x == temp) {
                    p->a += f1[i]->a * f2[j]->a; // @@ [Uninitialized pointers again; also logic for same exponent is incomplete.]
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