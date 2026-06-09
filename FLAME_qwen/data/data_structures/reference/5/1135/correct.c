#include<stdio.h>
#include<stdlib.h>
int i,j,n,m,num,n1,n2,n3;
struct node
{
    int a;//系数
    int b;//指数
    struct node *next;
} mutli;
struct node *first=NULL,*p,*q,*ptr;
struct node *first1,*first2,*p1,*p2,*ans;
void input();
void sum();
void combine();
void sort();
int main()
{
    input();
    n1=num;
    input();
    n2=num-n1;//输入两组数据并统计项数
    sum();//计算
    combine();//合并同类项
    sort();//以指数为标准排序
    for(p=ans;p!=NULL;p=p->next)
    {
        if(p->a<2000000)
        printf("%d %d ",p->a,p->b);
    }
    return 0;
}

void input()
{
    do
    {
        scanf("%d%d",&m,&n);
        q=(struct node*)malloc(sizeof(mutli));
        q->a=m;
        q->b=n;
        q->next=NULL;
        if(first==NULL)
            first=p=q;
        else
        {
            p->next=q;
            p=p->next;
        }
        num++;//统计项数
    }
    while(getchar()!='\n');
}

void sum()
{
    for(i=0,first2=first1=first; i<n1; i++)
        first2=first2->next;//初始化first1和first2为不同多项式的开头
    for(p1=first1; p1!=first2; p1=p1->next)
    {
        p2=first2;
        do
        {
            q=(struct node*)malloc(sizeof(mutli));
            q->a=p1->a*p2->a;//系数相乘
            q->b=p1->b+p2->b;//指数相加
            q->next=NULL;
            if(first==NULL)
                first=p=q;
            else
            {
                p->next=q;
                p=p->next;
            }
            n3++;
            p2=p2->next;
            if(n3==1)
                ans=q;//记录答案的开头
        }
        while(p2!=ans);
    }
}

void combine()
{
    for(p=ans; p!=NULL; p=p->next)
    {
        for(q=p->next,i=0; q!=NULL;q=q->next,i++)
        {
            if(p->b==q->b)
            {
                p->a+=q->a;
                for(j=0,ptr=p;j<i;j++)
                    ptr=ptr->next;
                ptr->next=q->next;
                free(q);
            }
        }
    }
}

void sort()
{
    int temp;
    for(p=ans; p!=NULL; p=p->next)
    {
        for(q=p->next; q!=NULL; q=q->next)
        {
            if(p->b<q->b)
            {
                temp=p->b;
                p->b=q->b;
                q->b=temp;
                temp=p->a;
                p->a=q->a;
                q->a=temp;
            }
        }
    }
}

