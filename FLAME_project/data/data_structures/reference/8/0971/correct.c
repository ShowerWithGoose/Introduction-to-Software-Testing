#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int a;
	struct node* nex;
};

typedef struct node ljb;
typedef struct node* ljbp;

ljbp b[102]; 

void add_chain(int a,int b);
void DSF(int i);
void BSF(int i);
void DEL(int i);

int n_num,e_num,hash[102];

int main(){
	ljbp s,t;
	int e_id1,e_id2,i,del;
	scanf("%d %d",&e_num,&n_num);
	for(i=0;i<n_num;i++){
		scanf("%d %d",&e_id1,&e_id2);
		add_chain(e_id1,e_id2);
	}
	scanf("%d",&del);
	DSF(0);
	printf("\n");
	memset(hash,0, 4*e_num);
	BSF(0);
	printf("\n");
	DEL(del);
	/*for(i=0;i<e_num;i++){
			if(i==del){
				continue;
			}
			for(s=b[i];s!=NULL;s=s->nex){
				printf("%d ",s->a);
			}
			printf("\n");
		}*/ 
	DSF(0);
	printf("\n");
	memset(hash,0, 4*e_num);
	e_num--;
	BSF(0);
	return 0;
}

void add_chain(int d,int c){
	ljbp p,q,v,head;
	p=(ljbp)malloc(sizeof(ljb));
	if(b[c]==NULL){
		p->a=c;
		p->nex=NULL;
		b[c]=p;
	}
	else{
		free(p);
	}
	q=(ljbp)malloc(sizeof(ljb));
	q->a=d;
	q->nex=NULL;
	if(b[c]->nex==NULL){
		b[c]->nex=q;
	}
	else{
		head=b[c]->nex;
		if(head->a>q->a){
			q->nex=head;
			head=q;
			b[c]->nex=head;			
		}
		else{
			for(v=head;v!=NULL;v=v->nex){
				if(v->nex==NULL||((v->a<q->a)&&(v->nex->a>q->a))){
					break;
				}
			}
			if(v->nex!=NULL){
				q->nex=v->nex;
				v->nex=q;
			}
			else{
				v->nex=q;
			}
		}	
	}
	p=(ljbp)malloc(sizeof(ljb));
		if(b[d]==NULL){
			p->a=d;
			p->nex=NULL;
			b[d]=p;
		}
		else{
			free(p);
		}
		q=(ljbp)malloc(sizeof(ljb));
		q->a=c;
		q->nex=NULL;
		if(b[d]->nex==NULL){
			b[d]->nex=q;
		}
		else{
			head=b[d]->nex;
			if(head->a>q->a){
				q->nex=head;
				head=q;
				b[d]->nex=head;			
			}
			else{
				for(v=head;v!=NULL;v=v->nex){
					if(v->nex==NULL||((v->a<q->a)&&(v->nex->a>q->a))){
						break;
					}
				}
				if(v->nex!=NULL){
					q->nex=v->nex;
					v->nex=q;
				}
				else{
					v->nex=q;
				}
			}	
		}
	return ;
}

void DSF(int i){
	ljbp p;
	printf("%d ",b[i]->a);
	hash[b[i]->a]++;
	for(p=b[i]->nex;p!=NULL;p=p->nex){
		if(hash[p->a]==0){
			DSF(p->a); 
		}
	}
	return ;
}

void BSF(int i){
	int z[102]={0},top,low,j;top=low=0;
	ljbp p;
	z[top++]=b[i]->a;
	hash[b[i]->a]++;
	while(top>low){
		for(p=b[z[low]]->nex;p!=NULL;p=p->nex){
			if(hash[p->a]==0){
				z[top++]=p->a;
				hash[p->a]++;
			}
		}
		if(top==e_num){
			break;
		}
		low++;
	}
	for(j=0;j<e_num;j++){
		printf("%d ",z[j]);
	}
	memset(hash,0,4*e_num);
	return ;
}

void DEL(int i){
	ljbp p,q;
	int j;
	p=b[i];
	while(p->nex!=NULL){
		q=p->nex;
		free(p);
		p=q;
	} 
	free(p);
	for(j=0;j<e_num;j++){
		if(j==i){
			continue;
		}
		for(p=b[j];p->nex!=NULL;p=p->nex){
			q=p->nex;
			if(q->a==i){
				p->nex=q->nex;
				free(q);
				break;
			}
		}
	}
	return ;
}


