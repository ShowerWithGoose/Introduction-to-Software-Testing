#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int exp1[1000][2],exp2[1000][2],exp[1000][2];
int ans[1000][2];
int cmp(const void *p1,const void *p2){
	return -(((int *)p1)[1]-((int *)p2)[1]);
}
int main(){
	int cnt1=0,cnt2=0;
	while(1){
		scanf("%d",&exp1[cnt1][0]);
		scanf("%d",&exp1[cnt1++][1]);
		char c=getchar();
		if(c=='\n') break;
	}
	while(1){
		scanf("%d",&exp2[cnt2][0]);
		scanf("%d",&exp2[cnt2++][1]);
		char c=getchar();
		if(c=='\n') break;
	}
	int cnt=0;
	for(int i=0;i<cnt1;i++){
		for(int j=0;j<cnt2;j++){
			exp[cnt][0]=exp1[i][0]*exp2[j][0];
			exp[cnt++][1]=exp1[i][1]+exp2[j][1];
		}
	}
	qsort(exp,cnt,sizeof(exp[0]),cmp);
	cnt1=0;
	for(int i=0;i<cnt;i++){
		if(exp[i][1]==ans[cnt1][1]) ans[cnt1][0]+=exp[i][0];
		else ans[++cnt1][0]=exp[i][0],ans[cnt1][1]=exp[i][1];
	}
	for(int i=1;i<=cnt1;i++) printf("%d %d ",ans[i][0],ans[i][1]);
} 

