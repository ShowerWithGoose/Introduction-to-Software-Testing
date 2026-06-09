#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node {
    int x;//系数 
    int z;//指数 
    struct node *link;
} ; 


int main()
{
int x,z,x2,z2;
char c;
struct node *list=NULL,*p,*q;//第一个链表存第一个多项式 
do{
	scanf("%d%d%c",&x,&z,&c);
	q=(struct node*)malloc(sizeof(struct node));
	q->x=x;
	q->z=z;
	q->link=NULL;
	if (list==NULL)
	list=p=q;
	else{
	p->link=q;
	p=q;}
}while(c!='\n');

struct node *list2=NULL,*p2=NULL,*q2,*r=NULL,*qq=NULL,*rr;//对第二个多项式，每读取一个指数和系数，就和第一个多项式相乘，并按大小插入 
do{
	scanf("%d%d%c",&x,&z,&c);
	for (r=list;r!=NULL;r=r->link){

		q2=(struct node*)malloc(sizeof(struct node));
		x2=x*(r->x);
		z2=z+(r->z);
		q2->x=x2;
		q2->z=z2;
		q2->link=NULL;
		if (list2==NULL)
		list2=p2=q2;
		else{
			for (p2=list2;p2!=NULL;qq=p2,p2=p2->link){//找到插入位置(p2之前，qq是p2的前序节点) 
			if (q2->z > p2->z){//q2插入到p2前 
			if (p2==list2){//若在头结点前插入 
				q2->link=list2;
				list2=q2;
				break;
			}
			else{
				q2->link=p2;
				qq->link=q2;
				break;
			}
		}
			else if (q2->z==(p2->z)){//若相等则不需插入，只需相加系数即可 
				p2->x+=q2->x;
				break;
			}
			}
            if (p2==NULL)//若在尾结点后插入 
            qq->link=q2;
		}
	}
}while(c!='\n');

for (rr=list2;rr!=NULL;rr=rr->link)
printf("%d %d ",rr->x,rr->z);
return 0; 
}








