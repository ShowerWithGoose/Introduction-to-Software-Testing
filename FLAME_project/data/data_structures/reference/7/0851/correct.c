#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define ep 1e-6
#define pi 3.14159265
#define pf printf
#define sf scanf
#define ll long long
#define ull unsigned long long
#define NumberOf(x) (sizeof(x) / sizeof(x[0]))
#define max(A, B) ((A) > (B) ? (A) : (B))

struct Bst{
    int num;
    int deep;
    struct Bst *lkid;
    struct Bst *rkid;
};
struct Bst *root=NULL;
void insert(int x);
void findlelf(struct Bst *p);
int main()
{ 
    int n,i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        insert(x);
    }
    findlelf(root);
}
void insert(int x)
{
    struct Bst *p,*q=NULL;
    p=(struct Bst *)malloc(sizeof(struct Bst));
    p->num=x;
    p->lkid=NULL;
    p->rkid=NULL;
    if(root==NULL)
    {
        p->deep=1;
        root=p;
    }
    else
    {
        q=root;
        while(1)
        {
            if(x<q->num&&q->lkid==NULL)
            {
                p->deep=(q->deep)+1;
                q->lkid=p;
                break;
            }
            else if(x>=q->num&&q->rkid==NULL)
            {
                p->deep=(q->deep)+1;
                q->rkid=p;
                break;
            }
            else if(x<q->num&&q->lkid!=NULL)
            q=q->lkid;
            else if(x>=q->num&&q->rkid!=NULL)
            q=q->rkid;
        }
    }
}
void findlelf(struct Bst *p)
{
    if(p!=NULL)
    {
        
        if(p->lkid==NULL&&p->rkid==NULL)
        {
            printf("%d %d\n",p->num,p->deep);
        }   
        findlelf(p->lkid);
        findlelf(p->rkid);
    }
}
