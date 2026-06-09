#include<stdio.h>
#include<stdlib.h>
struct node{
	int v[4];
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr list[100],p,q;//list是尾指针，Node是循环链表
int sum,listn=0,listi,listj,sumi,scani,s,num[100],listk,tmp,t=1;
int Check(Nodeptr p)
{
	for(listi=0;listi<listn;listi++){
		q=list[listi]->link;//首元素
		if(p->v[0]==list[listi]->v[2]&&p->v[1]==list[listi]->v[3]){
			s=0;
			return listi;
		}
		else if(p->v[2]==q->v[0]&&p->v[3]==q->v[1]){
			s=1;
			return listi;
		}
	}
	if(listi==listn){
		s=-1;
		return -1;
	}
}
int Same(Nodeptr a,Nodeptr b)
{
	//末尾线段的尾部能连接另一个线段的头部
	if(a->v[2]==b->v[0]&&a->v[3]==b->v[1]) return 1;
	else return 0;
}
void Combine()
{
	t=0;
	for(listi=0;listi<listn;listi++){
		for(listj=0;listj<listn;listj++){
			if(listj==listi) continue;
			else{
				tmp=Same(list[listi],list[listj]->link);
				if(tmp==1){
					t=1;
					q=list[listi]->link;
					list[listi]->link=list[listj]->link;
					list[listj]->link=q;
					num[listi]+=num[listj];
					list[listi]=list[listj];
					for(listk=listj;listk<listn-1;listk++){
						list[listk]=list[listk+1];
						num[listk]=num[listk+1];
					}
					listn--;
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&sum);
	for(sumi=0;sumi<sum;sumi++){
		p=(Nodeptr)malloc(sizeof(Node));
		p->link=NULL;
		for(scani=0;scani<4;scani++)
			scanf("%d",&(p->v[scani]));
		Check(p);
		if(s==-1){
			list[listn++]=p;
			num[listn-1]=1;
			list[listn-1]->link=p;
		}
		if(s==0){
			p->link=q;
			list[listi]->link=p;
			list[listi]=p;
			num[listi]++;
		}
		if(s==1){
			p->link=q;
			list[listi]->link=p;
			num[listi]++;
		}
	}
	while(t==1){
		Combine();
	}
	int maxnum=0,maxi;
	for(listi=0;listi<listn;listi++){
		if(maxnum<num[listi]){
			maxnum=num[listi];
			maxi=listi;
		}
	}
	q=list[maxi]->link;
	printf("%d %d %d",maxnum,q->v[0],q->v[1]);
	return 0;
}
