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
    list=createNode(y); // @@ [The initial node has coefficient 0 and exponent 0, which may incorrectly represent a zero term that should not appear in output if all terms cancel out or if it's just a placeholder. More critically, the logic below assumes this dummy node is part of the result, leading to incorrect handling when k=0,m=0 overwrites it, but subsequent terms may not properly merge with existing terms due to flawed insertion logic.]
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
    for(int k=0;k<=i;k++) // @@ [Loop condition should be k < i, not k <= i, because i is the count of terms (0-based index), so valid indices are 0 to i-1. Same issue for m <= j. This causes reading beyond the actual input data, leading to undefined behavior or incorrect multiplication using uninitialized values.]
    {
        for(int m=0;m<=j;m++) // @@ [Same as above: should be m < j, not m <= j.]
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
                searchNode(list,x)->data.xishu+=x.xishu; // @@ [This line modifies the node returned by searchNode, but insertSortNode does not maintain a fully sorted list during incremental insertion because it inserts based on descending order assumption, yet the traversal in searchNode doesn't account for possible duplicate exponents inserted out-of-order. Also, after modifying the coefficient, if it becomes zero, the node should be removed, but it isn't.]
            }
            }
        }
    }
    for(n=list;n!=NULL;n=n->link)
    {
        printf("%d %d\n",n->data.xishu,n->data.zhishu); // @@ [Output format requires space-separated terms on one line, not newline-separated. Also, zero-coefficient terms (which can result from cancellation) are printed, violating the requirement to only output non-zero terms.]
    }
}