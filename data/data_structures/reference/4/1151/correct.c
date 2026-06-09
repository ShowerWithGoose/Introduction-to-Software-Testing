#include<stdio.h>
#include<string.h>
int child[100005][26],tot;
int cnt[100005];
char ch[100005],ch1[1000005],llen;
char now[100005];
int judge(int k){return (k>='A'&&k<='Z')||(k>='a'&&k<='z');}
void add()
{
	int tmp=0,d=1;
	while(d<=llen)
	{
		if(!child[tmp][ch1[d-1]-'a'])
			child[tmp][ch1[d-1]-'a']=++tot;
		tmp=child[tmp][ch1[d-1]-'a'];
		d++;
	}
	cnt[tmp]++;
}
void dfs(int k,int d)
{
	if(cnt[k]&&d)
	{
		for(int q=1;q<=d;q++)
			printf("%c",now[q]);
		printf(" %d\n",cnt[k]);
	}
	for(int q=0;q<26;q++)
		if(child[k][q])
			now[d+1]=q+'a',dfs(child[k][q],d+1);
}
signed main()
{
	FILE *in;
	in=fopen("article.txt","r");
	while(fgets(ch,1000005,in)!=NULL)
	{
		int len=strlen(ch),tmp=0;
		while(tmp<len)
		{
			while(tmp<len&&!judge(ch[tmp]))	tmp++;
			llen=0;
			while(tmp<len&&judge(ch[tmp]))	ch1[llen++]=(ch[tmp]>='A'&&ch[tmp]<='Z')?ch[tmp]-'A'+'a':ch[tmp],tmp++;
			add();
		}
	}
	dfs(0,0);
}
