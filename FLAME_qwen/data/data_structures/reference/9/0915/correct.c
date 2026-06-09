#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a<=b)?a:b)
#define max(a,b) ((a>=b)?a:b)
int fa[110];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void join(int a,int b){
	fa[find(b)]=find(a);
}
int main(){
	int x[110],y[110],z[110],w[110];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&x[i],&y[i],&z[i],&w[i]);
		fa[i]=i;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[i]==z[j]&&y[i]==w[j]){
				join(j,i);
			}
			if(x[j]==z[i]&&y[j]==w[i]){
				join(i,j);
			}
		}
	}
	int max=0;
	int hash[110]={0};
	for(int i=1;i<=n;i++){
		hash[find(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(hash[i]>max){
			ans=i;
			max=hash[i];
		}
	}
	printf("%d %d %d",max,x[ans],y[ans]);
return 0;
}


