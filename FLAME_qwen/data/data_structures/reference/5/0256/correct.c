#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct haha{
	int xi;
	int zhi;
	struct haha *next;
};
int main()
{
	typedef struct haha *add;
	typedef struct haha box;
	int a,b;
	char c;
	struct haha *head=NULL,*p,*q=NULL;//第一次的链表 
	struct haha *head1=NULL,*p1,*q1=NULL,*p0;//用来存最后结果！ 
	do{
	q=(add)malloc(sizeof(box));//q申请空间，也是地址！ 
	scanf("%d%d%c",&a,&b,&c);
	q->xi=a;
	q->zhi=b;
	q->next=NULL;
	if(head==NULL)
	{
	head=q;//head不动，p随着动，只要找到head就能找到链表！！！！ 
	p=q;
	}
	else{
		p->next=q;
		p=p->next;//一个个的往下走，地址逐渐变后面 
	}	
	}while(c!='\n');
	int a1,b1;
	do{
		scanf("%d%d%c",&a,&b,&c);
		for(p=head;p!=NULL;p=p->next){//逐个相乘！！
		q1=(add)malloc(sizeof(box));//申请存储结果的空间 
			a1=a*(p->xi);
			b1=b+(p->zhi); 
			q1->xi=a1;
			q1->zhi=b1;
			q1->next=NULL;
			if(head1==NULL){
				p1=q1;
				head1=q1;
			}
		    else{
		            for(p1=head1; p1!=NULL; p0=p1,p1=p1->next) {//终有一次，p1=p1->next会变成NULL；所以最后要插入q!!!! 
		            if(q1->zhi == p1->zhi)  {
						        p1->xi=q1->xi+p1->xi; 
							    break;
											 }//指数相等，系数相加
		                if(q1->zhi > p1->zhi) {
		                    if(p1==head){
		                    	head=q1;
								q1->next=head1;
								break;
								}//插入到头节点前;//尾巴处理好，头处理好即可！！！！！直接break; 
		                    else{
								p0->next=q1;
							    q1->next=p1;
							    break;
							} //将q插入到p前！！！！！p0是用来记录p1的地址的！！！！！！！！ 
		                }
		            }
		             if(p1== NULL)  {
					 	p0->next = q1;   //将q插入到尾节点后    
		            }
					}
		}
	}while(c!='\n');
	for(p1=head1;p1!=NULL;p1=p1->next){
		printf("%d %d ",p1->xi,p1->zhi);
	}
    return 0;
}



