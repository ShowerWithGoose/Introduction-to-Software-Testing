#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

char w[500010][110];
char ch[5010];
int vis[500010];
int n,m,q;
struct wordlist{
	char s[110];
	int cnt;
}p[500010];
int is_s(char e) {
	if(('a'<=e && e<='z') || ('A'<=e && e<='Z')) return 1;
	return 0;
}
int cmp(const void * a,const void *b) {
	struct wordlist * c=(struct wordlist *)a;
	struct wordlist * d=(struct wordlist *)b;
	return strcmp(c->s,d->s);
}
int main() {
	FILE * IN;
	IN=fopen("article.txt","r");
	int i,j;
	while(fgets(ch,1010,IN)) {
		for(i=0;i<strlen(ch);i++) {
			if(is_s(ch[i])) {
				++m;
//				printf("%c\n",ch[i]);
				for(j=i;j<strlen(ch);j++) {
					if(!is_s(ch[j])) break;
					if('a'<=ch[j] && ch[j]<='z') w[m][j-i]=ch[j];
					else w[m][j-i]=ch[j]-'A'+'a';
				}
				i=j-1;
			}
		}
	}
//	printf("%")
	for(i=1;i<=m;i++) {
		if(vis[i]) continue;
		q++;
		for(j=0;j<strlen(w[i]);j++) p[q].s[j]=w[i][j];
		p[q].cnt=1;
		vis[i]=1;
		for(j=i+1;j<=m;j++) {
			if(strcmp(w[i],w[j])==0) p[q].cnt++,vis[j]=1;
		}
	}
	qsort(p+1,q,sizeof(p[1]),cmp);
	for(i=1;i<=q;i++) {
		printf("%s %d\n",p[i].s,p[i].cnt);
	}
	return 0;
}

