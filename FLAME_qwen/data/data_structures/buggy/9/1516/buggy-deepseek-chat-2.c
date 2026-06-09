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
            if (iend->x2 == p->x1 && iend->y2 == p->y1) { // @@ [Error: The condition checks x2 and y2 of the end node, but the problem requires connecting based on shared endpoints. The reference program uses x1 and y1 of the current segment to match the previous segment's x2 and y2, which is correct. However, this code uses iend->x2 and iend->y2, which is the second endpoint of the last segment in the chain, but the problem states that segments connect when the second endpoint of one equals the first endpoint of the next. This logic is actually correct for connecting head-to-tail, but the issue is that the code does not handle the case where the new segment's first endpoint matches an existing chain's last endpoint (i.e., extending the chain). The condition should be checking if the new segment's x1,y1 matches the chain's last endpoint's x2,y2, which is what is done here. However, the error is that the code does not properly update the chain when connecting; it only sets iend->next = p, but does not update the chain's end pointer or handle the case where the new segment's second endpoint might connect to another chain. Additionally, the code does not handle the case where the new segment's first endpoint matches the start of an existing chain (i.e., prepending). The reference program uses a different approach with arrays, so this linked list approach has logical flaws.]
                iend->next = p;
                break;
            }
        }
        //给定尾端点连接头端点
        for (; j < linecnt; j++) {
            if (jump[j]) continue;
            if (p->x2 == list[j]->x1 && p->y2 == list[j]->y1) { // @@ [Error: This condition checks if the new segment's second endpoint matches the first endpoint of an existing chain, which is correct for connecting the new segment to the beginning of a chain. However, the code sets p->next = list[j] and marks list[j] as jumped, but it does not update the list[i] pointer to point to the new head of the combined chain. This means the combined chain's head is lost, and the chain starting from p is not properly tracked. Additionally, the code does not handle the case where both connections happen (i.e., the new segment bridges two chains), which would require merging two chains. The reference program handles this by using a single array and updating endpoints, but this linked list approach fails to merge chains correctly.]
                p->next = list[j];
                jump[j] = 1;
                break;
            }
        }
        if (i == linecnt && j == linecnt) list[linecnt++] = p; // @@ [Error: This condition only adds the new segment as a new chain if neither connection was made. However, if the new segment connects to an existing chain at both ends (i.e., it bridges two chains), both i and j will be less than linecnt, so this condition will be false, and the new segment will not be added to any chain, causing it to be lost. The reference program handles this by updating the existing chain's endpoint, but this code does not merge chains. This is a logical error that leads to incorrect counting of segments in the longest continuous line.]
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