#include<string.h>
#include<stdio.h>
#define maxn 100005
int tire[maxn*10][30],i,p,cnt,sum[maxn];
FILE *in;
char s[maxn],word[10005];
void dfs(int now,int deep){
	int k;
	if(sum[now]>0){
		for(k=0;k<deep;k++)printf("%c",word[k]);
		printf(" %d\n",sum[now]);
	}
	for(k=0;k<26;k++){
		if(tire[now][k]==-1)continue;
		word[deep]=k+'a';
		dfs(tire[now][k],deep+1);
	}
}
int main(){
	in=fopen("article.txt","r");
	cnt=1;
	memset(tire[0],-1,sizeof(tire[0]));
	while(fgets(s,100000,in)!=NULL){
		int l=strlen(s);
		for(i=0;i<l;i++){
			if(s[i]<='Z'&&s[i]>='A')s[i]=s[i]-'A'+'a';
			if(!(s[i]<='z'&&s[i]>='a')){
				if(p>0)sum[p]++;
				p=0;
			}else{
				if(tire[p][s[i]-'a']==-1){
					memset(tire[cnt],-1,sizeof(tire[cnt]));
					tire[p][s[i]-'a']=cnt;
					p=cnt++;
				}else{
					p=tire[p][s[i]-'a'];
				}
			
			}
		}
		p=0;
	}
	dfs(0,0);
	return 0;
}
