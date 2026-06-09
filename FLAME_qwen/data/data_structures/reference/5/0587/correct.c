#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int a;
    int x;
    struct Node* p;
} node;

char a[1000000];

int main()
{
    long long la1 = 2147483649, la2 = 0;
    int n1 = -1, n2 = 1;
    node* head = NULL;
    node* last = NULL;
    while(1){
        int a, x; scanf("%d%d", &a, &x);
        if(la1 <= x){
            la1 = a; la2 = x;
            break;
        }
        node* t = (node*)malloc(sizeof(node));
        t->a = a; t->x = x; t->p = NULL;
        if(n1 == -1){
            head = t;
            last = t;
        }
        else{
            last->p = t;
            last = t;
        }
        n1++;
        la1 = x;
    }
    last->p = NULL;

    node* load = (node*)malloc(sizeof(node));
    load->a = la1; load->x = la2; load->p = NULL;

    last = load;

    int a1 = 0, x1 = 0;

    while(scanf("%d%d", &a1, &x1) != EOF){
        node* t = (node*)malloc(sizeof(node));
        t->a = a1; t->x = x1; t->p = NULL;
        last->p = t;
        last = t;
        n2++;
    }

    last->p = NULL;
    node* s = NULL, * t1 = head;
    int num1 = 0, num2 = 0;
    while(t1 != NULL){
        num2 = 0;
        node* t2 = load;
        while(t2 != NULL){
            int a = (t1->a)*(t2->a), x = (t1->x)+(t2->x);
            if(s == NULL){
                node* t = (node*)malloc(sizeof(node));
                t->a = a; t->x = x; t->p = NULL;
                s = t;
            }
            else{
                node* t3 = s;
                node* la = t3;
                int is = 1;
                while(t3 != NULL){
                    if(t3->x > x){
                        la = t3;
                        t3 = t3->p;
                    }
                    else if(t3->x == x){
                        t3->a += a;
                        is = 0;
                        break;
                    }
                    else if(t3->x < x){
                        node* t = (node*)malloc(sizeof(node));
                        t->a = a; t->x = x; t->p = t3;
                        la->p = t;
                        is = 0;
                        break;
                    }
                }
                if(is == 1){
                    node* t = (node*)malloc(sizeof(node));
                    t->a = a; t->x = x; t->p = NULL;
                    la->p = t;
                }
            }
            t2 = t2->p;
        }
        t1 = t1->p;
    }
    while(s != NULL){
        printf("%d %d ", s->a, s->x);
        s = s->p;
    }
    printf("\n");
    return 0;
}

