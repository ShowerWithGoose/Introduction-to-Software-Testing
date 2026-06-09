//bsts
#include<stdio.h>
#include<stdlib.h>
struct node{
    int date;
    int high;
    struct node* left, *right;
};
typedef struct node *NTNodeptr;
typedef struct node NTNode;
NTNodeptr root=NULL;
NTNodeptr madetree(int);
void put(NTNodeptr );
void insert(NTNodeptr p);
int main()
{
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        NTNodeptr q=madetree(num);
        insert(q);
    }
    put(root);
    return 0;
}

NTNodeptr madetree(int p)
{
    NTNodeptr q;
    q=(NTNodeptr)malloc(sizeof(struct node));
    q->date=p;
    q->left=q->right=NULL;
    return q;
}
void insert(NTNodeptr p){
    if (root==NULL)
    {
        p->high=1;
        root=p;
        return;
    }
    int i=1;
    NTNodeptr q=root,r;
    while (q!=NULL)
    {
        if (p->date<q->date)
        {
            r=q;
            q=q->left;
        }else{
            r=q;
            q=q->right;
        }
        i++;
    }
        if (p->date<r->date)
        {
            r->left=p;
        }else{
            r->right=p;
        }   
        p->high=i;
}
void put(NTNodeptr p)
{
    if (p->left==NULL&&p->right==NULL)
    {
        printf("%d %d\n",p->date,p->high);
    }else{
        if (p->left!=NULL)
        {
            put(p->left);
        }
        if (p->right!=NULL)
        {
            put(p->right);
        }
    }
    free(p);
    return;
}
