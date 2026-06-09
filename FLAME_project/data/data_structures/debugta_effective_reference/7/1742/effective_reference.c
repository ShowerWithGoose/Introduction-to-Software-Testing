#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct bst{
    int num;
    int depth;
    struct bst *lchild,*rchild;
}*head = NULL,*p = NULL,*q = NULL;
void inorder(struct bst *t);
int main(){
    int get,n,high = 1;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&get);
        high = 1;
        if(head == NULL){
            head = (struct bst*)malloc(sizeof(struct bst));
            head->depth = high;
            head->num = get;
            head->lchild = head->rchild = NULL;
        }
        else{
            p = (struct bst*)malloc(sizeof(struct bst));
            p->num = get;
            p->lchild = p->rchild = NULL;
            q = head;
            while(1){
                high++;
                if(get >= q->num){
                    if(q->rchild == NULL){
                        p->depth = high;
                        q->rchild = p;
                        break;
                    }
                    else{
                        q = q->rchild;
                    }
                }
                else{
                    if(q->lchild == NULL){
                        p->depth = high;
                        q->lchild = p;
                        break;
                    }
                    else{
                        q = q->lchild;
                    }
                }
            }
        }
    }
    //printf("struct success\n");
    inorder(head);
    system("pause");
    return 0;
}
void inorder(struct bst *t){
    if(t != NULL){
        inorder(t->lchild);
        inorder(t->rchild);
        if(t->lchild ==NULL && t->rchild == NULL){
            printf("%d %d\n",t->num,t->depth);
        }
    }
    return;
}
