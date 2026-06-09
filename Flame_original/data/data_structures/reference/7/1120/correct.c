#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int use,val,right,left;
}node;
node tree[10000];
int loc=1;
void insert(int n){
	int p=1;
	while(tree[p].use){
		if(n<tree[p].val){
			if(tree[p].left) p=tree[p].left;
			else{
				tree[p].left=loc;
				tree[loc].use=1;
				tree[loc].val=n;
				loc++;
				return;
			}
		}
		else{
			if(tree[p].right) p=tree[p].right;
			else{
				tree[p].right=loc;
				tree[loc].val=n;
				tree[loc].use=1;
				loc++;
				return;
			}
		} 
	}
	tree[p].use=1;
	tree[p].val=n;
	loc++;
}
int he=1;
void dfs(int p){
	if(tree[p].left==0&&tree[p].right==0) printf("%d %d\n",tree[p].val,he);
	if(tree[p].left) {
		he++;dfs(tree[p].left);he--;
	}
	if(tree[p].right){
		he++;dfs(tree[p].right);he--;
	}
	return;
} 
int main(){
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;++i){
		scanf("%d",&j);
		insert(j);
	}
	dfs(1);
	return 0;
	
}

