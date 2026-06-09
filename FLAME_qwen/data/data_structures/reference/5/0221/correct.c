#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int a;
	int e;
	
} LNode; 
int cmp(const void *a,const void *b);
int main(){
	LNode A[100],B[100],C[1000],D[500];
	char c;
	int i=0,j=0,k=0,l=0,ax,ex,h=0,g=0;
	while(~scanf("%d%d%c",&A[i].a,&A[i].e,&c)){
		if(c==' '){
			i++;
		}
		else if(c=='\n'){
			break;
		}
		
	}
	while(~scanf("%d%d%c",&B[j].a,&B[j].e,&c)){
		if(c==' '){
			j++;
		}
		else if(c=='\n'){
			break;
		}	
	}
	for(k=0;k<=i;k++){
		for(l=0;l<=j;l++){
			C[h].a=A[k].a*B[l].a;
			C[h].e=A[k].e+B[l].e;
			h++;
		}
	}
	qsort(C,h,sizeof(C[0]),cmp);
	for(i=0;i<h-1;i++){
		if(C[i].e==C[i+1].e){
			C[i+1].a+=C[i].a;
			
		}
		else {
			D[g].a=C[i].a;
			D[g].e=C[i].e;
			g++;
			
		}
	
	}
			D[g].a=C[i].a;
			D[g].e=C[i].e;
			g++;	
	for(i=0;i<g;i++){
		printf("%d %d ",D[i].a,D[i].e);
	}
	return 0;
}
int cmp(const void *a,const void *b){
	LNode *w=(LNode *)a;
	LNode *q=(LNode *)b;
		return q->e-w->e;
}






