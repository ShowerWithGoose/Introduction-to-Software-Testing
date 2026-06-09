#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coifficient;
    int index;
    struct Node* next;
}Node, * List;

List InitList() {
    List p = (List)malloc(sizeof(Node));
    p->next = NULL;
    if (p != NULL) return p;
}

void DestroyList(List linearlist) {
    List p, pre;
    for (p = linearlist->next, pre = linearlist; p != NULL;) {
        pre = p;
        p = p->next;
        free(pre);
    }
}

int PushBack(List linearlist, Node* node) {
    Node* p = linearlist;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = node;
    node->next = NULL;
    return 1;

}

int DestroyNode(List linearlist, Node* p) {
    if (p == linearlist) return -1;
    if (p->next == NULL) {
        Node* p_str = linearlist;
        for (p_str = linearlist->next; p_str != NULL; p_str = p_str->next) {
            if (p_str->next == p) break;
        }
        if (p_str->next == p) {
            p_str->next = NULL;
            free(p);
            return 1;
        }
        else return -1;
    }
    Node* pre = p;
    Node* other = p->next;
    pre->coifficient = other->coifficient;
    pre->index = other->index;
    pre->next = other->next;
    free(other);
    return 1;
}

List merge(List list1, List list2) {
    List li = (List)malloc(sizeof(Node));
    Node* p = li;
    Node* better;
    if(list1==NULL){
        free(li);
        return list2;
    }else if(list2==NULL){
        free(li);
        return list1;
    }else if(list1==NULL&&list2==NULL){
        free(li);
        return NULL;
    }
    Node* p_str1 = list1->next;
    Node* p_str2 = list2->next;
    while (p_str1 != NULL && p_str2 != NULL) {
        better = (p_str1->index >= p_str2->index) ? p_str1 : p_str2;
        if (better == p_str1) {
            if(p_str1->index > p_str2->index )p_str1 = p_str1->next;
            else {
                Node* p_str3 = p_str2;
                p_str1->coifficient += p_str2->coifficient;
                p_str2 = p_str2->next;
                p_str1 = p_str1->next;
                free(p_str3);
            }
        }
        else {
            p_str2 = p_str2->next;
        }
        p->next = better;
        p = p->next;
    }
    if (p_str1 == NULL) {
        if (p_str2 != NULL) {
            p->next = p_str2;
        }
    }
    else if(p_str2==NULL){
        if (p_str1 != NULL) {
            p->next = p_str1;
        }
    }

    return li;
}


char buf[10] = { 0 };

    int main() {
    List list1 = InitList();
    int Nindex, Ncoifficient;
    while (scanf_s("%d %d", &Ncoifficient, &Nindex)) { // @@ [Using scanf_s which is not standard in GCC and causes implicit declaration and linking errors; should use scanf instead]
        Node* p = (Node*)malloc(sizeof(Node));
        p->coifficient = Ncoifficient;
        p->index = Nindex;
        PushBack(list1, p);
        char c = getchar();
        if (c == '\n') break;
    }
    Node* start = list1->next;
    List li = NULL;
    while (scanf_s("%d %d", &Ncoifficient, &Nindex)) { // @@ [Same error: scanf_s is non-standard and not available in standard C library on Linux/GCC environments]
        List list2 = InitList();
        start = list1->next;
        while(start!=NULL){
            Node* p = (Node*)malloc(sizeof(Node));
            p->coifficient = Ncoifficient*start->coifficient;
            p->index = Nindex + start->index;
            PushBack(list2, p);
            start =start->next;
        }
        li = merge(li,list2);
        char c = getchar();
        if (c == '\n') break;
    }

    Node* p = li;
    for (p = p->next; p != NULL; p = p->next) {
        printf("%d %d ", p->coifficient, p->index);
    }
    printf("\n");
    DestroyList(li);
    free(list1);
    return 0;
    }