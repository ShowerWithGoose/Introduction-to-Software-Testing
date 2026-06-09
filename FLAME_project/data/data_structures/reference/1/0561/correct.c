#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
int n;
int a[20],vis[20];
void print(){
	REP(i,1,n)printf("%d ",a[i]);
	puts("");
}
void dfs(int pos){
	if(pos==n+1){print();return ;}
	REP(i,1,n){
		if(!vis[i])
			{vis[i]=1;
			a[pos]=i;
			dfs(pos+1);
			vis[i]=0;
			a[pos]=0;
			}
	}
}
int main(){
	scanf("%d",&n);
	dfs(1);
}

