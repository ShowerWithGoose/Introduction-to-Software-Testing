#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define maxn 100005
int n,num[maxn],i,cnt;
int tree[maxn][2],val[maxn];
void insert(int p,int v){
	if(val[p]==1e9){
		val[p]=v;
		tree[p][0]=++cnt;
		tree[p][1]=++cnt;
		val[tree[p][0]]=1e9;
		val[tree[p][1]]=1e9;
		return;
	}
	if(v<val[p])insert(tree[p][0],v);
	else insert(tree[p][1],v);
}
void query(int p,int h){
	if(val[tree[p][0]]==1e9&&val[tree[p][1]]==1e9){
		printf("%d %d\n",val[p],h);
		return;
	}
	if(val[tree[p][0]]!=1e9)query(tree[p][0],h+1);
	if(val[tree[p][1]]!=1e9)query(tree[p][1],h+1);
}
int main(){
	scanf("%d",&n);
	val[0]=1e9;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		insert(0,num[i]);
	}
	query(0,1);
	return 0;
}
