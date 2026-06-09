#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if(a > b) return a;
    return b;
}
int min(int a, int b){
    if(a < b) return a;
    return b;
}

typedef struct Tree{
//    struct Tree * last;
    int a;
    int c;
    struct Tree * l;
    struct Tree * r;
} tree;

void find(tree * t){
    if(t == NULL) return;
    if(t->l == NULL && t->r == NULL){
        printf("%d %d\n", t->a, t->c);
        return;
    }
    find(t->l); find(t->r);
}

int main()
{
    int n; scanf("%d", &n);
    tree * head;
    for(int i = 0; i < n; i++){
        int t; scanf("%d", &t);
        if(i == 0){
            tree * p = (tree*)malloc(sizeof(tree));
            p->a = t; p->c = 1;
//          p->last = NULL;
            p->l = NULL; p->r = NULL;
            head = p;
        }
        else{
            tree * st = head;
            tree * ls = NULL;
            while(1){
                if(st == NULL){
                    tree * p = (tree*)malloc(sizeof(tree));
                    p->a = t; p->c = (ls->c)+1;
//                    p1->last = ls;
                    p->l = NULL; p->r = NULL;
                    st = p;
                    if(t < ls->a) ls->l = p;
                    else ls->r = p;
                    break;
                }
                else if(t < st->a) ls = st, st = st->l;
                else ls = st, st = st->r;
            }
        }
    }
    find(head);
    printf("\n");
    return 0;
}

/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35

*/

