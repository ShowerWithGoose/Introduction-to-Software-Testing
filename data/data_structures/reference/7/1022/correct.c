#include<stdio.h>
#include<ctype.h>
#define maxn 1000005

inline int read() { //快速读入，可以放在自己的缺省源里面 
	int x = 0; //数字位 
	int f = 1; //符号位 
	char ch = getchar(); //读入第一个字符 
	while (!isdigit(ch)) { //不是数字 
		if (ch == '-') { //特判负号 
			f = -1;
		}
		ch = getchar();
	}
	while (isdigit(ch)) { //读入连续数字 
		x = (x << 3) + (x << 1) + ch - '0'; // x * 10 == (x << 3) + (x << 1) 
		ch = getchar();
	}
	return x * f;
}

typedef struct tree {
	int son[2]; //存储儿子，0代表左儿子，1代表右儿子。 
	int val;//存储权值 
} Tree;
Tree tr[maxn];
int root;
int cnt;

void ins(int* rt, int val) {
	if (!(*rt)) {//不存在结点，可以新建一个存下当前值
		*rt = ++cnt; //分配一个新的编号为 cnt + 1 的结点 
		tr[*rt].val = val;
		return;
	}
	ins(&tr[*rt].son[tr[*rt].val <= val], val);
	//当前结点存在，按照排序二叉树的约束继续尝试插入 
	//显然 t[*rt].val <= val 时，应该在右子树 ，正好编号为 1 
}

void dfs(int rt,int dep) {//遍历子树输出 
	if (!rt) {
		return;
	} 
	if (!tr[rt].son[0] && !tr[rt].son[1]) {//为叶子结点。 
		printf("%d %d\n", tr[rt].val, dep);
	}
	// 继续遍历子树，记得增加深度。 
	dfs(tr[rt].son[0], dep + 1);  
	dfs(tr[rt].son[1], dep + 1);
}

int main() {
	int n = read();
	int i;
	for (i = 0; i < n; ++i) {
		int x = read();
		ins(&root, x);
	}	
	dfs(root, 1);
	return 0;
} 

