#include <stdio.h>
#include <stdlib.h>
struct Dxs{ //一个多项式结点结构
	int xs; //系数
	int cf; //幂
	struct Dxs *next;
};
int main(){
	int a,n;
	char c;
	struct Dxs *headsave,*p,*q,*t0,*t,*headre,*tmp,*pr;
	headsave=p=NULL;
	//创建一个链表读入第一个多项式
	while(c!='\n'){
		scanf("%d%d%c",&a,&n,&c);
		q=(struct Dxs*)malloc(sizeof(struct Dxs));
		q->xs=a;
		q->cf=n;
		q->next=NULL;
		if(headsave==NULL){
			headsave=p=q;
		}
		else{
			p->next=q;
			p=p->next;
		}
	}
	t=headsave;
//	while(t!=NULL){
//		printf("%d %d ",t->xs,t->cf);
//		t=t->next;
//	}
//	printf("done\n");


		p=headsave;
//		printf("here\n");
		headre=NULL;
		headre = (struct Dxs *)malloc(sizeof(struct Dxs));
		headre->xs=0;
		headre->cf=1;
		headre->next=NULL;
do{
	

		scanf("%d%d%c", &a, &n, &c);
		q = (struct Dxs *)malloc(sizeof(struct Dxs));
		q->cf = a;
		q->xs = n;
		q->next = NULL;
		//读入第二个多项式中的一项

    for(p=headsave;p!=NULL;p=p->next){
				tmp=(struct Dxs *)malloc(sizeof(struct Dxs));
				tmp->xs=a*(p->xs);
				tmp->cf=n+(p->cf);
				tmp->next==NULL;
//				printf("tmp=%d %d\n",tmp->xs,tmp->cf);
				//然后把tmp插入新的结果多项式里
		if(headre!=NULL){
			for(t=headre;t!=NULL;t0=t,t=t->next){
				if(tmp->cf>t->cf){
					if(t==headre){
						tmp->next=headre;
						headre=tmp;
						break;
					}
					else{
						tmp->next=t;
						t0->next=tmp;
						break;
					}
				} else if(tmp->cf==t->cf){
					t->xs+=tmp->xs;
					break;
				}
			}
			if(t==NULL){
				t0->next=tmp;
			}
		}
		if(headre==NULL){
			headre=tmp;//此时结果链表里有一个结点，有终止标志
		}
    }
}while(c!='\n');
	t=headre;
	while(t!=NULL){
		if(t->xs!=0)
		//printf("result=%d %d ",t->xs,t->cf);
		printf("%d %d ",t->xs,t->cf);
		t=t->next;
	}
	return 0;
}

