#include<stdio.h>
struct node {
    int num;
    struct node * llink, * rlink;
};
struct node * p, *list=NULL;
void build(int temp);
void compare(struct node * find, int temp);
void libian(int floor,struct node * link);
int main()
{
    int n; scanf("%d",&n);
    int i,temp;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        build(temp);
    }
    libian(0,list);
    //中序，输出数据； 
}
void libian(int floor,struct node * link)
{
    floor++;
    if((link->llink)!=NULL)
    {
        libian(floor,(link->llink));
    }
    //printf("%d ",(link->num));
    //    printf("%d\n",floor);
    else if((link->llink)==NULL&&(link->rlink)==NULL)
    {
        printf("%d ",(link->num));
        printf("%d\n",floor);
        
    }
     if((link->rlink)!=NULL)
    {
        libian(floor,(link->rlink));
    }
    
}
void build(int temp)
{
    if(list==NULL)
    {
        list=(struct node *)malloc(sizeof(struct node));
        list->num=temp;
        p=list;
        list->llink=NULL;
        list->rlink=NULL;
    }
    else
    {
        p=list;
        compare(p,temp);
        
    }
}
void compare(struct node * find, int temp)
{
    if((find->num)>temp)
    {
        if(find->llink!=NULL)
        {
            compare((find->llink),temp);
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            p->num=temp;
            find->llink=p;
            p->llink=NULL;
            p->rlink=NULL;
        }
    }
    else if((find->num)<temp)
    {
        if(find->rlink!=NULL)
        {
            compare((find->rlink),temp);
        }
        else
        {
            p=(struct node *)malloc(sizeof(struct node));
            p->num=temp;
            find->rlink=p;
            p->llink=NULL;
            p->rlink=NULL;
        }
    }
} // @@ [Missing handling for equal values: when (find->num == temp), the code does nothing, violating BST rule that right child should be >= root. This causes duplicate values to be ignored, leading to incorrect tree structure and missing leaf nodes.]