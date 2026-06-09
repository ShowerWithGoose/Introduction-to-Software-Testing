#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long
int p[105][105];
int v[105];
struct t{
	int n;
	struct t *next;
}q[105],*c,*cc,*Q[105];
void dfs(int x)
{
	struct t *C;
	v[x]=1;
	printf("%d ",x);
	for(C=q[x].next;C!=NULL;C=C->next){
		if(v[C->n]!=1){
			dfs(C->n);
		}
	}
}
void deep(int n)
{
	int i;
	for(i=0;i<n;i++){
		if(v[i]!=1){
			dfs(i);
		}
	}
}
void broad(int n)
{
	struct t *C;	
	int a=0,b=0;
	Q[0]=&q[0];
	while(a<=b){
		for(C=&q[Q[a]->n];C->next!=NULL;C=C->next){
			if(v[C->next->n]!=1){
				v[C->next->n]=1;
				b++;
				Q[b]=C->next;
			}
		}
		v[0]=1;
		printf("%d ",Q[a]->n);
		a++;
	}		
} 
int main(){
	int i,j,k;
	int n,e,d;
	scanf("%d%d",&n,&e);
	for(i=0;i<e;i++){
		scanf("%d%d",&j,&k);
		p[j][k]=p[k][j]=1;
	}
	scanf("%d",&d);
	for(i=0;i<n;i++){
		q[i].n=i;
		cc=&q[i];
		for(j=0;j<n;j++){
			if(p[i][j]==1){
				c=(struct t*)malloc(sizeof(struct t));
				c->n=j;
				c->next=NULL;
				cc->next=c;
				cc=cc->next; 
			}
		}
	}
	for(i=0;i<n;i++){
		v[i]=0;
	}	
	deep(n);
	printf("\n");
	for(i=0;i<n;i++){
		v[i]=0;
	}	
	broad(n); 
	printf("\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==d||j==d){
				p[i][j]=0;
			}
		}
	}
	for(i=0;i<n;i++){
		q[i].next=NULL;
	}
	for(i=0;i<n;i++){
		q[i].n=i;
		cc=&q[i];
		for(j=0;j<n;j++){
			if(p[i][j]==1){
				c=(struct t*)malloc(sizeof(struct t));
				c->n=j;
				c->next=NULL;
				cc->next=c;
				cc=cc->next; 
			}
		}
	}
	for(i=0;i<n;i++){
		v[i]=0;
	}	
	v[d]=1;
	deep(n);
	printf("\n");
	for(i=0;i<n;i++){
		v[i]=0;
	}	
	v[d]=1;
	broad(n); 		
}

