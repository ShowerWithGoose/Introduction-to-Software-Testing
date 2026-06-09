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
}

int main() {
    char *in = (char *) malloc(10005 * sizeof(char));
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f1[num_a] = getnode(num, num2); // @@ The original code accessed f1[num_a]->a without allocating memory for the node pointer first, causing a segmentation fault (Runtime Error). Also, sscanf with a static string will loop infinitely if the pointer isn't advanced correctly or if the format doesn't consume the string properly, but the primary crash is dereferencing uninitialized pointers in the array.
        num_a++;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) {
        f2[num_b] = getnode(num, num2); // @@ Same error as above: accessing f2[num_b]->a on an uninitialized pointer causes Runtime Error.
        num_b++;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x);
            if(i + j == 0)
                continue;
            nptr p = head;
            int temp = f1[i]->x + f2[j]->x;
            while (p != NULL) {
                nptr q = getnode(f1[i]->a * f2[j]->a, temp);
                if (p->x == temp) {
                    p->a += f1[i]->a * f2[j]->a;
                    free(q); // @@ Memory leak fix, though not strictly runtime error, good practice. However, the logic below is flawed for sorted insertion.
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
                p = p->next; // @@ The original code missed advancing the pointer 'p' in the while loop when no insertion/break occurred, leading to an infinite loop (Runtime Error/Timeout).
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