#include<stdio.h>
#include<math.h>
#include <ctype.h>
#define sf scanf
#define pf printf
#define ll long long
#define eps 1e-8
#include<string.h>
#include<stdlib.h>
#define ui unsigned int
#define max(a,b) ((a)>(b))?(a):(b)
typedef int datatype;
typedef struct node{
    datatype data;
    struct node*left;
    struct node*right;
    int deep;   
}tree,*Tree;
Tree head=NULL;
void out(Tree b)
{
    if(b!=NULL)
    {
        out(b->left);
        if(b->left==NULL&&b->right==NULL) // @@ Duplicate: this and the next if condition cause each leaf to be printed twice
            printf("%d %d\n",b->data,b->deep); // @@ This line prints leaf node, but later will print again
        out(b->right);
        if(b->left==NULL&&b->right==NULL) // @@ Duplicate condition causing second print for the same leaf
            printf("%d %d\n",b->data,b->deep); // @@ This line causes another duplicate print for leaf node
    }
}
int main()
{
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        Tree q=NULL,p=NULL;
        scanf("%d",&num);
        q=(Tree)malloc(sizeof(tree));
        q->data=num;
        q->left=NULL;
        q->right=NULL;
        q->deep=1;
        if(head==NULL)
            head=q;
        else
        {
              p=head;
              while(1)
              {
                if(num<p->data)
                {
                    if(p->left!=NULL)
                    {
                        q->deep++;
                        p=p->left;
                    }
                    else{
                        q->deep++;
                        p->left=q;
                        break;
                    }
                }
                else
                {
                    if(p->right!=NULL)
                    {
                        q->deep++;
                        p=p->right;
                    }
                    else{
                        q->deep++;
                        p->right=q;
                        break;
                    }
                }
              }
        }
    }
    out(head);
    return 0;
}