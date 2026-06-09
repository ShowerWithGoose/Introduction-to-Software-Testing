#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)

typedef struct words{
	int count;
	char s[40];
	struct words*link;
}W;
char small(char ch){
	if(ch>='A'&&ch<='Z')return ch-'A'+'a';
	else return ch;
}
int isword(char ch){
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))return 1;
	else return 0;
}
int main(){
	W*p,*q,*r=malloc(sizeof(W));
	r->link=NULL;
	char buf[1000],word[40];
	int i=0,j=0;
	FILE*in;
	in=fopen("article.txt","r");
	while(fgets(buf,1024,in)!=NULL){
		for(i=0,j=0;buf[i];i++){
			if(isword(buf[i]))word[j++]=small(buf[i]);
			else if(word[0]){
				j=0;
				p=malloc(sizeof(W));
				p->count=1;
				FOR(k,0,40)p->s[k]=0;
				strcpy(p->s,word);
				FOR(k,0,40)word[k]=0;
				for(q=r;q->link!=NULL&&strcmp(p->s,q->link->s)>0;q=q->link);
				if(q->link==NULL)q->link=p,p->link=NULL;
				else if(strcmp(p->s,q->link->s)<0)p->link=q->link,q->link=p;
				else q->link->count++,free(p);
			}
		}
	}
	for(q=r->link;q!=NULL;q=q->link){
		free(r);
		printf("%s %d\n\n",q->s,q->count);
		r=q;
	}
	fclose(in);
	return 0;
}



