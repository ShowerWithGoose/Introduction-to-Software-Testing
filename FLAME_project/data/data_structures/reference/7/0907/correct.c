#include<stdio.h>
#include<string.h>
int n;
int t[1000];
void dfs(int l,int f){
	if(t[l*2]==-1 && t[l*2+1]==-1){
		printf("%d %d\n",t[l],f);
		return;
	}
	if(t[l*2]!=-1) dfs(l*2,f+1);
	if(t[l*2+1]!=-1) dfs(l*2+1,f+1);
	return;
}
int main(){
	scanf("%d",&n);
	memset(t,-1,sizeof(t));
	scanf("%d",&t[1]);
	for(int i=2;i<=n;i++){
		int p;
		scanf("%d",&p);
		int loc=1;
		while(1){
			 if(p>=t[loc]) loc=loc*2+1;
			 else loc*=2;
			 if(t[loc]==-1){
			 	t[loc]=p;
			 	break;
			 }  
		}
	}
	dfs(1,1);
	return 0;
}
