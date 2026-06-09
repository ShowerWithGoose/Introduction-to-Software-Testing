#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
#include <ctype.h> 
typedef struct tree{
	int num;
	struct tree* lc;
	struct tree* rc;
}num,*pnum;
pnum root=NULL;
int dep=1;
void tra(pnum a){
	
	if(a!=NULL){
		if(a->lc==NULL&&a->rc==NULL){
			printf("%d %d\n",a->num,dep); 
		}
		dep++;
		tra(a->lc);
		tra(a->rc);
		dep--;
	}
	
}
pnum insert(int m,pnum r){
	if(r==NULL){
		r=(pnum)malloc(sizeof(num)); 
		r->lc=NULL;
		r->rc=NULL;
		r->num=m; 
	}else{
		if(m>=r->num){
		r->rc=insert(m,r->rc);
		}else{
		r->lc=insert(m,r->lc);
		}
	}
	return r;
}
int main(){
	int n,i,temp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&temp);
		root=insert(temp,root);
	} 
	tra(root);
	return 0;
} 

