#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int xi;
	int zhi;
	struct node * pNext;
} * pNode;

pNode a[110],b[110];
pNode pHead;
int s1[100],s2[100];


void Link(pNode a[],pNode b[],int i,int j)
{
	pNode pNew=(pNode)malloc(sizeof(struct node));
	pNew->pNext =NULL;
	pNew->xi =a[i]->xi *b[j]->xi ;
	pNew->zhi=a[i]->zhi +b[j]->zhi ;
	pNode p=pHead->pNext ;
	pNode pb=pHead;
	if(p!=NULL&&p->zhi <pNew->zhi ){
		pNew->pNext =p;
		pHead->pNext =pNew;
	}
	if(p!=NULL&&p->zhi ==pNew->zhi ){
		p->xi +=pNew->xi ;
	}
	while(p!=NULL){
		if(p->zhi <pNew->zhi ){
			pb->pNext =pNew;
			pNew->pNext =p;
			break;
		}
		else if (p->zhi ==pNew->zhi ){
			p->xi +=pNew->xi ;
			break;
		}
		p=p->pNext ;
		pb=pb->pNext ;
	}
	if(p==NULL){
		pb->pNext =pNew;
		pNew->pNext =NULL;
	}
	/*if(p!=NULL){
		while(p!=NULL){
			p=p->pNext ;
			pb=pb->pNext ;
		}
	}*/		
}

void qingling ()
{
	pNode p,pb;
	pb=pHead;
	p=pHead->pNext ;
	while(p!=NULL){
		if(p->xi ==0){
			pb->pNext =p->pNext ;
		}
		p=p->pNext ;
		pb=pb->pNext ;
	}
}

int main()
{
	int i,j,k;
	int l,r;
	pHead=(pNode)malloc(sizeof(struct node));
	pHead->xi =-1;pHead->zhi =-1;
	pHead->pNext =NULL;
	i=0;
	char ch='1';
	int x1[1000],x2[1000];
	while(ch!='\n'){
		a[i]=(pNode)malloc(sizeof (struct node));
		a[i]->pNext =NULL;
		scanf("%d %d",&a[i]->xi  ,&a[i]->zhi );
		i++;
		scanf("%c",&ch);
		if(ch=='\n') break;
	}l=i;ch='1';i=0;
	
	while(ch!='\n'){
		b[i]=(pNode)malloc(sizeof (struct node));
		b[i]->pNext =NULL;
		scanf("%d %d",&b[i]->xi  ,&b[i]->zhi );
		i++;
		scanf("%c",&ch);
		if(ch=='\n') break;
	}r=i;
	for(i=0;i<l;i++){
		for(j=0;j<r;j++){
			Link(a,b,i,j);
		}
	}
	qingling();
	pNode p=pHead->pNext ;
	while(p!=NULL){
		printf("%d %d ",p->xi ,p->zhi );
		p=p->pNext ;
	}
	return 0;
}

