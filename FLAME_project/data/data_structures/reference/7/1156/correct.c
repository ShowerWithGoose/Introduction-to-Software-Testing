#include<stdio.h>
#include<string.h>
#define Lc (p<<1)
#define Rc (p<<1|1)
#define INF (0x3f3f3f3f)
int A[10000000];
void Get(int p,int x){
	if (A[p]==INF){
		return;
	}
	if (A[Lc]==INF && A[Rc]==INF){
		printf("%d %d\n",A[p],x);
		return;
	}
	Get(Lc,x+1);
	Get(Rc,x+1);
}
void Insert(int p,int x){
	if (A[p]==INF){
		A[p]=x;
		return;
	}
	if (x<A[p]){
		Insert(Lc,x);
	}else{
		Insert(Rc,x);
	}
}
int main(){
	memset(A,63,sizeof(A));
	int n;
	scanf("%d",&n);
	while (n--){
		int x;
		scanf("%d",&x);
		Insert(1,x);
	}
	Get(1,1);
	return 0;
}

