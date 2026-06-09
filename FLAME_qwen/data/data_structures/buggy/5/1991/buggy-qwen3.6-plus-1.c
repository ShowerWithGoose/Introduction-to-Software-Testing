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

void insert(int x, int y) { // @@ Only inserts when head is NULL, fails to insert subsequent nodes into the linked list.
    if (head == NULL)
        head = getnode(x, y);
}

int main() {
    char *in = (char *) malloc(10005 * sizeof(char));
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in); // @@ gets is removed in C11 standard, causing compilation error; use fgets instead.
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ sscanf returns number of matched items, should check == 2 instead of != EOF to prevent infinite loop.
        f1[num_a]->a = num; // @@ f1 is an array of uninitialized pointers, dereferencing causes runtime error; should allocate memory or use struct array.
        f1[num_a++]->x = num2; // @@ Same as above, dereferencing uninitialized pointer.
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }
    gets(in); // @@ gets is removed in C11 standard, causing compilation error; use fgets instead.
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ sscanf returns number of matched items, should check == 2 instead of != EOF.
        f2[num_b]->a = num; // @@ f2 is an array of uninitialized pointers, dereferencing causes runtime error.
        f2[num_b++]->x = num2; // @@ Same as above, dereferencing uninitialized pointer.
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ Calls flawed insert function and dereferences uninitialized pointers.
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