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
        if (i == linecnt && j == linecnt) list[linecnt++] = p; // @@ The logic fails to merge two existing chains when the current segment connects them (one chain ends at p's start, another starts at p's end). It only appends/prepends to one chain, leaving the other chain separate and marked as jumped or unmerged, resulting in an incorrect count. Additionally, if it attaches to head (j loop), it doesn't update the list array to point to the new head (p), potentially losing track of the chain start if not handled by the fact that list[j] is still reachable via traversal from original head? No, if p->next = list[j], p is the new head. But list[j] still points to the old head. The traversal later uses list[i]. If i!=j, list[j] is marked jump. If i==j (impossible as i==linecnt), it's a new chain. The main issue is merging two existing chains.
    }
    int maxlen = 0;
    int savex,savey;
    int maxx, maxy;
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