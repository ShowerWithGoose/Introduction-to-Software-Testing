#include<stdio.h>
#include<stdlib.h>
typedef struct LNode{
	int a;
	int e;
	
} LNode; 
int cmp(const void *a,const void *b);
int main(){
	LNode A[100],C[100],Wordlist[1000],D[500];
	char c;
	int l=0,r=0,i=0,j=0,ax,ex,h=0,g=0;
	while(~scanf("%d%d%c",&A[l].a,&A[l].e,&c)){
		if(c==' '){
			l++;
		}
		else if(c=='\n'){
			break;
		}
		
	}
	while(~scanf("%d%d%c",&C[r].a,&C[r].e,&c)){
		if(c==' '){
			r++;
		}
		else if(c=='\n'){
			break;
		}	
	}
	for(i=0;i<=l;i++){
		for(j=0;j<=r;j++){
			Wordlist[h].a=A[i].a*C[j].a;
			Wordlist[h].e=A[i].e+C[j].e;
			h++;
		}
	}
	qsort(Wordlist,h,sizeof(Wordlist[0]),cmp);
	for(l=0;l<h-1;l++){
		if(Wordlist[l].e==Wordlist[l+1].e){
			Wordlist[l+1].a+=Wordlist[l].a;
			
		}
		else {
			D[g].a=Wordlist[l].a;
			D[g].e=Wordlist[l].e;
			g++;
			
		}
	
	}
			D[g].a=Wordlist[l].a;
			D[g].e=Wordlist[l].e;
			g++;	
	for(l=0;l<g;l++){
		printf("%d %d ",D[l].a,D[l].e);
	}
	return 0;
}
int cmp(const void *a,const void *b){
	LNode *w=(LNode *)a;
	LNode *q=(LNode *)b;
		return q->e-w->e;
}






