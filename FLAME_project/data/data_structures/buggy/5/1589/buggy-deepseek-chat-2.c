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
    for(p=list;p!=NULL&&item.zhishu<p->data.zhishu;q=p,p=p->link); // @@ 当p为NULL时，q可能未初始化，导致后续使用q时出现未定义行为
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
        for(p=list;p->link!=NULL;p=p->link); // @@ 循环结束后p指向最后一个节点，但后续调用insertNode时传入p作为参数，而insertNode会在p后面插入，但这里p已经是最后一个节点，且insertNode中会创建新节点并链接，但此函数中又创建了一个节点p，导致内存泄漏和逻辑错误
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
    list=createNode(y);
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
    for(int k=0;k<=i;k++)
    {
        for(int m=0;m<=j;m++)
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
                insertSortNode(list,x); // @@ 函数返回新的链表头，但此处未更新list，导致链表头可能丢失
            }
            else
            {
                searchNode(list,x)->data.xishu+=x.xishu; // @@ 重复调用searchNode，效率低下且逻辑正确但可优化
            }
            }
        }
    }
    for(n=list;n!=NULL;n=n->link)
    {
        printf("%d %d\n",n->data.xishu,n->data.zhishu); // @@ 输出格式错误，每个项后应输出空格而不是换行，且最后一项后不应有空格
    }
}