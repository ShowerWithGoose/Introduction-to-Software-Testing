#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct wordlist{
	char wrd[32];
	int i;
	struct wordlist *link;
}*wl,wordl;
int getword(FILE* fp0,char *c){
	char s[32]="",x;
	int k=0;
	while((x=fgetc(fp0))!=EOF){
		if(x>='a'&&x<='z') s[k++]=x;
		else if(x>='A'&&x<='Z') s[k++]=x+('a'-'A');
		else if(k!=0) break;
	}
	if(s[0]=='\0') return -1;
	else{
		strcpy(c,s);
		return 1;
	}
}
int main(){
	FILE *fp;
	wl p,q,list=NULL,r;
	char word[32];
	fp=fopen("article.txt","r");
	while(getword(fp,word)!=-1){
		p=(wl)malloc(sizeof(wordl));
		strcpy(p->wrd,word);
		p->i=1;
		p->link=NULL;
		if(list==NULL){
			list=q=p;
		}
		else{
			r=list;
			if(strcmp(p->wrd,r->wrd)<=0){
				if(strcmp(p->wrd,r->wrd)<0){
					p->link=r;
					list=p;
				}
				else r->i++;
			}
			else{
			while(r->link!=NULL){
				if(strcmp(p->wrd,r->link->wrd)<=0){
					if(strcmp(p->wrd,r->link->wrd)<0){
						p->link=r->link;
						r->link=p;
					}
					else r->link->i++;
					break;
				}
				else r=r->link;
			}
			if(r->link==NULL) r->link=p;
		    }
		}
	}
	for(r=list;r!=NULL;r=r->link){
		printf("%s %d\n",r->wrd,r->i);
	}
	fclose(fp);
	return 0;
}

