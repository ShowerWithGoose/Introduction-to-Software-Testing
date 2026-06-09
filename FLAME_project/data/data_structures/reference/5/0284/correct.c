#include<stdio.h>
#include<malloc.h>
typedef struct x{
	long long int xs,zs;
	struct x *next;
}X;
X* handle(long long int l[],int il,long long int s[],int is){
	int i=1,j=1;
	long long int tempxs,tempzs;
	X *tou=(X*)malloc(sizeof(X));
	tou->next=NULL;
	X *now,*tempX;
	for(i=1;i<=is;i++){
		now=tou;
		for(j=1;j<=il;j++){
			tempxs=s[2*i-1]*l[2*j-1];
			tempzs=s[2*i]+l[2*j];
			if(tou->next==NULL){
				tou->next=(X*)malloc(sizeof(X));
				tou->next->next=NULL;
				tou->next->xs=tempxs;
				tou->next->zs=tempzs;
			}else{
				while(now->next!=NULL&&now->next->zs>=tempzs){//找到一个比tempzs小的或者找到末尾了
					now=now->next;
				}
				if(now->zs==tempzs)now->xs+=tempxs;//找到和tempxs相等的
				else{
					if(now->next==NULL){//找到末尾且未找到
						tempX=(X*)malloc(sizeof(X));
						tempX->next=NULL;
						tempX->xs=tempxs;
						tempX->zs=tempzs;
						now->next=tempX;
					}else{//未找到，且不在末尾
						tempX=(X*)malloc(sizeof(X));
						tempX->next=now->next;
						tempX->xs=tempxs;
						tempX->zs=tempzs;
						now->next=tempX;
					}
				}
				
			}
		}
	}
	return tou->next;
}
int main(){
	long long int A[100],B[100];
	int a=0,b=0,iA,iB;
	char delta=' ';
	X *list;
	for(iA=1;delta!='\n';iA++){
		scanf("%d%d%c",&A[2*iA-1],&A[2*iA],&delta);
	}
	delta=' ';
	for(iB=1;delta!='\n';iB++){
		scanf("%d%d%c",&B[2*iB-1],&B[2*iB],&delta);
	}
	iA--;iB--;
	if(iA>iB)list=handle(A,iA,B,iB);
	else list=handle(B,iB,A,iA);
	while(list!=NULL){
		printf("%d %d ",list->xs,list->zs);
		list=list->next;
	}
}


