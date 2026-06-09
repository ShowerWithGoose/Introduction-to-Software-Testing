#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct shabi
{
    int xishu;
    int zhishu;
}shabi;
typedef struct Node
{
    shabi data;
    struct Node *link;
}Node,*Nodeptr;
Nodeptr list=NULL;
Nodeptr createNode(shabi item)//创建节点
{
    Nodeptr p;
    p=(Nodeptr)malloc(sizeof(Node));
    p->data.xishu=item.xishu;
    p->data.zhishu=item.zhishu;
    p->link=NULL;
    //printf("%d %d\n", p->data.xishu,p->data.zhishu);
    return p;
}
Nodeptr insertFirst(Nodeptr list,shabi item)//插入1：在链表的第一个结点list前面插入一个新结点；
{
    Nodeptr p;
    p=createNode(item);
    p->link=list;
    return p;
}
Nodeptr insertNode(Nodeptr list,Nodeptr p,shabi item)//插入2：在链表中指针p指的结点后插入
{
    Nodeptr q;
    q=createNode(item);
    if(p==NULL)
    {
        list=insertFirst(list,item);
    }
    else
    {
        q->link=p->link;
        p->link=q;
    }
    return list;
}
Nodeptr searchNode(Nodeptr list,shabi item)//查询链表中的值为某个元素的结点
{
    Nodeptr p=list;
    while(p!=NULL&&p->data.zhishu!=item.zhishu)
        p=p->link;
    return p;
}
Nodeptr insertSortNode(Nodeptr list,shabi item)//插入5：在有序链表中相应结点后面插入
{
    Nodeptr p,q;
    for(p=list;p!=NULL&&item.zhishu<p->data.zhishu;q=p,p=p->link);
    if(p==list)
    list=insertFirst(list,item);
    else
    {
        list=insertNode(list,q,item);
    }
    return list;
}


Nodeptr insertLast(Nodeptr list,shabi item)//插入4：在链表最后插入一个结点
{
    Nodeptr p;
    p=createNode(item);
    if(list==NULL)
    list=p;
    else
    {
        for(p=list;p->link!=NULL;p=p->link);
        list=insertNode(list,p,item);
    }
    return list;
}
int main()
{
    Nodeptr n;
    shabi a[10000],b[10000],x,y;
    char c;
    int i=0,j=0;
    y.xishu=0;y.zhishu=0;
    list=createNode(y); // @@ [This initializes the list with a dummy node (0,0), which will cause incorrect output if not handled properly. The multiplication result should not include this dummy term.]
    while(1)
    {
        scanf("%d%d",&a[i].xishu,&a[i].zhishu);
        if(getchar()=='\n') break;
        i++;
    }
    while(1)
    {
        scanf("%d%d",&b[j].xishu,&b[j].zhishu);
        if(getchar()=='\n') break;
        j++;
    }
    for(int k=0;k<=i;k++) // @@ [Loop condition should be k < i, not k <= i. Because i is the count of terms, valid indices are 0 to i-1. Same issue for m <= j below.]
    {
        for(int m=0;m<=j;m++) // @@ [Loop condition should be m < j, not m <= j. This causes reading beyond the actual input data (e.g., uninitialized values in a[i] and b[j]).]
        {
            x.xishu=a[k].xishu*b[m].xishu;
            x.zhishu=a[k].zhishu+b[m].zhishu;
            if(k==0&&m==0)
            {
                list->data.xishu=x.xishu;list->data.zhishu=x.zhishu;
            }
            else
            {
                if(searchNode(list,x)==NULL)
            {
                insertSortNode(list,x);
            }
            else
            {
                searchNode(list,x)->data.xishu+=x.xishu;
            }
            }
        }
    }
    for(n=list;n!=NULL;n=n->link)
    {
        printf("%d %d\n",n->data.xishu,n->data.zhishu); // @@ [This prints even zero-coefficient terms if they exist, but problem states only non-zero terms should be printed. Also, due to dummy node initialization and loop bounds error, output may include incorrect or extra terms.]
    }
}