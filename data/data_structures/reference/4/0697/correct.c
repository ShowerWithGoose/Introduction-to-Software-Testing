#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct TRIE
{
	int num;
	struct TRIE *ch[33];
}Trie;
Trie* newnode(){Trie* re=(Trie*)malloc(sizeof(Trie));re->num=0;for(int i=0;i<=32;i++)re->ch[i]=NULL;return re;}
FILE *IN;
char s[100000],ans[100000];

void insert(Trie* now,char* s,int len,int p)
{
	// printf("#in %c\n",s[p]);
	if(p-1==len){now->num++;return;}
	int son=s[p]-'a'+1;
	if(now->ch[son]!=NULL){insert(now->ch[son],s,len,p+1);return;}
	now->ch[son]=newnode();insert(now->ch[son],s,len,p+1);
}
void find(Trie* now,char *ans,int dep)
{
	// printf("#dep: %d : ",dep);for(int i=1;i<dep;i++)printf("%c",ans[i]);puts("");
	if(now->num>=1){for(int i=1;i<dep;i++)printf("%c",ans[i]);printf(" %d\n",now->num);}
	for(int i=1;i<=26;i++)
	if(now->ch[i]!=NULL)
	{
		ans[dep]=i+'a'-1;
		find(now->ch[i],ans,dep+1);
	}
}
signed main()
{
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);

	Trie* tr=newnode();
	IN=fopen("article.txt","r");
	while(fgets(s+1,100000,IN))
	{
		// puts(s+1);
		int p=0,l=strlen(s+1);
		for(int i=1;i<=l;i++)if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
		for(int i=1;i<=l;i++)
		{
			if(s[i]>='a'&&s[i]<='z'&&p==0)p=i;
			if((s[i]<'a'||s[i]>'z')&&p!=0){insert(tr,s+p-1,i-p,1);p=0;}
		}
	}
	find(tr,ans,1);
}
