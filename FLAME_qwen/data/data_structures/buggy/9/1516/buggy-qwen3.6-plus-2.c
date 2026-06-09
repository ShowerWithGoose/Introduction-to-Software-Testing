#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int x1;
    int y1;
    int x2;
    int y2;
    struct node* next;
}Node;

Node* list[100];
int jump[100];
int linecnt;

Node* end(Node* head)
{
    if (head == NULL) return NULL;
    Node* p = head;
    while (p->next != NULL) p = p->next;
    return p;
}

int main()
{
    int n;
    Node buf = { 0,0,0,0,NULL };
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d%d%d", &buf.x1, &buf.y1, &buf.x2, &buf.y2);
        Node* p = (Node*)malloc(sizeof(Node));
        *p = buf;
        int i = 0, j = 0; // @@ In C89/C90, variables must be declared at the beginning of a block; declaring them inside the loop body may cause a compilation error on strict compilers.
        //给定头端点连接尾端点
        for (; i < linecnt; i++) {
            if (jump[i]) continue;
            Node* iend = end(list[i]);
            if (iend->x2 == p->x1 && iend->y2 == p->y1) {
                iend->next = p;
                break;
            }
        }
        //给定尾端点连接头端点
        for (; j < linecnt; j++) {
            if (jump[j]) continue;
            if (p->x2 == list[j]->x1 && p->y2 == list[j]->y1) {
                p->next = list[j];
                jump[j] = 1;
                break;
            }
        }
        if (i == linecnt && j == linecnt) list[linecnt++] = p; // @@ If `linecnt` reaches 100, accessing `list[100]` causes an out-of-bounds error since `list` is declared with size 100 (indices 0-99).
    }
    int maxlen = 0;
    int savex,savey; // @@ Variables `savex` and `savey` are declared but not initialized; if `linecnt` is 0, they will hold garbage values, leading to undefined behavior.
    int maxx, maxy; // @@ Variables `maxx` and `maxy` are declared but not initialized; if `maxlen` remains 0, printing them results in undefined behavior.
    for (int i = 0; i < linecnt; i++) { // @@ C89/C90 does not support declaring loop variables inside the for statement; this will cause a compilation error on older compilers.
        if (jump[i]) continue;
        int cnt = 0; // @@ C89/C90 requires all variable declarations to be at the top of the block; declaring `cnt` here may cause a compilation error.
        Node* p = list[i];
        savex = p->x1, savey = p->y1;
        while (p != NULL)
        {
            cnt++;
            Node* temp = p;
            p = p->next;
            free(temp);
        }
        if (cnt > maxlen) {
            maxlen = cnt;
            maxx = savex, maxy = savey;
        }
    }
    printf("%d %d %d\n", maxlen, maxx, maxy);
    return 0;
}