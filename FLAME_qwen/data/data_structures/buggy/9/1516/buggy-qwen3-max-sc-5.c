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
int linecnt; // @@ [Global variables are initialized to zero by default, but 'linecnt' should be explicitly initialized to 0 for clarity and safety, though this is not the cause of compilation error.]

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
        int i = 0, j = 0;
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
        if (i == linecnt && j == linecnt) list[linecnt++] = p;
    }
    int maxlen = 0;
    int savex,savey;
    int maxx, maxy; // @@ [Variables 'maxx' and 'maxy' may be used uninitialized if no valid chain is found, leading to undefined behavior at runtime, but this is not a compilation error.]
    for (int i = 0; i < linecnt; i++) {
        if (jump[i]) continue;
        int cnt = 0;
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