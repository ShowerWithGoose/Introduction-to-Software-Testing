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

nptr new_node() { return (nptr) malloc(sizeof(node)); }

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
        head = getnode(x, y); // @@ [only handles first insertion; subsequent calls do nothing, losing terms]
}

int main() {
    char *in = (char *) malloc(10005 * sizeof(char));
    int num_a = 0, num_b = 0;
    int num, num2;
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ [sscanf does not return EOF on string; should check return value == 2]
        f1[num_a]->a = num; // @@ [f1[num_a] is an uninitialized pointer; dereference causes segmentation fault]
        f1[num_a++]->x = num2; // @@ [same as above; also increments before allocating memory]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }
    gets(in);
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ [same issue as above]
        f2[num_b]->a = num; // @@ [f2[num_b] uninitialized; segmentation fault]
        f2[num_b++]->x = num2; // @@ [same]
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;
        else
            break;
    }

    for (int i = 0; i < num_a; i++) {
        for (int j = 0; j < num_b; j++) {
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ [f1[i] and f2[j] are still NULL; also insert is insufficient]
            if(i + j == 0)
                continue;
            nptr p = head;
            int temp = f1[i]->x + f2[j]->x; // @@ [f1[i] still NULL]
            while (p != NULL) {
                nptr q = getnode(f1[i]->a * f2[j]->a, temp); // @@ [memory leak if condition breaks without inserting q; also f1[i] NULL]
                if (p->x == temp) {
                    p->a += f1[i]->a * f2[j]->a; // @@ [integer overflow: product may exceed int range; use long long]
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