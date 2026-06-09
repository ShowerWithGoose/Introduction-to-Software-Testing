#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tree[1200],i,n,x,p,depth=1;
int treeup(int x)
{
	p = 0;
	if(tree[p] == -100) {
		tree[p] = x;
		return 0;
	}
	while(tree[p]!=-100){
		if(x < tree[p]) p = p*2+1;
		else p = p*2+2;
	}
	tree[p] = x;return 0;
}
int treeout(int p)
{
	if(tree[p]!=-100){
		if(tree[2*p+1]==-100&&tree[2*p+2]==-100){
			printf("%d %d\n",tree[p],depth);
			depth--;return 0;
		}
		depth++;
		treeout(2*p+1);
		depth++;
		treeout(2*p+2);
	}
	depth--;
	return 0;
}
int main(){
	for(i = 0; i <= 1199; i++) tree[i] = -100;
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		scanf("%d",&x);
		treeup(x);
	}
	p = 0;
	treeout(p);
}




