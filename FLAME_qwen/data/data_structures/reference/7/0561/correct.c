#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
int n,x;
typedef struct {
	int val;
	int ls;
	int rs;
}node;
int tot;
node t[10010];
void ins(int key,int pos){
	if(key<t[pos].val){
		if(!t[pos].ls)
			{
				t[pos].ls=++tot;
				t[tot].val=key;
				return ;
			}
		ins(key,t[pos].ls);
	}
	else{
		if(!t[pos].rs)
			{
				t[pos].rs=++tot;
				t[tot].val=key;
				return ;
			}
		ins(key,t[pos].rs);
	}
}
void dfs(int pos,int depth){
	if(!t[pos].ls&&!t[pos].rs)
		{printf("%d %d\n",t[pos].val,depth);return ;}
	if(t[pos].ls)dfs(t[pos].ls,depth+1);
	if(t[pos].rs)dfs(t[pos].rs,depth+1);
}
int main(){
	scanf("%d",&n);
	REP(i,1,n){
		scanf("%d",&x);
		if(!tot){t[++tot].val=x;continue;}
		ins(x,1);
	}
	dfs(1,1);
}

