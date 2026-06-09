#include<stdio.h>
#include<string.h>
int list[11];
int visit[11];
void perm(int n,int step){
	if(step == n+1){
		int i; 
		for(i = 1;i<=n;i++){
			 printf("%d ",list[i]);
		}
		printf("\n");
	}
	else{int i;
	for(i = 1;i<=n;i++){
		if(!visit[i])
		{
			visit[i] = 1;
			list[step] = i;
			perm(n,step+1);
			visit[i] = 0;
		}
	}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	perm(n,1);
	return 0;
}

