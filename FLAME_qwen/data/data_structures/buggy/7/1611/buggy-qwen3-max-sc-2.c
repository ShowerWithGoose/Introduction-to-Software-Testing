#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    int height;
    struct node *lchild;
    struct node *rchild;
};

struct node *head;
void *create(int a)
{
    //struct node *head;
    head=( struct node*)malloc(sizeof(struct node));
    head->data=a;
    head->height=1;
    head->lchild=NULL;
    head->rchild=NULL;
} // @@ [Function 'create' is declared to return void* but does not return anything, causing undefined behavior]

void into_tree(int m)
{
    struct node *p, *q;
    p=( struct node*)malloc(sizeof(struct node));
    p->data=m;
    p->height=1;
    p->lchild=NULL;
    p->rchild=NULL;
    q=head;
    while(1)
    {    
        //printf("q=%d\n",q->data);
        if(m<(q->data)) 
        {
            if((q->lchild)==NULL)
            {
                //printf("11111\n");
                q->lchild=p;
                p->height=q->height+1;
                break;
            }
            q=q->lchild;
        }
        else if(m>=(q->data)) 
        {
            if((q->rchild)==NULL)
            {
                //printf("22222\n");
                q->rchild=p;
                p->height=(q->height)+1;
                break;
            }
            q=q->rchild;
        }
    }

}
void inorder(struct node *p)
{
    if(p!=NULL)
    {
        if(p->lchild==NULL&&p->rchild==NULL)
            printf("%d %d\n",p->data,p->height);
        if(p->lchild!=NULL) inorder(p->lchild); // @@ [In-order traversal should visit left subtree, then node, then right subtree. Current logic prints leaf before traversing children, and order of recursive calls is incorrect for in-order]
        if(p->rchild!=NULL) inorder(p->rchild);
    }
}

int main()
{
    int n,i;
    int a;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    scanf("%d",&a);
    //printf("a=%d\n",a);
    head=create(a); // @@ [Assigning void* return of create() to struct node* without cast is allowed in C but the function doesn't actually return anything, leading to undefined behavior]
    //head->data=a;
    for(i=1;i<n;i++)
    {
        scanf("%d",&a);
        //printf("a=%d\n",a);
        into_tree(a);
    }
    inorder(head);
    free(head);
    //free(p);
}