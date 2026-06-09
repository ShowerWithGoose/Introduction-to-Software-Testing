#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    int date;
    int floor;
    struct node*l;
    struct node*r;
}Node,*Nodeptr;
Nodeptr root;
Nodeptr judge(Nodeptr root,int element,int hight)
{
    if(root==NULL)
    {
        root=(Nodeptr)malloc(sizeof(Node));
        root->floor=hight;
        root->date=element;
        root->l=root->r=NULL;
    }
    else
    {
        if(root->date<=element)
        {
            root->r=judge(root->r,element,hight+1);
        }
        else
        {
            root->l=judge(root->l,element,hight+1);
        }
    }
    return root;
}
void print(Nodeptr root)
{
    if(root!=NULL)
    {
        if(root->l==NULL&&root->r==NULL)
        {
            printf("%d %d\n",root->date,root->floor);
        }
        print(root->l);
        print(root->r);
    }

}
int main()
{
    int n,i,element,hight=1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&element);
        root=judge(root,element,hight);
    }
    print(root);
}

