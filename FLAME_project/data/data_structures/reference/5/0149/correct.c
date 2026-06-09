//
//  main.c
//  多项式相乘
//
//  Created by  on 2022/4/4.
//思路：类似于多项式相加，首先创建一个链表，读入第一组数字和幂次数。然后读入第二组数字和幂次，与每一项相乘，这样可以自动排好序，如果没有相同的就插入，有相同的就合并，创建和插入的话可以写一个函数来对应。
//目前的思路：首先创建第一个链表记录第一组数
//然后每次读入两个数字就创建一个结点，然后再创建一个链表，将这个节点与之前那个链表的每一个结点相乘除然后插入尾插法插入到新的链表中（注意头指针的问题）

#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    int pow;
    struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
char c=' ';
Nodeptr list=NULL, result=NULL, p,q,r,p1,p2;

Nodeptr create_list(Nodeptr list, int a, int b);
Nodeptr insert_node(Nodeptr list, int a, int b);

int main(int argc, const char * argv[])
{
    int a,b;
    int count = 0;
    while (c!='\n')
    {
        scanf("%d%d%c",&a,&b,&c);
        list = create_list(list,a,b);
    }
//    for (p=list; p!=NULL; p=p->link)
//    {
//        printf("%d %d ",p->num,p->pow);
//    }
//    printf("\n");
    c = ' ';
    while (c!='\n')
    {
        scanf("%d%d%c",&a,&b,&c);
        count++;
        if (count==1)
        {
            //printf("yes\n");
            for (p=list; p!=NULL; p=p->link)
            {
                //printf("%d %d\n",p->num,p->pow);
                result = create_list(result, a*p->num,b+p->pow);
            }
        }
        else
        {
            for (p=list; p!=NULL; p=p->link)
            {
                result = insert_node(result, a*p->num, b+p->pow);
            }
        }
//        for (p=result; p!=NULL&&p->num!=0; p=p->link)
//        {
//            printf("%d %d ",p->num, p->pow);
//        }
//        printf("\n");
    }
    for (p=result; p!=NULL&&p->num!=0; p=p->link)
    {
        printf("%d %d ",p->num, p->pow);
    }
    printf("\n");
    return 0;
}

Nodeptr create_list(Nodeptr list, int a, int b)
//注意全局变量的问题，之前这里一直写的都是p，所以会出问题，应该是r才对
{
    q = (Nodeptr)malloc(sizeof(Node));
    q->num = a;
    q->pow = b;
    q->link = NULL;
    if (list==NULL)
    {
        list = q;
        r = q;
    }
    else
    {
        r->link = q;
        r=r->link;
    }
    //printf("%d %d\n",p->num,p->pow);
    return list;
}
Nodeptr insert_node(Nodeptr list, int a, int b)
//list是形参，这个函数不能这么写
{
    r = (Nodeptr)malloc(sizeof(Node));
    r->num = a;
    r->pow = b;
    r->link = NULL;
    Nodeptr p = NULL;//这个指针是用来遍历整个链表的
    Nodeptr q = NULL;//这个指针是用来表示p1前面的结点
    for (p=result; p!=NULL&&p->pow>b; q=p,p=p->link);
    if (p==result)
    {
        r->link = result;
        result = r->link;
        return r;
    }
    else if (p!=NULL && p->pow==b)
        p->num += a;
    else
    {
        r->link = q->link;
        q->link = r;
    }
    return result;
}

