#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct node
{
    int num;
    int hight;
    struct node *left,*right;
};

typedef struct node node;
typedef struct node* nodeptr;
nodeptr creat1(nodeptr a, int m,int l)
{
    l++;
    if(a==NULL)
    {
        a=(nodeptr)malloc(sizeof(node));
        a->num=m;
        a->left=NULL;
        a->right=NULL;
        a->hight=l;
    }
    else if(m<a->num)
        a->left=creat1(a->left,m,l);
    else if(m>=a->num)
        a->right=creat1(a->right,m,l);
    return a;
}
void search1(nodeptr a)
{
    if(a)
    {
        if((a->left==NULL) && (a->right==NULL))
            printf("%d %d\n",a->num,a->hight);
        search1(a->left);
        search1(a->right);
    }
}
int main()
{
    int m,n;
    scanf("%d",&n);
    nodeptr a=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        int l=0;
        a=creat1(a,m,l);
    }
    search1(a);
}

