#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    int xishu;
    int zhishu;
    struct node *next;
    struct node *before;
}snode;
snode *creat(int xi,int zhi);
snode *get_poly();
int main()
{
    snode *start1=(snode *)malloc(sizeof(snode));
    start1=creat(0,0);
    snode *head1=(snode *)malloc(sizeof(snode));

    start1=get_poly();
    head1=start1;
    //第一部分
    snode *start2=(snode *)malloc(sizeof(snode));
    start2=creat(0,0);
    snode *head2=(snode *)malloc(sizeof(snode));
    start2=get_poly();
    head2=start2;
    //第二部分
    snode *ret=(snode *)malloc(sizeof(snode));
    ret=creat(0,0);//答案
    snode *p=(snode *)malloc(sizeof(snode));//用来标记ret的地址的
    p=ret;
    int flag=0;//如果是第一个，那么直接放上去否则要比较答案
    /*while(head1!=NULL)
    {
        printf("%d ",head1->xishu);
        head1=head1->next;
    }*/
   while(head1!=NULL)
    {
        head2=start2;
        while(head2!=NULL)
        {
            int temp_xishu=head1->xishu*head2->xishu;
            int temp_zhishu=head1->zhishu+head2->zhishu;
            snode *temp=(snode *)malloc(sizeof(snode));
            temp=creat(temp_xishu,temp_zhishu);//得到某一次的乘积
            if(flag==0)//是第一个
            {
                ret=temp;
                p=ret;
                flag=1;
            }
            else//并非第一个值
            {
                p=ret;
                while(p->next!=NULL&&p->zhishu>temp_zhishu)
                {
                    p=p->next;
                }
                    if(p->next==NULL)//在结尾
                    {
                        if(p->zhishu>temp_zhishu)//插入项目在末尾
                        {
                            p->next=temp;
                            temp->before=p;
                        }
                        else if(p->zhishu==temp_zhishu)//如果在结尾并且指数相同
                        {
                            int result_xishu=p->xishu+temp_xishu;
                            /*if(result_xishu==0)//删除该节点
                            {
                                p->before->next=NULL;
                                p->before=NULL;
                            }*/
                           // else
                            //
                                p->xishu=result_xishu;

                        }
                        else //(p->zhishu<temp_zhishu)//在结尾的前面插入
                        {
                            temp->before=p->before;
                            p->before->next=temp;
                            temp->next=p;
                            p->before=temp;
                        }
                    }
                    else//不是在末尾
                    {
                        if(p->zhishu==temp_zhishu)//指数相同
                        {
                            /*if(p->xishu+temp_xishu==0)//删除
                            {
                                p->next->before=p->before;
                                p->before->next=p->next;
                            }*/
                            //else//直接加
                            //{
                                p->xishu=p->xishu+temp_xishu;
                           // }
                        }
                        else//找到了大的那个项
                        {
                            temp->before=p->before;
                            p->before->next=temp;
                            temp->next=p;
                            p->before=temp;
                        }
                    }
            }
            head2=head2->next;
        }
        head1=head1->next;
    }
    p=ret;

   while(p!=NULL)
    {
        printf("%d %d ",p->xishu,p->zhishu);
        p=p->next;
    }
    return 0;

}
snode *creat(int xi,int zhi)
{
    snode *tp=(snode *)malloc(sizeof(snode));
    tp->xishu=xi;
    tp->zhishu=zhi;
    tp->next=NULL;
    tp->before=NULL;
    return tp;
}
snode *get_poly()
{
    int flag=0;
    int expon=1;//指数
    int coef=1;//系数
    snode *head=(snode *)malloc(sizeof(snode));
    snode *start=(snode *)malloc(sizeof(snode));
    start=creat(0,0);
    head=creat(0,0);
    char c;
    while(1)
    {
        scanf("%d%d",&coef,&expon);
        if(flag==0)//if is the first
        {
            snode *temp=(snode *)malloc(sizeof(snode));
            temp=creat(coef,expon);
            start=temp;
            head=temp;
            flag=1;
        }
        else //if is the next one
        {
            snode *temp=(snode *)malloc(sizeof(snode));
            temp=creat(coef,expon);
            head->next=temp;
            temp->before=head;
            head=head->next;
        }
        char c;
        if((c=getchar())=='\n')
            return start;
    }

    return start;
}


