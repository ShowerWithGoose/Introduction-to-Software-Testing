#include<stdio.h>
#include<stdlib.h>

struct node{
	int flag;
	int front[2];
	int end[2];
} ;
int line[100][3];
int cmp(const void *a,const void *b);
int main(){
	int q,i,j,k=-1,m[2],n[2],max=0,f;
	struct node A[105];	
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d%d%d%d",&A[i].front[0],&A[i].front[1],&A[i].end[0],&A[i].end[1]);
		A[i].flag=1;
	}
	qsort(A,q,sizeof(A[0]),cmp);
	
	for(i=0;i<q;i++){
		if(A[i].flag==1){
			k++;line[k][0]++;
			m[0]=A[i].end[0];
			m[1]=A[i].end[1];
			line[k][1]=A[i].front[0];
			line[k][2]=A[i].front[1];
				A[i].flag=0;	
			for(j=i+1;j<q;j++){
				if(m[0]==A[j].front[0]&&m[1]==A[j].front[1]&&A[j].flag==1){
					m[0]=A[j].end[0];
					m[1]=A[j].end[1];
					line[k][0]++;
					A[j].flag=0;
				}
			}
		}
	}
	for(i=0;i<=k;i++){
		if(line[i][0]>max){
			max=line[i][0];
			f=i;
		}
		
	}
	printf("%d %d %d",line[f][0],line[f][1],line[f][2]);
	

	return 0;
}
int cmp(const void *a,const void *b){
	struct node *c = (struct node *)a;  
	struct node *d = (struct node *)b;  
	if(c->front[0] != d->front[0]) return c->front[0]  - d->front[0] ;  
	else return d->front[1] - c->front[1]; 
}

