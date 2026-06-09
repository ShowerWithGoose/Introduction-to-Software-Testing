#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 20000
int now,tran[N][26],End[N],cnt,sz[N],root;
void init(){
	freopen("article.txt","r",stdin); now=root=++cnt; char c;
	while ((c=getchar())!=EOF){
		if (c>='a'&&c<='z'||c>='A'&&c<='Z'){
			int C=tolower(c)-'a'; 
			if (!tran[now][C]) tran[now][C]=++cnt;
			now=tran[now][C]; sz[now]++;
		}else{
			if (now!=root) End[now]++;
			now=root;
		}
	}
}
char s[N];
void dfs(int u,int L){
	if (End[u]) {
		for (int i=1;i<=L-1;i++) putchar(s[i]); putchar(' ');
		printf("%d\n",End[u]);
	}
	for (int i=0;i<26;i++){
		if (tran[u][i]){
			s[L]=i+'a';
			dfs(tran[u][i],L+1);
		}
	} 
}
void solve(){
	dfs(1,1);
} 
int main(){
	init(); solve();
	return 0;
} 

