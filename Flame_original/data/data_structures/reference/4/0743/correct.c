#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define MaxTo(a,b) (a)=(a)>(b)?(a):(b)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define ull unsigned long long
#define FO2(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define swap(type,a,b) {type t=a;a=b;b=t;}
#define node struct _node
int Alpha(int x){//大小写字母
	if(x>='A'&&x<='Z') return 1;
	if(x>='a'&&x<='z') return 2;
	return 0;
}
node{
	int Letter;
	int Count;
	node *Child[26];
};
node *Trie,*p;
char ReadyPut[120],RD0=0;
void Output(node *r){
	ReadyPut[RD0++]=r->Letter+97;
	if(r->Count>0) printf("%s %d\n",ReadyPut,r->Count);
	FOR(i,0,26) if(r->Child[i]!=NULL)Output(r->Child[i]); 
	ReadyPut[--RD0]=0;
}
int main()
{
	FILE *File=fopen("article.txt","r");
	int x;
	Trie=malloc(sizeof(node));
	Trie->Count=-2147483647;FOR(i,0,26) Trie->Child[i]=NULL;
	p=Trie;
	while((x=fgetc(File))!=EOF){//录入过程
		if(!Alpha(x)){
			p->Count++;
			p=Trie;
			continue;
		}//结束Trie树
		x=(x-65)%32;
		if(p->Child[x]==NULL){
			node *q=malloc(sizeof(node));
			q->Letter=x;
			q->Count=0;
			FOR(i,0,26) q->Child[i]=NULL;
			p->Child[x]=q;
		}
		p=p->Child[x];
	}
	FOR(i,0,26) if(Trie->Child[i]!=NULL)Output(Trie->Child[i]); 
	return 0;
}


