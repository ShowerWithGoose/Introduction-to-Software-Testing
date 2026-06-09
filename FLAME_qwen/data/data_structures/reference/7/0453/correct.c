#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int numb;
    int high;
    struct node  * left ,*right ;
}*root;

void print(struct node*p);
void find(int k);
void tofind(int n,int high,struct node* head,struct node* before,int dir);
struct node* start(int line,int n);

int main()
{
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
      find(i);
  }
  print(root);
  return 0;
}

void print(struct node*p)
{
    if(p!=NULL)
    {
    if(p->left==NULL&&p->right==NULL)
    {
        printf("%d %d\n",p->numb,p->high);
    }
    else
    {
        print(p->left);
        print(p->right);
    }
    }
}

void find(int k)
{
    int b;
    scanf("%d",&b);
    if(k==0)
    {
        root=start(1,b);
    }
    else
    {
        tofind(b,1,root,root,-1);
    }
}

void tofind(int n,int high,struct node* head,struct node* before,int dir)
{
    if(head==NULL)
    {
        if(dir==0)
            before->left=start(high,n);
        else if(dir==1)
            before->right=start(high,n);
    }
    else
    {
        before=head;
        if(n<head->numb)
            tofind(n,high+1,head->left,before,0);
        else if(n>=head->numb)
            tofind(n,high+1,head->right,before,1);
    }

}

struct node* start(int line,int n)
{
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->numb=n;
    p->high=line;
    p->left=p->right=NULL;
    return p;
}

