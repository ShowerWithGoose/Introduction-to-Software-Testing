#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _multi {
    int coe;
    int exp;
    struct _multi* next;
}Node;

Node* add(Node* head, int coe, int exp);
void cal(Node* head1, Node* head2);
void sort(Node* head);

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    int coe;
    int exp;
    
    do {
        scanf("%d", &coe);
        scanf("%d", &exp);
        head1 = add(head1, coe, exp);
    } while (getchar()!='\n');

    do {
        scanf("%d", &coe);
        scanf("%d", &exp);
        head2 = add(head2, coe, exp);
    } while (getchar() != '\n');
    
    cal(head1, head2);
    return 0;
}

Node* add(Node* head, int coe, int exp) {
    //create the p Node
    Node* p = (Node*)malloc(sizeof(Node));
    p->coe = coe;
    p->exp = exp;
    p->next = NULL;

    //find the last,拼接
    Node* last = head;
    if (last != NULL) {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = p;
    }
    else {
        head = p;
    }

    return head;
}

void sort(Node* head) {
    Node* p, *q;
    for (p = head; p->next != NULL; p = p->next) {
        for (q = head->next; q != NULL; q = q->next) { // @@ The inner loop always starts from head->next, causing incorrect swaps with nodes before the current p. For descending sort, this can disrupt already sorted order. The loop should start from p->next to compare only subsequent nodes.
            if (p->exp < q->exp) {
                int tempCoe = p->coe;
                p->coe = q->coe;
                q->coe = tempCoe;

                int tempExp = p->exp;
                p->exp = q->exp;
                q->exp = tempExp;

            }
        }
    }
}

void cal(Node* head1, Node* head2) {
    Node* p = head1;
    Node* q = head2;
    Node* headResult = NULL;
    int flag = 0;        //默认找不到

    for (p = head1; p != NULL; p = p->next) {
        for (q = head2; q != NULL; q = q->next) {
            Node* temp = (Node*)malloc(sizeof(Node));
            temp->coe = p->coe * q->coe;
            temp->exp = p->exp + q->exp;
            temp->next = NULL;

            //find the last,查重并拼接
            Node* last = headResult;
            if (last != NULL) {
                flag = 0;
                while (last->next != NULL) {
                    if (last->exp == temp->exp) {
                        last->coe += temp->coe;
                        flag = 1;
                        goto here;
                    }
                    last = last->next;
                }

                if (last->exp == temp->exp) {
                    last->coe += temp->coe;
                    flag = 1;
                }

                if (flag == 0) {
                    last->next = temp;    //没合并同类项，后边加
                }
                here:;
            }
            else {
                headResult = temp;
            }
        }
    }


    //sort
    sort(headResult);

    //output
    for (p = headResult; p != NULL; p = p->next) {
        printf("%d %d ", p->coe, p->exp);
    }
}