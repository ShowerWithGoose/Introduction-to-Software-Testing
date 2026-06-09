#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void produce(int spot0,int spott);
typedef struct mode{
	int spot;
	struct mode *next;
}conlink; 
typedef struct tyr{
	struct mode *link;
}first;
void deepbianli(int);
void widebianli();
first tou[105];
int flag[105]={0};
int cancel;
int main(){
    int i,sumsp,sumline,spot1,spot2,op;
    conlink *p,*q,*r;
    scanf("%d %d",&sumsp,&sumline);
    for(i=1;i<=sumline;i++){
    	scanf("%d%d",&spot1,&spot2);
    	produce(spot1,spot2);
    	produce(spot2,spot1);
	}
	for(i=0;i<=sumsp-1;i++){
		op=1;
		while(op!=0){
			op=0;
			for(p=tou[i].link;p!=NULL;q=p,p=p->next){
				if(p->next==NULL){
					break;
				}
				if(p==tou[i].link){
					if(p->next->spot>p->spot){
						continue;
					}
					else{
						tou[i].link=p->next;
						p->next=p->next->next;
						tou[i].link->next=p;
						p=tou[i].link;
						op=1;
					}
				}
				else{
					if(p->next->spot>p->spot){
						
					}
					else{
						q->next=p->next;
						p->next=p->next->next;
						q->next->next=p;
						p=q->next;
						op=1;	
					}
				}
			}
		}
	}
	scanf("%d",&cancel);
	deepbianli(0);
	memset(flag,0,420);
	printf("\n");
	widebianli();
	memset(flag,0,420);
	printf("\n");
	for(p=tou[cancel].link;p!=NULL;p=p->next){
		for(q=tou[p->spot].link;q!=NULL;r=q,q=q->next){
			if(q->spot==cancel){ 
				if(q==tou[p->spot].link){
					tou[p->spot].link=q->next;
				}
				else{
					r->next=q->next;
				}
			}	
		}
	}
	deepbianli(0);
	printf("\n");
	memset(flag,0,420);
	widebianli();
	return 0;
} 
void produce(int spot0,int spott){
	conlink *p,*q;
	p=(conlink*)malloc(sizeof(conlink));
	p->next=NULL;
	p->spot=spott;
	if(tou[spot0].link!=NULL){
		q=tou[spot0].link;
		while(q->next!=NULL){
			q=q->next;
		}
		q->next=p;
	}
	else{
		tou[spot0].link=p;
	}
}
void deepbianli(int n){
	conlink *p;
	flag[n]=1;
	printf("%d ",n);
	for(p=tou[n].link;p!=NULL;p=p->next){
			if(flag[p->spot]==0){
				deepbianli(p->spot);
			}
			else{
				continue;
			}
	}
}
void widebianli(){
	conlink *p;
	int n,queue[105]={0},front=0,rear=-1;
	queue[0]=0;
	rear=0;
	flag[0]=1;
	while(front<=rear){
		n=queue[front++];
		printf("%d ",n);
		for(p=tou[n].link;p!=NULL;p=p->next){
			if(flag[p->spot]==0){
				flag[p->spot]=1;
				queue[++rear]=p->spot;
			}
			else{
				continue;
			}
		}
		
	}
}

