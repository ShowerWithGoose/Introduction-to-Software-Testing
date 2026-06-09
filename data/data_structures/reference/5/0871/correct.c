#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct node{
	ElemType coef;//系数 
    ElemType exp;//指数
	struct node *next;//指针域 
}slink;//取代 struct node
int n,x,y; 
int a,b;
slink*p1,*q1,*head1=NULL;
slink*p2,*q2,*head2=NULL;
slink*p;
void multislink();
int main()
{
   int i,m;
    multislink();
    for(p2=head2;p2!=NULL;p2=p2->next)
   {
       printf("%d %d ",p2->coef,p2->exp);
   }
   printf("\n");
    return 0;
}
void multislink()
{
    char c;
    do
    {
        scanf("%d%d%c",&x,&y,&c);
        q1=(slink*)malloc(sizeof(slink));//开拓一个新空间 
        q1->coef=x;q1->exp=y;q1->next=NULL;//数据放在链表中
        if(head1==NULL)//首位是空的 
        {
            head1=p1=q1;//头指针指向q1 
        }
        else //首位不空 
        {
            p1->next=q1;
            p1=p1->next;//p指向原来的q1 
        }
    } while (c!='\n');//出现换行，第一个多项式输入完成 
    do
    {
      scanf("%d%d%c",&x,&y,&c);
      for(p1=head1;p1!=NULL;p1=p1->next)//从多项式第一项开始 
      {
          a=x*p1->coef;//系数相乘 
          b=y+p1->exp;//指数相加 
          q2=(slink*)malloc(sizeof(slink));//开拓新空间 
          q2->coef=a;q2->exp=b;q2->next=NULL;//将得到的数据放在新链表中 
          if(head2==NULL)
          {
              head2=p2=q2;//首位为空的情况 
          }
          else
          {
              for(p2=head2;p2!=NULL;p=p2,p2=p2->next)
              {
                  if(q2->exp>p2->exp)//新的数指数更大 
                  {
                    if(p2==head2)//p2在第一位		 
                      {
                          q2->next=head2;//首位地址传给q 
                          head2=q2;//q的地址传给头指针 
                          break;
                      }
                      else//p2不在第一位 
                      {
                        q2->next=p2;//p的地址传给q 
                        p->next=q2;//q的地址传到原来的p上 
                        break;
                      }
                  }
                  else if(q2->exp==p2->exp)//乘完后指数不变 
                  {
                      p2->coef+=q2->coef;//原来的基础上加相应q的数值 
                      break;
                  }
              }
               if(p2==NULL)//结束 
                p->next=q2;//将q插到最后 
          }
      }
    } while (c!='\n');
}

