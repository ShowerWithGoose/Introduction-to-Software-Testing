#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//qsort顺序为数组名，元素数量，元素大小，cmp 
/*int addnode(LinkList list,int i,Elemtype a){
	LinkList p,q=list;
	int j=1;
	while(j<i&&q!=NULL){
		q=q->next;
		j++;
	}
	if(j!=i&&q==NULL){
		return -1;//插入失败 
	}
	p=(LinkList)malloc(sizeof(LNode));
	p->data=a;
	p->next=q->next;
	q->next=p; 
	return 1;//插入成功 
}

int delnode(LinkList list,int i){
	LinkList p,q=list;
	int j=1;
	while(j<i&&q!=NULL){
		q=q->next;
		j++;
	}
	if(j!=i&&q==NULL){
		return -1;//失败
	}
	p=q->next;
	q->next=q->next->next;
	free(p);
	return 1;//成功
}*/

int main(){
	typedef struct node{
		int xi;//要存的数据
		int zhi;
		struct node *next;//链接下一个节点
	}LNode,*LinkList; 
	int i,inixi,inizhi,num=0,op=0,finxi,finzhi,m=1,n=1;
	char c;
	LinkList p,q,r=NULL,firstx,firsty,firstfin=NULL,pfin=NULL,pcha=NULL;
	for(i=0;;i++){
		scanf("%d %d%c",&inixi,&inizhi,&c);
		p=(LinkList)malloc(sizeof(LNode));//申请新节点
		p->xi=inixi;//赋值该节点
		p->zhi=inizhi;
		if(i==0)
		firstx=p;
		else
		r->next=p;
		r=p;
		if(c=='\n')
		break;
	}
	r->next=NULL;
	for(i=0;;i++){
		scanf("%d %d%c",&inixi,&inizhi,&c);
		p=(LinkList)malloc(sizeof(LNode));//申请新节点
		p->xi=inixi;//赋值该节点
		p->zhi=inizhi;
		if(inizhi==0)
		inizhi=-1;
		if(i==0)
		firsty=p;
		else
		r->next=p;
		r=p;
		if(c=='\n')
		break;
	}
	r->next=NULL;
	p=firstx;
	while(n==1){
		if(p->next==NULL)
		n=0;
		q=firsty;
		m=1;
		while(m==1){
			finxi=(p->xi)*(q->xi);
			finzhi=(p->zhi)+(q->zhi);
			pfin=(LinkList)malloc(sizeof(LNode));
			pfin->xi=finxi;
			pfin->zhi=finzhi;
			if(q->next==NULL)
			m=0;
			q=q->next;
			if(firstfin==NULL){
				firstfin=pfin;
				r=pfin;
				num++;
			}
			else{
				pcha=firstfin;
				op=0;
				while(pcha->next!=NULL){
					if(pcha->next->zhi==pfin->zhi&&pcha->next->zhi!=0){
						pcha->next->xi+=pfin->xi;
						free(pfin);
						op=1;//与之前相等 
						break;
					}
					else if(pcha->next->zhi<pfin->zhi||pcha->next->zhi<=0){
						pfin->next=pcha->next;
						pcha->next=pfin;
						op=2;//找到插入点
						num++;
						break;
					}
					pcha=pcha->next;
				}
				if(op==1)
				continue;
				else if(op==0){
					//插到末尾 
					num++;
					r->next=pfin;
					r=pfin;
					r->next=NULL;
				}
			}
			
		}
		p=p->next;
	}
	pfin=firstfin;
	for(i=1;i<=num;i++){
		if(pfin->zhi==-1)
		pfin->zhi=0;
		printf("%d %d ",pfin->xi,pfin->zhi);
		pfin=pfin->next;
	}
	
    return 0;
} 

