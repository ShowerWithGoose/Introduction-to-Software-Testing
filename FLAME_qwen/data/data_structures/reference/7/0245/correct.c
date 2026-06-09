#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node{
    int data;
    struct node *l, *r;
};

void order(struct node*, int);

int main(){
    struct node *tree, *p1, *p2;
    int tmp, num, isMinus;
    char c;
    tree = p1 = p2 = NULL;
    scanf("%d\n", &num);
    while(num-- > 0){
        tmp = 0;
        isMinus = 0;
        if((c = getchar()) == '-'){
            isMinus = 1;
        }else{
            ungetc(c, stdin);
        }
        while(isdigit(c = getchar())){
            tmp = tmp * 10 + c - '0';
        }
        if(isMinus == 1){
            tmp = 0 - tmp;
        }
        p2 = malloc(sizeof(struct node *));
        p2->data = tmp;
        p2->l = p2->r = NULL;
        if(tree == NULL){
            tree = p1 = p2;
        }else{
            p1 = tree;
            while(1){
                if(tmp < p1->data){
                    if(p1->l == NULL){
                        p1->l = p2;
                        break;
                    }
                    p1 = p1->l;
                }else{
                    if(p1->r == NULL){
                        p1->r = p2;
                        break;
                    }
                    p1 = p1->r;
                }
            }
        }
    }
    order(tree, 1);
    return 0;
}

void order(struct node *t, int depth){
    if(t != NULL){
        order(t->l, depth + 1);
        order(t->r, depth + 1);
        if(t->l == NULL && t->r == NULL){
            printf("%d %d\n", t->data, depth);
        }
    }
}

