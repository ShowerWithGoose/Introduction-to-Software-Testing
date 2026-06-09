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
} // @@ [Function 'create' is declared to return void* but does not return anything, leading to undefined behavior. Also, using a global variable 'head' makes the code non-reentrant and error-prone.]

void into_tree(int m)
{
    struct node *p, *q;
    p=( struct node*)malloc(sizeof(struct node));
    p->data=m;
    p->height=1; // @@ [Initial height is set to 1, but it should be updated based on parent's height during insertion. However, this is later corrected when attaching to parent, so not the main issue.]
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
    } // @@ [This is not a proper in-order traversal. In-order should be: left -> root -> right. Here, the leaf check happens before traversing children, and children are traversed independently, which breaks in-order sequence. This causes output order to be incorrect (pre-order like), violating the "left to right" leaf requirement as per BST in-order.]
}

int main()
{
    int n,i;
    int a;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    scanf("%d",&a);
    //printf("a=%d\n",a);
    head=create(a); // @@ [The function 'create' returns void*, but its return value is assigned to 'head'. However, 'create' doesn't return anything, so 'head' becomes undefined (garbage). This leads to undefined behavior when used later. Also, 'head' is already global and modified inside 'create', so assignment is redundant and harmful.]
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
} // @@ [Only the root node is freed; all other allocated nodes cause memory leaks. While not causing wrong output, it's poor practice. However, the critical errors are in traversal order and create() misuse.]