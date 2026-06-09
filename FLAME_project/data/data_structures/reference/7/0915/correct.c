#include<stdio.h>
#define MAXN 100010
struct bst {
	int num;
	int depth;
} t[MAXN];
void init() {
	for(int i=1; i<MAXN; i++)
		t[i].num=-1;
}
void dfs(int x) {
	if(t[2*x].num==-1&&t[2*x+1].num==-1) printf("%d %d\n",t[x].num,t[x].depth);
	if(t[2*x].num!=-1)dfs(2*x);
	if(t[2*x+1].num!=-1)dfs(2*x+1);
}
int main() {
	init();
	int n;
	scanf("%d",&n);
	scanf("%d",&t[1].num);
	t[1].depth=1;
	int insert;
	for(int i=2; i<=n; i++) {
		scanf("%d",&insert);
		int j=1;
		int k=1;
		while(t[j].num!=-1) {
			k++;
			if(insert<t[j].num)
				j*=2;
			else
				j*=2,j++;
		}
		t[j].num=insert;
		t[j].depth=k;
	}
	dfs(1);
	return 0;
}


