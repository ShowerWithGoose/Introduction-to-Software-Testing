#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct tree
{
	struct tree *next[26];
	int cnt;
}node;
struct wordlist
{
	char word[105];
}w[10000];
int cnt; 
char s[105];
int h[100005]; 

int t[100005][26];
int num[100005];
int pos=1;
unsigned int BKDRHash(char *str)
{
	unsigned int seed=31,key=0;
	while(*str) key=key*seed+(*str++);
	return key&0x7fffffff;
}
node *initialtree()
{
	node *headnode=(node *)malloc(sizeof(node));
	memset(headnode,0,sizeof(node));
	return headnode;
}
void insert(char s[],node *root)
{
	node *p=root;
	for(int i=0;s[i]!='\0';i++)
	{
		if(p->next[s[i]-'a']==NULL)
		    p->next[s[i]-'a']=initialtree();
		p=p->next[s[i]-'a'];
		if(s[i+1]=='\0') p->cnt++; 
	}
}
int find(char s[],node *root)
{
	node *p=root;
	for(int i=0;s[i]!='\0';i++)
	{
		if(p->next[s[i]-'a']==NULL)
		    return 0;
		p=p->next[s[i]-'a'];
	}
	return p->cnt;
}
void visit(node *now,int depth)
{
	node *p=now;
	int flag=0;
	for(int i=0;i<26;i++)
	{
		if(p->next[i]!=NULL)
		{
			s[depth]=i+'a';
			flag=1;
			visit(p->next[i],depth+1);	
		} 
	}
	if(!flag)
	{
		s[depth]='\0';
		printf("%s %d\n",s,now->cnt);
	}	
	
}
void insert_array(char s[])
{
	int p=0;
	for(int i=0;s[i]!='\0';i++)
	{
		int n=s[i]-'a';
		if(t[p][n]==0) t[p][n]=pos++;
		p=t[p][n];
		if(s[i+1]=='\0') num[p]++; 
	}
} 
int find_array(char s[])
{
	int p=0;
	for(int i=0;s[i]!='\0';i++)
	{
		int n=s[i]-'a';
		if(t[p][n]==0) return 0;
		p=t[p][n];
	}
	return num[p];
}
void read(FILE *in,node *root)
{
	char c;
	int l=0;
	while((c=fgetc(in))!=EOF)
	{
		if(isalpha(c))
		{
			l=0;
			do
			{
				s[l++]=tolower(c);
				c=fgetc(in);
			}while(isalpha(c)&&c!=EOF);
			s[l]='\0';
			int key=BKDRHash(s)%100000;
			if(!h[key])
			{
				h[key]=1;
				strcpy(w[++cnt].word,s);
			}
			//insert(s,root);
			insert_array(s);
		}
	}
}
int cmp(const void *_a,const void *_b)
{
	struct wordlist a=*(struct wordlist *)_a;
	struct wordlist b=*(struct wordlist *)_b;
	return strcmp(a.word,b.word);
}
int main()
{
    FILE *in;
    in=fopen("article.txt","r");
    node *root=initialtree();
    read(in,root);
    qsort(w+1,cnt,sizeof(w[0]),cmp);
    for(int i=1;i<=cnt;i++) printf("%s %d\n",w[i].word,find_array(w[i].word));
    //visit(root,0);
	return 0;
}



