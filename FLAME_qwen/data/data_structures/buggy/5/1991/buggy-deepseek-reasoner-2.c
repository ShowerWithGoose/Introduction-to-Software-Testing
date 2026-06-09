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
    gets(in); // @@ `gets` is deprecated and removed in C11; causes compilation error in strict C11 or later.  
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ `sscanf` returns 2 on success, not EOF; condition should be `== 2`. This leads to infinite loop or early exit.  
        f1[num_a]->a = num; // @@ `f1[num_a]` is an uninitialized pointer; dereferencing it causes undefined behavior (not a compilation error but a severe logic error).  
        f1[num_a++]->x = num2;  
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;  
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;  
        else  
            break;  
    }  
    gets(in); // @@ Same issue: `gets` is deprecated/removed.  
    while (sscanf(in, "%d %d", &num, &num2) != EOF) { // @@ Same `sscanf` condition error.  
        f2[num_b]->a = num; // @@ `f2[num_b]` is an uninitialized pointer; undefined behavior.  
        f2[num_b++]->x = num2;  
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;  
        if (strstr(in, " ") != NULL) in = strstr(in, " ") + 1;  
        else  
            break;  
    }  

    for (int i = 0; i < num_a; i++) {  
        for (int j = 0; j < num_b; j++) {  
            insert(f1[i]->a * f2[j]->a, f1[i]->x + f2[j]->x); // @@ `insert` only works when `head` is NULL; subsequent calls do nothing.  
            if(i + j == 0)  
                continue;  
            nptr p = head;  
            int temp = f1[i]->x + f2[j]->x;  
            while (p != NULL) {  
                nptr q = getnode(f1[i]->a * f2[j]->a, temp); // @@ This creates a new node in every iteration, even if not used; memory leak.  
                if (p->x == temp) {  
                    p->a += f1[i]->a * f2[j]->a;  
                    break;  
                } else if (p->x != temp) { // This condition is always true when the outer `if` fails.  
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
                // Missing `p = p->next;` here causes infinite loop if no break occurs.  
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