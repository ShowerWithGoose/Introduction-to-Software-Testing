#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
struct BTtree{
	int val;
	int child1;
	int child2;
};
struct BTtree tree[4096];
int cnt=0;
int root=0;
void createTree(int *tr,int val){
	if(!(*tr)){
		*tr=++cnt;
		tree[*tr].val=val;
		return ;
	}
	else {
		if(tree[*tr].val<=val)
			createTree(&tree[*tr].child2,val);
		else if(tree[*tr].val>val)
			createTree(&tree[*tr].child1,val);
	}
}
void searchLeaf(int tr,int dep){
	if(!tr)
		return ;
	if(tree[tr].child1==0&&tree[tr].child2==0)
		printf("%d %d\n",tree[tr].val,dep);
	else{
		searchLeaf(tree[tr].child1,dep+1);
		searchLeaf(tree[tr].child2,dep+1);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		createTree(&root,x);
	}
	searchLeaf(root,1);
	return 0;
}



