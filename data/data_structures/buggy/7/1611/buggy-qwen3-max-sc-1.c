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
} // @@ [Function 'create' is declared to return void* but does not return anything. This leads to undefined behavior when assigning its result to 'head' in main().]

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
        if(p->lchild!=NULL) inorder(p->lchild);
        if(p->rchild!=NULL) inorder(p->rchild);
    } // @@ [In-order traversal is implemented incorrectly: it prints leaf nodes before traversing children, and the recursive calls are not in proper in-order sequence (left, root, right). This results in incorrect left-to-right leaf order.]
}

int main()
{
    int n,i;
    int a;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    scanf("%d",&a);
    //printf("a=%d\n",a);
    head=create(a); // @@ [Assigning void* return of 'create' (which actually returns nothing) to 'head' causes undefined behavior. Also, 'create' should return struct node*, not void*.]
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
} // @@ [Memory leak: only the root node 'head' is freed, but all other dynamically allocated nodes in the tree are not freed. However, this may not cause compilation error but is a runtime issue. The primary compilation/runtime error stems from the incorrect return type and missing return in 'create'.]