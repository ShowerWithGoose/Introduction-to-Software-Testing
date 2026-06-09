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
    for(p=list;p!=NULL&&item.zhishu<p->data.zhishu;q=p,p=p->link); // @@ The variable 'q' is used uninitialized in the first iteration if the condition fails immediately or if list is NULL, leading to undefined behavior. Also, logic for inserting at head vs middle/end is flawed because 'q' might not be set correctly if the loop doesn't execute or executes once.
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
    list=createNode(y); // @@ Initializing the list with a dummy node containing 0 coefficient and 0 exponent causes an extra term "0 0" to appear in the output if not handled, or interferes with the multiplication logic if this term is treated as a valid polynomial term.
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
                list->data.xishu=x.xishu;list->data.zhishu=x.zhishu; // @@ Overwriting the dummy node's data directly. If the first product term has coefficient 0, it remains. More importantly, the list still contains this initial node structure.
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
        printf("%d %d\n",n->data.xishu,n->data.zhishu); // @@ The expected output format requires terms to be separated by spaces on the same line (or specific formatting), but here each term is printed on a new line. Additionally, if the initial dummy node resulted in a 0 coefficient term that wasn't removed, it will be printed. The problem states "Output the result... Print the terms... separated by a space". The reference output shows all terms on one line.
    }
}