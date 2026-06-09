#include<stdio.h>
#include<stdlib.h>

typedef struct NODE1{
	int xishu1;
	int zhishu1;
	struct NODE1 *link1;
}node1;

typedef struct NODE2{
	int xishu2;
	int zhishu2;
	struct NODE2 *link2;
}node2;

typedef struct NODE3{
	int xishu3;
	int zhishu3;
	struct NODE3 *link3;
}node3;


int main(){
	int a,b,bb=2147483647;
	int n1=0,n2=0,n3=0,i,j,flag=0,hold=0,k=0;
	node1 *head1;
	node2 *head2;
	node3 *head3;
	
	node1 *p,*r,*list=NULL;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(bb<=b)
			break;
		bb=b;
		
		p=(node1*)malloc(sizeof(node1));
		p->xishu1=a;
		p->zhishu1=b;
		p->link1=NULL;
		
		if(list==NULL)
			list=p;
		else
			r->link1=p;
		r=p;
		
		n1++;
	}//循环读入第一个多项式 
	head1=list;//记录第一个多项式头指针 
	
	node2 *pp,*rr,*listt=NULL;
	do{
		pp=(node2*)malloc(sizeof(node2));
		pp->xishu2=a;
		pp->zhishu2=b;
		pp->link2=NULL;
		
		if(listt==NULL)
			listt=pp;
		else
			rr->link2=pp;
		rr=pp;
		
		n2++;
	}while(scanf("%d%d",&a,&b)!=EOF);//循环读入第一个多项式 
	head2=listt;//记录第二个多项式头指针 
	
	node3 *ppp,*rrr,*listtt=NULL;
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			ppp=(node3*)malloc(sizeof(node3));
			ppp->xishu3 =list->xishu1 * listt->xishu2;
			ppp->zhishu3 =list->zhishu1 + listt->zhishu2;
			ppp->link3=NULL;
			
			if(listtt==NULL)
				listtt=ppp;
			else
				rrr->link3=ppp;
			rrr=ppp;
			
			listt=listt->link2;
			n3++;
		}
		listt=head2;
		list=list->link1;
	}//用一个链表记录两式相乘的多项式 
	list=head1;
	listt=head2;//还原头指针 
	head3=listtt;//记录第三个多项式的头指针 
	
	
	
	for(i=0;i<n3-1;i++){
		flag=0;
		for(j=0;j<n3-i-1;j++){
			if(listtt->zhishu3  <  listtt->link3->zhishu3){
				hold=listtt->zhishu3;
				listtt->zhishu3=listtt->link3->zhishu3;
				listtt->link3->zhishu3 =hold;
				hold=listtt->xishu3;
				listtt->xishu3=listtt->link3->xishu3;
				listtt->link3->xishu3 =hold;
				
				listtt=listtt->link3;
				
				flag=1;
			}
			else
				listtt=listtt->link3;
		}
		
		listtt=head3;
		
		if(flag==0)
			break;
	}//对第三个多项式排序 
	listtt=head3; 
	ppp=listtt->link3;
	rrr=listtt;//还原第三个多项式的头指针，以及p和r 
	
	for(i=0;i<n3-1;i++){
		if(rrr->zhishu3==rrr->link3->zhishu3){
			rrr->xishu3 += rrr->link3->xishu3;
			rrr->link3=ppp->link3;
			free(ppp);
			ppp=rrr->link3;
			k++;
		}
		else{
			rrr=ppp;
			ppp=ppp->link3;
		}
	}//合并第三个多项式的同类项 
	listtt=head3;
	ppp=listtt->link3;
	rrr=listtt;//还原第三个多项式的头指针，以及p和r 
	
	for(i=0;i<n3-k;i++){
		printf("%d %d ",listtt->xishu3,listtt->zhishu3);
		if(listtt->link3==NULL)
			break;
		else
			listtt=listtt->link3;
	}
	
	return 0;
}



