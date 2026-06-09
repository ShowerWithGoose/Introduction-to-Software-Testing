#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct Tree{
    struct Tree* l;
    struct Tree* r;
    int value;
    int height;
}*root,temp[10000];
int tempcount = 0;

void insert(struct Tree* a,struct Tree* b){
    while(1){
        a->height ++;
        if(a->value < b->value){
            if(b->l == NULL){
                b->l = a;
                return;
            }else{
                b = b->l;
                continue;
            }
        }else{
            if(b->r == NULL){
                b->r = a;
                return;
            }else{
                b = b->r;
                continue;
            }
        }
    }
}

void traverse(struct Tree* a){
    temp[tempcount ++] = *a;
    while(tempcount != 0){
        tempcount --;
        struct Tree x = temp[tempcount];
        if(x.r != NULL){
            temp[tempcount] = *x.r;
            tempcount ++;
        }
        if(x.l != NULL){
            temp[tempcount] = *x.l;
            tempcount ++;
        }
        if(x.l == NULL && x.r == NULL){
            printf("%d %d\n",x.value,x.height);
        }
    }
}

int main(){

    int n;
    root = (struct Tree*)(malloc(sizeof(struct Tree)));
    root->height = 1; root->l = root->r = NULL;
    scanf("%d",&n);
    scanf("%d",&root->value);
    for(int q = 1;q < n;q ++){
        struct Tree* newNode = (struct Tree*)(malloc(sizeof(struct Tree)));
        newNode->height = 1; newNode->l = newNode->r = NULL;
        scanf("%d",&newNode->value);
        insert(newNode,root);
    }
    traverse(root);
}
