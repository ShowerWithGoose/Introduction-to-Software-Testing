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

nptr new_node() { return (nptr) malloc(sizeof(node)); } // 为新的节点开辟空间 @@ [missing #include <stdlib.h> is present, but malloc may still be undeclared if headers are not properly ordered; however, more critically, this function does not check for allocation failure, but that's not the main error here]
// 申请一个值域为 x 的新节点
nptr getnode(int a, int x) {
    nptr p = new_node();
    p->a = a;
    p->x = x;
    p->next = NULL;
    return p;
}

nptr f1[10005], f2[10005]; // @@ [these are arrays of pointers, but they are never initialized to point to valid memory before being dereferenced]

void insert(int x, int y) {
    if (head == NULL)
        head = getnode(x, y);
} // @@ [this insert function only handles the first insertion; it never appends or merges terms beyond the first term]

int main() {
    char *in = (char *) malloc(10005 * sizeof(char)); // @@ [malloc may return NULL; also, gets is dangerous and deprecated, but the real issue is below]
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in); // @@ [gets is unsafe and may not be available in modern compilers; more importantly, if input is empty, in may be uninitialized or cause undefined behavior]
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ [sscanf returns number of successfully matched items, not EOF; should compare to 2]
        f1[num_a]->a = num; // @@ [f1[num_a] is an uninitialized pointer; writing to ->a causes segmentation fault or undefined behavior]
        f1[num_a++]->x = num2; // @@ [same as above: dereferencing uninitialized pointer]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ [same sscanf issue: should check for == 2, not != EOF]
        f2[num_b]->a = num; // @@ [f2[num_b] is uninitialized pointer; dereference is invalid]
        f2[num_b++]->x = num2; // @@ [same as above]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ [insert only sets head once; subsequent calls do nothing, so multiplication result is incomplete]
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