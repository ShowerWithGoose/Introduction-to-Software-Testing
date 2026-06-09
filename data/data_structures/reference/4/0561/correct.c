#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
typedef struct{
	char str[5001];
}node;
typedef struct{
	char str[5001];
	int tot;
}cont;
node ky[100010];
cont ans[100010];
char s[100010];
int top,n;
void push(int st,int ed){
	top++;
	REP(i,st,ed)
		ky[top].str[i-st]=s[i];
}
int cmp(const void *na,const void *nb){
	node a=*(node *)na,b=*(node *)nb;
	return strcmp(a.str,b.str);
}
int main(){
	freopen("article.txt","r",stdin);
	while(gets(s)){
		int l=strlen(s);
		REP(i,0,l-1)
			if(s[i]>='A'&&s[i]<='Z')
				s[i]+='a'-'A';
		int st=-1;
		REP(i,0,l-1){
			if(s[i]>='a'&&s[i]<='z'&&(st==-1))
				st=i;
			if((s[i]<'a'||s[i]>'z')&&(st!=-1))
				push(st,i-1),st=-1;
		}
		if(st==0)push(0,l-1);
		int flag=1;
		if(st!=0)
			REP(i,st,l-1)
				if(s[i]<'a'||s[i]>'z')
					{flag=0;break;}
		if(flag&&st!=0)push(st,l-1);
	}
	qsort(ky+1,top,sizeof(ky[1]),cmp);
	REP(i,1,top)
		if(strcmp(ky[i].str,ans[n].str)!=0)
			strcpy(ans[++n].str,ky[i].str),ans[n].tot=1;
		else
			ans[n].tot++;
	REP(i,1,n)
		printf("%s %d\n",ans[i].str,ans[i].tot);
}



