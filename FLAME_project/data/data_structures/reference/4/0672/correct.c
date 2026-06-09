#include<stdio.h>
FILE *in,*out;
int trie[100100][26],tot,num[100100];
char c[100100];
void dfs(int u,int deep)
{
	int i;
	if(num[u])
	{
		for(i=0;i<deep;i++)printf("%c",c[i]);
		printf(" %d\n",num[u]);
	}
	for(i=0;i<26;i++)
		if(trie[u][i])
		{
			c[deep]=i+'a';
			dfs(trie[u][i],deep+1);
		} 
}
int main()
{
	in=fopen("article.txt","r");
	char c;
	int u=0;
	while(~fscanf(in,"%c",&c))
//	while(~scanf("%c",&c))
	{
		if(c>='a'&&c<='z')
		{
			if(!trie[u][c-'a'])trie[u][c-'a']=++tot;
			u=trie[u][c-'a'];
		}
		else if(c>='A'&&c<='Z')
		{
			if(!trie[u][c-'A'])trie[u][c-'A']=++tot;
			u=trie[u][c-'A'];
		}
		else
		{
			if(u)num[u]++;
			u=0;
		}
	}
	dfs(0,0);
	
}

