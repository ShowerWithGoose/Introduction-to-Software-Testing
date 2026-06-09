#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
	char word[100];
	int count;
	struct node *next;
} xr;
char t[100];
xr *Wordlist=NULL;
void replace(char s[]);
int main() {
	FILE *in;
	char s[1000][100];
	int ans=0,i=0,j=0;
	char c;
	xr *p,*q=NULL,*p0;
	in=fopen("article.txt","r");
	while(fscanf(in,"%c",&c)!=EOF) {
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z')) {
            s[i][j++]=c;
		}
		else if(j!=0){
			i++;
			j=0;
		}
	}
	for(int k=0;k<i;k++) {
		ans=0;
		q=NULL;
		replace(s[k]);
		for(p=Wordlist; p!=NULL; q=p,p=p->next) {
			if(strcmp(t, p->word) < 0)
				break;
			if(strcmp(t,p->word)==0) {
				p->count++;
				ans=1;
			}
		}
		if(ans==0) {
			p0 = (struct node * )malloc(sizeof(struct node));
			strcpy(p0->word,t);
			p0->count=1;
			p0->next=NULL;
			if(Wordlist==NULL) Wordlist=p0;
			else if(q==NULL) {
				p0->next=Wordlist;
				Wordlist=p0;
			} else {
				p0->next=q->next;
				q->next=p0;
			}
		}
		memset(t,0,sizeof(t));
	}
	p = (struct node * )malloc(sizeof(struct node));
	for(p=Wordlist; p != NULL; p=p->next)
		printf("%s %d\n", p->word, p->count);
	return 0;
}

void replace(char s[]) {
	int j=0;
	for(int i=0; s[i]!='\0'; i++) {
		if(s[i]>='a'&&s[i]<='z') t[j++]=s[i];
		if(s[i]>='A'&&s[i]<='Z') t[j++]=s[i]-'A'+'a';
	}
}
