#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
    int coe;
    int pow;
    struct node *link;
};//系数和指数

typedef struct node Node;
typedef struct node *Link;
int main()
{
    Link list1,p1,q1,list,p,q;
    list1=p1=NULL;//第一个多项式
    list=p=NULL;//乘完后的最终多项式

    int a,b;
    char c;
    do
    {//p1指向最后一个节点
        scanf("%d%d%c", &a, &b, &c);
        q1=malloc(sizeof(Node));
        q1->coe=a;   q1->pow=b;   q1->link=NULL;
        if(list1==NULL) {list1=p1=q1;}
        else {p1->link=q1; p1=q1;}
    }while(c!='\n');//创建第一个链表

    Link r;
    r=NULL;//r始终在p的前面,q是新的节点的指针
    do//第二个多项式中每一项分别与第一个多项式相乘，储存到新的链表中
    {//现在考虑第二个多项式中的某一项
        scanf("%d%d%c", &a, &b, &c);
        for(p1=list1;p1!=NULL;p1=p1->link)
        {
            q=malloc(sizeof(Node));
            q->coe=(p1->coe)*a;
            q->pow=(p1->pow)+b;
            q->link=NULL;

            if(list==NULL) {list=p=q;}
            else
            {
                for(p=list;p!=NULL;r=p,p=p->link)
                {//分两种情况讨论
                    if((p->pow)<(q->pow))
                    {
                        if(p==list) {q->link=p; list=q; break;}//插到头节点前
                        else {q->link=p; r->link=q; break;}//插到r,p之间
                    }
                    else if(p->pow==q->pow) {p->coe+=q->coe; break;}
                }
                if(p==NULL)//注意尾节点！
                {
                    r->link=q; // 注意！！！ 这里不能用break
                }
            }

        }
    }while(c!='\n');//注意，这是单引号，不是双引号！

    for(p=list;p!=NULL;p=p->link)
        printf("%d %d ", p->coe, p->pow);
    printf("\n");

    
    return 0;
}
