#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef long long ll;

ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
struct node{
	char s[50];
	int cnt;
}e[1010];
char st[110];
int cmp (const void *a,const void *b){
	return strcmp((*(struct node*)a).s+1,(*(struct node*)b).s+1);
}
int main(){
	FILE *in;
	in=fopen("article.txt","r");
	char tmp;
	int p=0,tot=0;;
	while (fscanf (in,"%c",&tmp)!=EOF){
		if (tmp >='A'&&tmp<='Z'){
			tmp=tmp-'A'+'a';
		}
		if (tmp>='a'&&tmp<='z'){
			st[++p]=tmp;
		}else{
			if (p==0) continue;
			st[++p]=0;
			int flag=0;
			for (int i=1;i<=tot;i++){
				if (strcmp(st+1,e[i].s+1)==0){
					flag=1;
					e[i].cnt++;
					break;
				}
			}
			if (!flag){
				e[++tot].cnt=1;
				strcpy(e[tot].s+1,st+1);
			}
			p=0;
			
		}
	}
	qsort(e+1,tot,sizeof(e[1]),cmp);
	for (int i=1;i<=tot;i++){
		printf("%s %d\n",e[i].s+1,e[i].cnt);
	}
	return 0;
}

