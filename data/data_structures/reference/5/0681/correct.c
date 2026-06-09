#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct  Node { //一个多项式节点结构
    int coe; //系数
    int pow; //幂
    struct Node *next;
}; 
int main()
{
	int a1,n1,a2,n2;
	char c1,c2;
	int flag;
	flag=1;
	struct Node *head1,*p,*head2,*q,*p0,*p1,*r;
	head1 = p = NULL;
	head2 = r = NULL;
	q=NULL;
	do {  //创建一个链表存放第一个多项式
        scanf("%d%d%c", &a1, &n1, &c1);
        if( head1 == NULL) 
             head1 = p = (struct Node *)malloc(sizeof(struct Node));
       else {
            p->next = (struct Node *)malloc(sizeof(struct Node));
            //p1=p;
            p = p->next;
       }
       p->coe = a1; p->pow = n1; p->next = NULL;
   	}while(c1!='\n');
	do { //将第二个多项式的每个项插入到第一个多项式链表中
        scanf("%d%d%c", &a2, &n2, &c2);//生成第二个多项式的一个结点
        if(flag==1)
        {
        	for(p=head1;p!=NULL;p0=p,p=p->next)
   	{
   		if(head2==NULL)
   		head2=r= (struct Node *)malloc(sizeof(struct Node));
   		else {
            r->next = (struct Node *)malloc(sizeof(struct Node));
            //p1=p;
            r = r->next; 
       }
       r->coe = a2*(p->coe); r->pow = n2+p->pow; r->next = NULL;
	}
	flag=0;
		}
		else
		{
        //q = (struct Node *)malloc(sizeof(struct Node));
        for(p=head1;p!=NULL;p0=p,p=p->next)
        {
        	q = (struct Node *)malloc(sizeof(struct Node));
        	q->coe = a2*(p->coe); q->pow = n2+p->pow; q->next = NULL;
        for(r=head2; r!=NULL; p1=r,r=r->next) {                    // 顺序查找链表结点
            if(q->pow > r->pow) { 
                 
                  q->next = r; p1->next = q; break;        //将q插入到p前
            }
            else if(r->pow == q->pow)  { r->coe += q->coe; break;}//指数相等，系数相加
         }
         if(r== NULL)  {
		 p1->next = q;   
		}
        //free(q);
		 }     
		 //q=NULL;
		 //free(q);
	}
    } while ( c2 != '\n');
	for(r=head2; r!=NULL; r=r->next)
         printf("%d %d ", r->coe,r->pow);
	
	return 0;
}

