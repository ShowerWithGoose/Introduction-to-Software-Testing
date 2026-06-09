#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct shizi
{
    long long xishu;
    long long zhishu;
    struct shizi *next;
};
typedef struct shizi *Nodeptr;
typedef struct shizi Node;
int main()
{
    Nodeptr head,p,p0,q,tmp,head2,p2,q2;
    head = head2 = p = NULL;
    long long a,b;
    char c;
    int count=0,i,j,k;
    do
    {
        scanf("%lld%lld%c", &a, &b, &c);
        q = (Nodeptr)malloc(sizeof(Node));
        q->xishu = a;
        q->zhishu = b;
        q->next = NULL;
        if(head == NULL)
             head = p = q;
        else
        {
            p->next = q;
            p = p->next;
        }
    }while (c != '\n');
    long long xi,zhi;
    /*do
    { //将第二个多项式的每个项与第一个多项式每个项相乘插入到第一个多项式链表中
        scanf("%lld%lld%c",&xi,&zhi,&c);//生成第二个多项式的一个节点
        q2 = (Nodeptr)malloc(sizeof(Node));
        for(tmp = head; tmp !=NULL; tmp = tmp->next)
        {
            q2 = (Nodeptr)malloc(sizeof(Node));
            q2->xishu = xi*tmp->xishu;
            q2->zhishu = zhi+tmp->zhishu;
            q2->next = NULL;
            if(head2==NULL)
            {
                head2 = q2;
                head2->next = NULL;
                continue;
            }
            for(p2=head2; p2 != NULL; p0=p2,p2=p2->next)
            {
                if(q2->zhishu > p2->zhishu)
                {
                    if(p2==head2)
                    {
                        q2->next = head2;
                        head2 = q2;
                        break;
                    }//插入到头节点前
                    else
                    {
                        q2->next = p2;
                        p0->next = q2;
                        break;
                    } //将q插入到p前
                }
                else if(q2->zhishu == p2->zhishu)
                {
                    p2->xishu += q2->xishu;
                    break;
                }//指数相等，系数相加
                if(p2 == NULL)
                {
                    p0->next = q2;
                    q2->next = p2;//将q插入到尾节点后
                }
            }
        }
    }while (c != '\n');*/

    do
    {
        scanf("%lld%lld%c",&xi,&zhi,&c);//生成第二个多项式的一个节点
        q = (Nodeptr)malloc(sizeof(Node));
        for(tmp = head; tmp !=NULL; tmp = tmp->next)
        {
            q = (Nodeptr)malloc(sizeof(Node));
            q->xishu = xi*tmp->xishu;
            q->zhishu = zhi+tmp->zhishu;
            q->next = NULL;
            if(head2 == NULL)
                head2 = p = q;
            else
            {
                p->next = q;
                p = p->next;
            }
            count++;
        }
    }while (c != '\n');

    for(tmp = head2; tmp !=NULL; tmp = tmp->next)
    {
        for(q = tmp->next; q !=NULL; p0=q,q = q->next)
        {
            if(tmp->zhishu == q->zhishu)
            {
                tmp->xishu += q->xishu;
                p0->next = q->next;
                free(q);
                count--;
                continue;
            }
        }
    }
    for(i=0; i<count-1; i++)
    {
        p = head2;
        for(j=0;j<count-i-1;j++)
        {
            if(p->zhishu < p->next->zhishu)
            {
                int temp;
                temp = p->xishu;
                p->xishu=p->next->xishu;
                p->next->xishu = temp;
                temp = p->zhishu;
                p->zhishu=p->next->zhishu;
                p->next->zhishu = temp;
            }
            p = p->next;
        }
    }
    for(tmp = head2; tmp != NULL; tmp = tmp->next)
    {
        printf("%lld %lld ",tmp->xishu,tmp->zhishu);
    }
    return 0;
}

