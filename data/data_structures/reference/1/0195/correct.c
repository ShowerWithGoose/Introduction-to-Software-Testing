#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define ULL unsigned long long 
#define LL long long
#define fep(i,l,r) for(int i=(l);i<=r;i++)
#define ffep(i,r,l) for(int i=(r);i>=l;i--)
int rd(){
	char ch;int f=0,w=1;
	ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){f=(f<<3)+(f<<1)+ch-'0';ch=getchar();}
	return f*w;
}
bool p[11];
int n,a[11];
void dfs(int dep){
	if(dep==n){
		fep(i,1,n-1)printf("%d ",a[i]);
		printf("%d\n",a[n]);
		return;
	}
	fep(i,1,n)if(!p[i]){
		a[dep+1]=i;
		p[i]=1;
		dfs(dep+1);
		p[i]=0;
	}
}
int main(){
	n=rd();
	dfs(0);
} 

