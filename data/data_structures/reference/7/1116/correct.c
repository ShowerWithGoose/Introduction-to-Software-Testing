#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h> 
struct TRee
{
    int Number;
    struct TRee* left;
    struct TRee* right;
    int high;
};
typedef struct TRee Tree;
Tree *p=NULL,*q=NULL,*head=NULL;
void dfs(Tree *idx)
{
    if(idx->left==NULL&&idx->right==NULL)
    {
        printf("%d %d\n",idx->Number,idx->high);
    }
    if(idx->left!=NULL) dfs(idx->left);
    if(idx->right!=NULL) dfs(idx->right);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
       int x;
       scanf("%d",&x);
       if(head==NULL)
       {
           q=(Tree*)malloc(sizeof(Tree));
           q->Number=x;
           q->left=NULL;
           q->right=NULL;
           q->high=1;
           head=q;
           p=q;
       }
       else
       {
           int cnt=2;
           p=head;
           while(1)
           {
               if(x<p->Number&&p->left==NULL)
               {
                  q=(Tree*)malloc(sizeof(Tree));
                  p->left=q;
                  q->Number=x;
                  q->left=NULL;
                  q->right=NULL;
                  q->high=cnt;
                  break;
               }
               else if(x>=p->Number&&p->right==NULL)
               {
                  q=(Tree*)malloc(sizeof(Tree));
                  p->right=q;
                  q->Number=x;
                  q->left=NULL;
                  q->right=NULL;
                  q->high=cnt;
                  break;
               }
               else if(x<p->Number&&p->left!=NULL)
               {
                   p=p->left;
                   cnt++;
               }
               else if(x>=p->Number&&p->right!=NULL)
               {
                   p=p->right;
                   cnt++;
               }
           }
       }
    }
    dfs(head);
    return 0;
}

