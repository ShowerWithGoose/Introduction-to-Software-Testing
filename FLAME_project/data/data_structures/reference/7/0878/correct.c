#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int tr[100000];
void insert(int x){
	if(tr[1]==0x3f3f3f3f) tr[1]=x;
	else{
		int u=1;
		while(tr[u]!=0x3f3f3f3f){
			if(x<tr[u]) u=2*u;
			else u=2*u+1;
		}
		tr[u]=x;
	}
	return;
}
void pretrav(int idx){
	if(tr[idx*2]==0x3f3f3f3f&&tr[idx*2+1]==0x3f3f3f3f){
		int dph=(int)((log(idx)/log(2))+1);
		printf("%d %d\n",tr[idx],dph);
	}
	else{
		if(tr[idx*2]!=0x3f3f3f3f) pretrav(idx*2);
		if(tr[idx*2+1]!=0x3f3f3f3f) pretrav(idx*2+1);
	}
	return;
}
int main(){
	memset(tr,0x3f,sizeof(tr));
	int n,tmp;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&tmp);
		insert(tmp);
	}
	pretrav(1);
	return 0;
} 



