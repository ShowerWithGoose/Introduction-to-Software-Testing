#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 1000000
struct treenode {
	int value,depth;
	int left,right;
} tree[MAXSIZE];
int size,n,a[MAXSIZE];
void insert(int val,int root) {
	if(val>=tree[root].value) {
		if(tree[root].right==0) {
			tree[root].right=++size;
			tree[size].value=val;
			tree[size].depth=tree[root].depth+1;
		} else insert(val,tree[root].right);
	} else {
		if(tree[root].left==0) {
			tree[root].left=++size;
			tree[size].value=val;
			tree[size].depth=tree[root].depth+1;
		} else insert(val,tree[root].left);
	}
}
void put(int root)
{
	if(tree[root].left!=0||tree[root].right!=0){
		if(tree[root].left!=0)
		put(tree[root].left);
		if(tree[root].right!=0)
		put(tree[root].right);
	}
	else {
		
		printf("%d %d\n",tree[root].value,tree[root].depth);
	}
}
int main() {
	int i,j;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	tree[++size].value=a[1];
	tree[size].depth=1;
	for(i=2; i<=n; i++)
		insert(a[i],1);
//	for(i=1;i<=size;i++)
//	printf("%d %d %d %d %d\n",i,tree[i].value,tree[i].left,tree[i].right,tree[i].depth);
	put(1);
	return 0;
}


