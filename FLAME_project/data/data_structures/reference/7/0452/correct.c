#include<stdio.h>
#include<ctype.h>
#define maxn 100
typedef struct tree {
	int son[2]; 
	int val; 
} Tree;
Tree tr[maxn];
int root;
int cnt;

void ins(int* rt, int val) {
	if (!(*rt)) {
		*rt = ++cnt; 
		tr[*rt].val = val;
		return;
	}
	ins(&tr[*rt].son[tr[*rt].val <= val], val);
}

void f(int rt,int dep) { 
	if (!rt) {
		return;
	} 
	if (!tr[rt].son[0] && !tr[rt].son[1]) { 
		printf("%d %d\n", tr[rt].val, dep);
	}	 
	f(tr[rt].son[0], dep + 1);  
	f(tr[rt].son[1], dep + 1);
}

int main() {
	int n;
	scanf("%d",&n);
	int i;
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d",&x);
		ins(&root, x);
	}	
	f(root, 1);
	return 0;
} 



