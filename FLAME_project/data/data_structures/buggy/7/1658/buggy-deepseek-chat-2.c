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
    else if((link->llink)==NULL&&(link->rlink)==NULL) // @@ [Error: This else if is attached to the previous if, meaning it only executes when the left child is NULL. If the left child is not NULL, the else if is skipped entirely, so leaf nodes with a left child (like 100) are never printed. Should be a separate if statement.]
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
    else if((find->num)<temp) // @@ [Error: This condition only handles strictly less than, but the problem states that right child should be greater than or equal to the root. When temp equals find->num, the code does nothing, so duplicate values like the second 100 are not inserted, causing the leaf node 100 to be missing from the output.]
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
}