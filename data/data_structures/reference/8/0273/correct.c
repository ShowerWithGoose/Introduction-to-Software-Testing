#include<stdio.h>
int n,m;
int a[205][205],flag[205];
int dfs(int p){
	printf("%d ",p);
	flag[p]=0;
	int i;
	for(i=0;i<n;i++) if(a[p][i]==1 && flag[i]==1) dfs(i);
	return 0;
}
int main(){
	int i,j,qd,zd,del,r=1,f=0; 
	int b[105];
	for(i=0;i<204;i++)
		for(j=0;j<204;j++) a[i][j]=0;
	for(i=0;i<105;i++) flag[i]=0;
	scanf("%d %d\n",&n,&m);
	for(i=0;i<n;i++) flag[i]=1;
	for(i=0;i<m;i++) {
		scanf("%d %d\n",&qd,&zd);
		a[qd][zd]=a[zd][qd]=1;
	}
	scanf("%d",&del);
	dfs(0);
	printf("\n");
	for(i=0;i<n;i++) flag[i]=1;
	b[0]=0;flag[0]=0;
	printf("0 ");
	while(f<r){
		for(i=1;i<n;i++) if(a[b[f]][i]==1 && flag[i]==1) {
			b[r]=i;
			r++;
			flag[i]=0;
			printf("%d ",i);	
		}
		f++;
	}
	printf("\n");
	for(i=0;i<n;i++) a[del][i]=a[i][del]=0;
	for(i=0;i<n;i++) flag[i]=1;
	dfs(0);
	printf("\n");
	for(i=0;i<n;i++) flag[i]=1;
	r=1;f=0;
	b[0]=0;flag[0]=0;
	printf("0 ");
	while(f<=r){
		for(i=1;i<n;i++) if(a[b[f]][i]==1 && flag[i]==1) {
			b[r]=i;
			r++;
			flag[i]=0;
			printf("%d ",i);	
		}
		f++;
	}
	return 0;
} 

