#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node
{
    int val;
    struct Node *lkid,*rkid;
};
void addTree(struct Node *head,struct Node *t)
{
    if(head->val > t->val){
        if(head->lkid == NULL)
            head->lkid = t;
        else
            addTree(head->lkid,t);
    }
    else{
        if(head->rkid == NULL)
            head->rkid = t;
        else
            addTree(head->rkid,t);
    }
    return ;
}
void searchTree(struct Node *head,int dep)
{
    if(head == NULL)
        return;
    if(head->lkid == NULL && head->rkid == NULL){
        printf("%d %d\n",head->val,dep);
        return ;
    }
    searchTree(head->lkid,dep+1);
    searchTree(head->rkid,dep+1);
}
void destoryTree(struct Node *head)
{
    if(head == NULL)
        return;
    destoryTree(head->lkid);
    destoryTree(head->rkid);
    free(head);
    return;
}
int main()
{
    struct Node *head,*t;
    int m,n,i;
    scanf("%d",&n);
    scanf("%d",&m);
    head = (struct Node *)malloc(sizeof(struct Node));
    head->lkid = head->rkid = NULL;
    head->val = m;

    for(i = 1;i < n;i++){
        scanf("%d",&m);
        t = (struct Node *)malloc(sizeof(struct Node));
        t->lkid = t->rkid = NULL;
        t->val = m;
        addTree(head,t);
    }
    searchTree(head,1);
    destoryTree(head);

    return 0;
}

