#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    int dep;
    struct node *lchlid,*rchlid;
}node;

node *root;

void insert(int);
void inorder(node*);
node* new_node(int);

int main(){
    int n,val;
    scanf("%d",&n);
    scanf("%d",&val);
    root= new_node(val);
    n--;
    while(n--){
        scanf("%d",&val);
        insert(val);
    }
    inorder(root);
    return 0;
}

void insert(int val){
    node *tmp,*p;
    tmp= new_node(val);
    p=root;
    while(1){
        if(p->val > tmp->val){
            if(p->lchlid==NULL) {
                tmp->dep++;
                p->lchlid = tmp;
                return;
            }
            else{
                p=p->lchlid;
                tmp->dep++;
            }
        }
        else if(p->val <= tmp->val){
            if(p->rchlid==NULL){
                tmp->dep++;
                p->rchlid=tmp;
                return;
            }
            else{
                p=p->rchlid;
                tmp->dep++;
            }
        }
    }
}

node* new_node(int val){
    node *new;
    new=(node*)malloc(sizeof (node));
    new->val=val;
    new->dep=1;
    new->lchlid=new->rchlid=NULL;
    return new;
}

void inorder(node* r){
    if(r!=NULL){
        if(r->lchlid==NULL&&r->rchlid==NULL)
            printf("%d %d\n",r->val,r->dep);
        inorder(r->lchlid);
        inorder(r->rchlid);
    }
    return;
}
