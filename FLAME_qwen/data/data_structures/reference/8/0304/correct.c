#include <stdio.h>
#include <malloc.h>
typedef struct node{
	int a;
	struct node *next;
}node,*list;
list s[100];
void insert(list s,int q){
	list n=(list)malloc(sizeof(node));
	n->a=q;
	n->next=NULL;
	if(s->next==NULL){
		s->next=n;
	}
	else{
		list t=s;
		while(t->next!=NULL&&t->next->a<n->a){
			t=t->next;
		}
		n->next=t->next;
		t->next=n;
	}
}
void ds(list k,int *f,int p){
	if(f[p]==0){
		f[p]=1;
		printf("%d ",p);
	}
	else{
		return;
	}
	list t=k;
	while(t->next!=NULL){
		ds(s[t->next->a],f,t->next->a);
		t=t->next;
	}
	return;
}
void ws(int *f,int *h,int cnt,int j,int n){
	list t=s[h[j]];
	while(t!=NULL){
		if(f[t->a]==1){
			f[t->a]=0;
			printf("%d ",t->a);
			h[cnt]=t->a;
			cnt++;
		}
		t=t->next;
	}
	if(cnt<n){
		ws(f,h,cnt,j+1,n);
	}	
	return;
}
void WS(int *f,int n){
	int h[100],cnt=0,j=0;
	h[0]=0;
	ws(f,h,cnt,j,n);
}
void del(int d){
	list t=s[d]->next;
	while(t!=NULL){
		list k=s[t->a];
		while(k->next->a!=d&&k->next!=NULL){
			k=k->next;
		}
		if(k->next!=NULL){
			k->next=k->next->next;
		}
		t=t->next;
	}
	s[d]->next=NULL;
}
int main(){
	int n,m,d,f[100];
	scanf("%d %d",&n,&m);	
	int i,p,q;
	for(i=0;i<n;i++){
		f[i]=0;
		s[i]=(list)malloc(sizeof(node));
		s[i]->a=i;
		s[i]->next=NULL;
	}
	for(i=0;i<m;i++){
		scanf("%d %d",&p,&q);
		insert(s[p],q);
		insert(s[q],p);
	}
	scanf("%d",&d);
	ds(s[0],f,0);
	printf("\n");
	WS(f,n);
	printf("\n");
	del(d);
	ds(s[0],f,0);
	printf("\n");
	WS(f,n-1);
	return 0;
}

