#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode {
    int xi;
    int zhi;
    struct polyNode* next;
} pn;

pn *heada, *headb, *headc, *headd;

void Init() {
    heada = (pn*)malloc(sizeof(pn));
    headb = (pn*)malloc(sizeof(pn));
    headc = (pn*)malloc(sizeof(pn));
    headd = (pn*)malloc(sizeof(pn));
    heada->next = NULL;
    headb->next = NULL;
    headc->next = NULL;
    headd->next = NULL;
}

void getNode(pn* head, int ixi, int izhi) {
    pn* p = head;
    pn* newNode = (pn*)malloc(sizeof(pn));
    newNode->xi = ixi;
    newNode->zhi = izhi;
    newNode->next = NULL;
    while (p->next) {
        p = p->next;
    }
    p->next = newNode;
    return;
}

void mergeList(pn* head1, pn* head2) {
    pn* p = head1->next;
    pn* q = head2->next;
    pn* r = head2;
    while (p && q) {
        if (p->zhi > q->zhi) {
            r->next = p;
            r = p;
            p = p->next;
        } else if (p->zhi < q->zhi) {
            r->next = q;
            r = q;
            q = q->next;
        } else {
            p->xi += q->xi;
            r->next = p;
            r = p;
            p = p->next;
            q = q->next;
        }
    }
    r->next = p ? p : q;
    return;
}

void freeList(pn* head) {
    if (head) {
        pn* p = head->next;
        pn* q = head->next;
        while (p) {
            q = p;
            p = p->next;
            free(q);
        }
        head->next = NULL;
    }
    return;
}

int main() {
    Init();
    int i = 0;
    int tempxi, tempzhi;
    while (scanf("%d %d", &tempxi, &tempzhi)) {
        getNode(heada, tempxi, tempzhi);
        if (getchar() == '\n') break;
    }
    i = 0;
    while (scanf("%d %d", &tempxi, &tempzhi)) {
        getNode(headb, tempxi, tempzhi);
        if (getchar() == '\n') break;
    }
    pn* q = headb->next;
    while (q) {
        pn* r = heada->next;
        int bxi = q->xi, bzhi = q->zhi;
        while (r) {
            int cxi = bxi * r->xi, czhi = bzhi + r->zhi;
            getNode(headc, cxi, czhi);
            r = r->next;
        }
        mergeList(headc, headd);
        headc->next = NULL;
        q = q->next;
    }
    pn* r = headd->next;
    while (r) {
        if (r->xi) printf("%d %d ", r->xi, r->zhi);
        r = r->next;
    }
    return 0;
}
